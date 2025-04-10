#pragma once

#include "myResource.h"
#include <Windows.h>
#include <map>

namespace my
{
	class Resources
	{
	public:
		template<typename T>
		static T* Find(const std::wstring& name)
		{
			std::map<std::wstring, Resource*>::iterator it = _resources.find(name);
			if (it == _resources.end())
				return nullptr;

			return dynamic_cast<T*>(it->second);
		}

		template<typename T>
		static T* Load(const std::wstring& name, const std::wstring& path)
		{
			T* resource = Find<T>(name);
			if (resource)
				return resource;
				
			resource = new T(name);
			resource->Load(path);
			
			_resources.insert(std::make_pair(name, resource));
			return resource;
		}

	private:
		static std::map<std::wstring, Resource*> _resources;
	};
}

