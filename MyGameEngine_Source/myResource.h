#pragma once

#include "Common.h"
#include "myEntity.h"
#include <string>
#include <Windows.h>

namespace my
{
	enum class eResourceType : uint8
	{
		Texture,
		AudioClip,
		Prefab,
		Animation,

		Count
	};

	class Resource abstract
		: public Entity
	{
	public:
		Resource(const std::wstring& name, const eResourceType type);
		virtual ~Resource();

		virtual void Load(const std::wstring& path) = 0;

		const eResourceType GetResourceType() const { return _type; }
		
		void SetPath(const std::wstring& path) { _path = path; }
		const std::wstring& GetPath() const { return _path; }

	private:
		eResourceType	_type = eResourceType::Count;
		std::wstring	_path;
	};
}

