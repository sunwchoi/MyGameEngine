#pragma once
#include <string>

#include "map.hpp"
#include "myITree.h"

namespace my
{
	class XmlNode : public TwoWayTree<XmlNode> 
	{
	public:
		std::string _tag;
		std::string _text;
		map<std::string, std::string> _attributes;
	};

	XmlNode* LoadXmlFile(const std::string& filename);
	XmlNode* LoadMymlFile(const std::string& filename);

}
