#pragma once

#include <Windows.h>
#include "myGameObject.h"

namespace my
{

	class Application
	{
	public:
		void Initialize( HWND hwnd, UINT width, UINT height );
		void Run();
		void Update();
		void LateUpdate();
		void Render();

		const HDC getHDC() const { return _hdc; }

	private:
		HWND	_hwnd;				// ������ �ڵ�
		HDC		_hdc;				// DC �ڵ�
		HBITMAP	_backBitmap;		// ������۸� �����
		HDC		_backHdc;			// ������۸� ����� DC �ڵ� 
		UINT	_width;				// â �ʺ�
		UINT	_height;			// â ����
	};

}

