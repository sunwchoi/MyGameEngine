#include "myApplication.h"
#include "myTime.h"

namespace my
{
	void Application::Initialize( HWND hwnd, UINT width, UINT height )
	{
		// ������� �ʱ�ȭ
		_hwnd = hwnd;
		_hdc = GetDC( hwnd );
		_width = width;
		_height = height;
		_backBitmap = CreateCompatibleBitmap( _hdc, _width, _height );
		_backHdc = CreateCompatibleDC( _hdc );
		
		HBITMAP oldBitmap = (HBITMAP)SelectObject( _backHdc, _backBitmap );
		DeleteObject( oldBitmap );

		//������ �۾����� ȭ��ũ�� �缳��
		RECT rect = { 0, 0, width, height };

		AdjustWindowRect( &rect, WS_OVERLAPPED, false );
		SetWindowPos( _hwnd, nullptr, 0, 0, _width, _height, 0 );
		ShowWindow( _hwnd, 0 );

		//
		_player.setPos( 0, 0 );
		Time::Initialize();
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		_player.Update();
		Time::Update();
	}

	void Application::LateUpdate()
	{
	}

	void Application::Render()
	{
		Rectangle( _backHdc, 0, 0, _width, _height );
		_player.Render( _backHdc );

		BitBlt( _hdc, 0, 0, _width, _height, _backHdc, 0, 0, SRCCOPY );
	}
}
