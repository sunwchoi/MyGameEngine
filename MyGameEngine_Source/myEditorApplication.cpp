#include "myEditorApplication.h"
#include "myUIManager.h"
#include "myEditorWidget.h"

namespace my
{
	void EditorApplication::Initialize(HWND hwnd, UINT width, UINT height)
	{
		_hwnd = hwnd;
		_hdc = GetDC(hwnd);
		_width = width;
		_height = height;

		RECT rect = { 0, 0, width, height };

		AdjustWindowRect(&rect, WS_OVERLAPPED, false);
		SetWindowPos(_hwnd, nullptr, 0, 0, _width, _height, 0);
	
		widget = UIManager::CreateWidget<EditorWidget>();
		UIManager::AddToViewport(widget);

		//CreateWindow(L"STATIC", L"pos:",
		//	WS_VISIBLE | WS_CHILD,
		//	20, 20, 30, 20,
		//	hwnd, NULL, NULL, NULL);

		//HWND hEditX, hEditY, hEditZ;

		//// X 입력창
		//hEditX = CreateWindow(L"EDIT", L"123.3",
		//	WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
		//	60, 18, 60, 24,
		//	hwnd, (HMENU)0, NULL, NULL);

		//// Y 입력창
		//hEditY = CreateWindow(L"EDIT", L"",
		//	WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
		//	130, 18, 60, 24,
		//	hwnd, (HMENU)1, NULL, NULL);

		//// Z 입력창
		//hEditZ = CreateWindow(L"EDIT", L"",
		//	WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL | ES_NUMBER,
		//	200, 18, 60, 24,
		//	hwnd, (HMENU)2, NULL, NULL);

		//CreateWindow(
		//	L"BUTTON",            // 클래스 이름
		//	L"Click Me",          // 버튼 텍스트
		//	WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, // 스타일
		//	0, 0, 100, 100,     // 위치 및 크기
		//	hwnd,                // 부모 윈도우 핸들
		//	(HMENU)1,    // 버튼 ID
		//	(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
		//	NULL
		//);

		ShowWindow(_hwnd, 0);
		
	}

	void EditorApplication::Run()
	{
		Update();
		LateUpdate();
		Show();
	}

	void EditorApplication::Update()
	{
	}

	void EditorApplication::LateUpdate()
	{
	}

	void EditorApplication::Show()
	{
	}
}
