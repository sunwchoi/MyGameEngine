#include "myXmlUtil.h"

#include <fstream>
#include <iostream>
#include <sstream>

namespace my
{
    size_t skipWhitespace(const std::string& str, size_t pos)
	{
        while (pos < str.size() && isspace(str[pos]))
            ++pos;
        return pos;
    }

    std::string parseAttributeValue(const std::string& str, size_t& pos)
	{
        std::string value;
        if (str[pos] == '"') {
            ++pos;
            while (pos < str.size() && str[pos] != '"') {
                value += str[pos++];
            }
            ++pos; // " 넘어가기
        }
        return value;
    }

    XmlNode* parseNode(XmlNode* parent, const std::string& xml, size_t& pos)
	{
        XmlNode* node = new XmlNode();
        node->SetParent(parent);

        pos = skipWhitespace(xml, pos);
        if (xml[pos] != '<') return nullptr;
        ++pos;

        // 태그 읽기
        while (pos < xml.size() && (isalnum(xml[pos]) || xml[pos] == '_' || xml[pos] == '-')) {
            node->_tag += xml[pos++];
        }

        // 속성 읽기
        while (true) {
            pos = skipWhitespace(xml, pos);

            // <tag>
        	if (xml[pos] == '>')
            {
            	++pos;
            	break;
            }

            // <tag/>
            if (xml[pos] == '/' && xml[pos + 1] == '>')
            {
	            pos += 2;
            	return node;
            }

            // attr="value"
            std::string attrName;
            while (pos < xml.size() && (isalnum(xml[pos]) || xml[pos] == '_' || xml[pos] == '-'))
            {
                attrName += xml[pos++];
            }
            pos = skipWhitespace(xml, pos);
            if (xml[pos] == '=') ++pos;
            pos = skipWhitespace(xml, pos);
            std::string attrValue = parseAttributeValue(xml, pos);
            node->_attributes[attrName] = attrValue;
        }

        // 자식/텍스트 읽기
        while (pos < xml.size()) {
            pos = skipWhitespace(xml, pos);
            if (xml[pos] == '<')
            {
                // 종료 태그
                if (xml[pos + 1] == '/')
                {
                    pos += 2;
                    std::string endTag;
                    while (pos < xml.size() && xml[pos] != '>')
                        endTag += xml[pos++];
                    ++pos;
                    return node;
                }
                // 아니면 자식 읽기
                else
                {
                    node->AddChild(parseNode(node, xml, pos));
                }
            }
            else
            {
                // 텍스트 읽기
                while (pos < xml.size() && xml[pos] != '<') {
                    node->_text += xml[pos++];
                }
            }
        }

        return node;
    }

    XmlNode* LoadXmlFile(const std::string& filename)
	{
        const std::string ext = filename.substr(filename.find_last_of(".") + 1);
        MY_ASSERT(ext == "xml");

        std::ifstream file(filename);
        MY_ASSERT(file);

        std::stringstream buffer;
        buffer << file.rdbuf();
        size_t pos = 0;
        return parseNode(nullptr, buffer.str(), pos);
    }

    void LoadMyssFile(const std::string& filename, __out std::unordered_map<std::string, std::unordered_map<std::string, std::string>>& styleMap)
    {
        std::ifstream file(filename);
        MY_ASSERT(file.is_open());

        std::string line;
        std::string currentClass;
        bool inBlock = false;

        while (std::getline(file, line))
        {
            // 공백 및 탭 제거
            line.erase(0, line.find_first_not_of(" \t\r\n"));
            line.erase(line.find_last_not_of(" \t\r\n") + 1);

            if (line.empty() || line.starts_with("/*")) // 빈 줄 or 주석
                continue;

            // 클래스 시작 (.classname {)
            if (line.starts_with(".") && line.find('{') != std::string::npos)
            {
                size_t nameStart = 1; // '.' 이후부터
                size_t nameEnd = line.find('{');
                currentClass = line.substr(nameStart, nameEnd - nameStart);
                // 공백 제거
                currentClass.erase(currentClass.find_last_not_of(" \t\r\n") + 1);
                inBlock = true;
                continue;
            }

            // 블록 끝 (})
            if (line.find('}') != std::string::npos)
            {
                currentClass.clear();
                inBlock = false;
                continue;
            }

            // 블록 내부
            if (inBlock && !currentClass.empty())
            {
                size_t colonPos = line.find(':');
                size_t semicolonPos = line.find(';');

                if (colonPos == std::string::npos)
                    continue;

                std::string key = line.substr(0, colonPos);
                std::string value = (semicolonPos != std::string::npos)
                    ? line.substr(colonPos + 1, semicolonPos - colonPos - 1)
                    : line.substr(colonPos + 1);

                // trim
                auto trim = [](std::string& s) {
                    s.erase(0, s.find_first_not_of(" \t\r\n"));
                    s.erase(s.find_last_not_of(" \t\r\n") + 1);
                    };
                trim(key);
                trim(value);

                styleMap[currentClass][key] = value;
            }
        }
    }

    void ReplaceClassToStyle(XmlNode* node, const std::unordered_map<std::string, std::unordered_map<std::string, std::string>>& styleMap)
    {
        auto classAttribute = node->_attributes.find("class");
        if (classAttribute == node->_attributes.end())
            return;

        std::string className = classAttribute->second;
        auto styleByClassIter = styleMap.find(className);
        if (styleByClassIter == styleMap.end())
        {
            MY_ASSERT_MSG(false, "class이름 잘못입력");
            return;
        }

        for (auto styleByClass : styleByClassIter->second)
            node->_attributes[styleByClass.first] = styleByClass.second;


        
    }

    XmlNode* LoadMymlFile(const std::string& filename)
    {
        const std::string ext = filename.substr(filename.find_last_of(".") + 1);
        MY_ASSERT(ext == "myml");

        std::ifstream file(filename);
        MY_ASSERT(file);

        std::string myssFilename;
        std::getline(file, myssFilename);

        // 공백 제거 (양쪽)
        myssFilename.erase(0, myssFilename.find_first_not_of(" \t\r\n"));
        myssFilename.erase(myssFilename.find_last_not_of(" \t\r\n") + 1);

        // 스타일시트 경로 파싱
        std::unordered_map<std::string, std::unordered_map<std::string, std::string>> styleMap;
        LoadMyssFile(myssFilename, styleMap);

        // 나머지 XML 내용 전체 읽기
        std::stringstream buffer;
        buffer << file.rdbuf();

        size_t pos = 0;
        XmlNode* node = parseNode(nullptr, buffer.str(), pos);
        node->Traverse([&styleMap](XmlNode* node) { ReplaceClassToStyle(node, styleMap); }, [](XmlNode*){});

        return node;
    }
}
