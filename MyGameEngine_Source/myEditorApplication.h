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
		HWND	_hwnd;				// ������ �ڵ�
		HDC		_hdc;				// DC �ڵ�
		HBITMAP	_backBitmap;		// ������۸� �����
		HDC		_backHdc;			// ������۸� ����� DC �ڵ� 
		UINT	_width;				// â �ʺ�
		UINT	_height;			// â ����

		EditorWidget* widget;
	};
}
