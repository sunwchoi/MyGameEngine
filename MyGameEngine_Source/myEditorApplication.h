#pragma once

#include <Windows.h>

namespace my
{
	class EditorWidget;

	class EditorApplication
	{
	public:
		void Initialize(HWND hwnd, UINT width, UINT height);
		void Run();
		void Update();
		void LateUpdate();

		void Show();

		const float GetWidth() const { return _width; }
		const float GetHeight() const { return _height; }
		const HDC& GetHDC() const { return _hdc; }
		const HWND& GetHWND() const { return _hwnd; }


	private:
		HWND	_hwnd;				// 윈도우 핸들
		HDC		_hdc;				// DC 핸들
		HBITMAP	_backBitmap;		// 더블버퍼링 백버퍼
		HDC		_backHdc;			// 더블버퍼링 백버퍼 DC 핸들 
		UINT	_width;				// 창 너비
		UINT	_height;			// 창 높이

		EditorWidget* widget;
	};
}
