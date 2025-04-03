#pragma once

#include <string>

namespace my
{
	class Entity
	{
	public:
		Entity() {};
		Entity(const std::wstring& name) : _name(name) {};
		~Entity() {};

		const std::wstring& getName() const { return _name; };
	
	private:
		std::wstring _name;
	};
}

