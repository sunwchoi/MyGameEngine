#include "myApplication.h"
#include "myTime.h"
#include "mySceneManager.h"
#include "Input.h"
#include "../MyGameEngine_Window/myLoad.h"

namespace my
{
	void Application::Initialize( HWND hwnd, UINT width, UINT height )
	{
		LoadResource();
		LoadScene();

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
		Input::Initialize();
		Time::Initialize();

		SceneManager::Initialize();
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		Input::Update();
		Time::Update();

		SceneManager::Update();
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
