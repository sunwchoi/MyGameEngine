#include "myApplication.h"
#include "myTime.h"
#include "mySceneManager.h"
#include "../MyGameEngine_Window/myLoadScene.h"

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

		// ������ �۾����� ȭ��ũ�� �缳��
		RECT rect = { 0, 0, width, height };

		AdjustWindowRect( &rect, WS_OVERLAPPED, false );
		SetWindowPos( _hwnd, nullptr, 0, 0, _width, _height, 0 );
		ShowWindow( _hwnd, 0 );

		//���� initialize
		SceneManager::Initialize();
		Time::Initialize();

		LoadScene();
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		SceneManager::Update();
		Time::Update();
	}

	void Application::LateUpdate()
	{
		SceneManager::LateUpdate();
	}

	void Application::Render()
	{
		Rectangle( _backHdc, 0, 0, _width, _height );
		SceneManager::Render( _backHdc );

		BitBlt( _hdc, 0, 0, _width, _height, _backHdc, 0, 0, SRCCOPY );
	}
}
