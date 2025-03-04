#pragma once
#include "Component.h"
#include <string>

#include <mmsystem.h>
#include <dinput.h>
#pragma comment(lib, "Msimg32.lib");
#pragma comment(lib, "winmm.lib");

#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib");

namespace my
{
	class SpriteRenderer : public Component
	{
	public:
		void Initialize() override;
		void Run() override;
		void Update() override;
		void LateUpdate() override;
		void Render( HDC hdc ) override;

		void ImageLoad( const std::wstring& path );

	private:
		Gdiplus::Image* _image;
		UINT			_height;
		UINT			_width;
	};
}

