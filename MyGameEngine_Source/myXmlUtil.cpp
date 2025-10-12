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
}
