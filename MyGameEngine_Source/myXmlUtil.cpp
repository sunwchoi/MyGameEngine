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
            ++pos; // " �Ѿ��
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

        // �±� �б�
        while (pos < xml.size() && (isalnum(xml[pos]) || xml[pos] == '_' || xml[pos] == '-')) {
            node->_tag += xml[pos++];
        }

        // �Ӽ� �б�
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

        // �ڽ�/�ؽ�Ʈ �б�
        while (pos < xml.size()) {
            pos = skipWhitespace(xml, pos);
            if (xml[pos] == '<')
            {
                // ���� �±�
                if (xml[pos + 1] == '/')
                {
                    pos += 2;
                    std::string endTag;
                    while (pos < xml.size() && xml[pos] != '>')
                        endTag += xml[pos++];
                    ++pos;
                    return node;
                }
                // �ƴϸ� �ڽ� �б�
                else
                {
                    node->AddChild(parseNode(node, xml, pos));
                }
            }
            else
            {
                // �ؽ�Ʈ �б�
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
            // ���� �� �� ����
            line.erase(0, line.find_first_not_of(" \t\r\n"));
            line.erase(line.find_last_not_of(" \t\r\n") + 1);

            if (line.empty() || line.starts_with("/*")) // �� �� or �ּ�
                continue;

            // Ŭ���� ���� (.classname {)
            if (line.starts_with(".") && line.find('{') != std::string::npos)
            {
                size_t nameStart = 1; // '.' ���ĺ���
                size_t nameEnd = line.find('{');
                currentClass = line.substr(nameStart, nameEnd - nameStart);
                // ���� ����
                currentClass.erase(currentClass.find_last_not_of(" \t\r\n") + 1);
                inBlock = true;
                continue;
            }

            // ��� �� (})
            if (line.find('}') != std::string::npos)
            {
                currentClass.clear();
                inBlock = false;
                continue;
            }

            // ��� ����
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
            MY_ASSERT_MSG(false, "class�̸� �߸��Է�");
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

        // ���� ���� (����)
        myssFilename.erase(0, myssFilename.find_first_not_of(" \t\r\n"));
        myssFilename.erase(myssFilename.find_last_not_of(" \t\r\n") + 1);

        // ��Ÿ�Ͻ�Ʈ ��� �Ľ�
        std::unordered_map<std::string, std::unordered_map<std::string, std::string>> styleMap;
        LoadMyssFile(myssFilename, styleMap);

        // ������ XML ���� ��ü �б�
        std::stringstream buffer;
        buffer << file.rdbuf();

        size_t pos = 0;
        XmlNode* node = parseNode(nullptr, buffer.str(), pos);
        node->Traverse([&styleMap](XmlNode* node) { ReplaceClassToStyle(node, styleMap); }, [](XmlNode*){});

        return node;
    }
}
