#include "myResource.h"

namespace my
{
	Resource::Resource(const std::wstring& name, const eResourceType type)
		: Entity(name)
		, _type(type)
	{
	}

	Resource::~Resource()
	{
	}
}
