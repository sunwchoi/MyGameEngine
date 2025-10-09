#include "myApplication.h"
#include "myTime.h"
#include "mySceneManager.h"
#include "Input.h"
#include "myDebugDrawer.h"
#include "../MyGameEngine_Window/myLoad.h"
#include "myGraphicDevice_DX11.h"

namespace my
{
	void Application::Initialize( HWND hwnd, UINT width, UINT height )
	{
		LoadResource();
		LoadScene();

		// 멤버변수 초기화
		_hwnd = hwnd;
		_hdc = GetDC( hwnd );
		_width = width;
		_height = height;
		_backBitmap = CreateCompatibleBitmap( _hdc, _width, _height );
		_backHdc = CreateCompatibleDC( _hdc );

		_graphicDevice = new GraphicDevice_DX11();
		_graphicDevice->Initialize();
		
		HBITMAP oldBitmap = (HBITMAP)SelectObject( _backHdc, _backBitmap );
		DeleteObject( oldBitmap );

		// 윈도우 작업영역 화면크기 재설정
		RECT rect = { 0, 0, width, height };

		AdjustWindowRect( &rect, WS_OVERLAPPED, false );
		SetWindowPos( _hwnd, nullptr, 0, 0, _width, _height, 0 );
		ShowWindow( _hwnd, 0 );

		//엔진 initialize
		Input::Initialize();
		Time::Initialize();

		SceneManager::Initialize();
		DebugDrawer::Initialize();
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
		//Rectangle( _backHdc, 0, 0, _width, _height );

		GetGraphicDevice()->PreRender();

		SceneManager::Render( nullptr );
		DebugDrawer::Render();

		GetGraphicDevice()->PostRender();

		//BitBlt( _hdc, 0, 0, _width, _height, _backHdc, 0, 0, SRCCOPY );

	}

	void Application::SetSelectedObject(const GameObject* object)
	{
		_selectedObject = object;
	}

	const GameObject* Application::GetSelectedObject() const
	{
		return _selectedObject;
	}
}
