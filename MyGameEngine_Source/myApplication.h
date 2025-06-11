#pragma once

#include <Windows.h>
#include "myGameObject.h"

namespace my
{
	class GraphicDevice_DX11;

	class Application
	{
	public:
		void Initialize( HWND hwnd, UINT width, UINT height );
		void Run();
		void Update();
		void LateUpdate();
		void Render();

		const float GetWidth() const { return _width; }
		const float GetHeight() const { return _height; }
		const HDC&	GetHDC() const { return _hdc; }
		const HWND& GetHWND() const { return _hwnd; }

		const GraphicDevice_DX11* GetGraphicDevice() const { return _graphicDevice; }
		
		void SetSelectedObject(const GameObject* object);
		const GameObject* GetSelectedObject() const;

	private:
		HWND	_hwnd;				// ������ �ڵ�
		HDC		_hdc;				// DC �ڵ�
		HBITMAP	_backBitmap;		// ������۸� �����
		HDC		_backHdc;			// ������۸� ����� DC �ڵ� 
		UINT	_width;				// â �ʺ�
		UINT	_height;			// â ����

		GraphicDevice_DX11* _graphicDevice;

		const GameObject* _selectedObject;
	};

}

