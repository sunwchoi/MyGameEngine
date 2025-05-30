#include "myGraphicDevice_DX11.h"
#include "myApplication.h"
#include "myAssert.h"
#include "myRenderer.h"
#include "myShader.h"
#include <d3d11.h>
#include <d3dcompiler.h>
#include <iostream>

extern my::Application application;

namespace my
{
	GraphicDevice_DX11::GraphicDevice_DX11()
	{
	}

	GraphicDevice_DX11::~GraphicDevice_DX11()
	{
	}

	void GraphicDevice_DX11::Initialize()
	{
		CreateDevice();
		CreateSwapChain();
		CreateDepthStencil();
		LoadShader();
		CreateInputLayout();

		D3D11_RASTERIZER_DESC rasterDesc = {};
		rasterDesc.FillMode = D3D11_FILL_WIREFRAME;
		rasterDesc.CullMode = D3D11_CULL_NONE; // 컬링 끔
		//rasterDesc.FrontCounterClockwise = FALSE; // 정면을 시계방향(CW)으로 간주
		//rasterDesc.DepthClipEnable = true;

		ID3D11RasterizerState* rasterState = nullptr;
		HRESULT hr = _device->CreateRasterizerState(&rasterDesc, &rasterState);
		if (SUCCEEDED(hr))
		{
			_deviceContext->RSSetState(rasterState);
		}

		//vertexes = vector<Vertex>(6);

		//vertexes[0] = Vertex(Vector3(-0.5, -0.5, 0.5), Vector3());
		//vertexes[1] = Vertex(Vector3(-0.5, 0.5, 0.5), Vector3());
		//vertexes[2] = Vertex(Vector3(0.5, 0.5, 0.5), Vector3());
		//
		//vertexes[3] = Vertex(Vector3(-0.5, -0.5, 0.5), Vector3());
		//vertexes[4] = Vertex(Vector3(0.5, 0.5, 0.5), Vector3());
		//vertexes[5] = Vertex(Vector3(0.5, -0.5, 0.5), Vector3());

	}

	void GraphicDevice_DX11::PreRender() const
	{
		// clear and ready
		FLOAT backgroundColor[4] = { 0.f, 0.f, 0.f, 1.0f };
		_deviceContext->ClearRenderTargetView(_renderTargetView.Get(), backgroundColor);
		_deviceContext->ClearDepthStencilView(_depthStencilView.Get(), D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.f, 0);

		D3D11_VIEWPORT viewPort = { 0, 0, application.GetWidth(), application.GetHeight(), 0.f, 1.f };
		_deviceContext->RSSetViewports(1, &viewPort);
		_deviceContext->OMSetRenderTargets(1, _renderTargetView.GetAddressOf(), _depthStencilView.Get());

	}

//#if _DEBUG
//	void GraphicDevice_DX11::RenderPractice()
//	{
//		_deviceContext->IASetInputLayout(_inputLayouts);
//		_deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY::D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
//		UINT vertexSize = sizeof(Vector2);
//		UINT offset = 0;
//		_deviceContext->IASetVertexBuffers(0, 1, &vertexBuffer, &vertexSize, &offset);
//		
//
//		_deviceContext->VSSetShader(static_cast<ID3D11VertexShader*>(_vertexShader->GetRawShader()), 0, 0);
//		_deviceContext->PSSetShader(static_cast<ID3D11PixelShader*>(_pixelShader->GetRawShader()), 0, 0);
//
//		_deviceContext->Draw(3, 0);
//		_swapChain->Present(1, 0);
//	}
//#endif // _DEBUG


	void GraphicDevice_DX11::RenderMesh(const Mesh& mesh, const Transform& transform) const
	{
		PreRender();

		_deviceContext->IASetInputLayout(_inputLayouts);
		_deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY::D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

		D3D11_BUFFER_DESC bufferDesc = {};

		bufferDesc.ByteWidth = mesh.getByteWidth();
		//bufferDesc.ByteWidth = sizeof(Vertex) * 6;

		bufferDesc.BindFlags = D3D11_BIND_FLAG::D3D11_BIND_VERTEX_BUFFER;
		bufferDesc.Usage = D3D11_USAGE::D3D11_USAGE_DYNAMIC;
		bufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_FLAG::D3D11_CPU_ACCESS_WRITE;

		//D3D11_SUBRESOURCE_DATA sub = { vertexes.data()};
		D3D11_SUBRESOURCE_DATA sub = { mesh.getBufferData() };
		
		ID3D11Buffer* vertexBuffer = nullptr;
		_device->CreateBuffer(&bufferDesc, &sub, &vertexBuffer);


		constexpr UINT vertexSize = sizeof(Vertex);
		constexpr UINT offset = 0;

		_deviceContext->IASetVertexBuffers(0, 1, &vertexBuffer, &vertexSize, &offset);
		
		Vector3 camLoc(0.f, 0.f, -10.f);
		Vector3 origin;
		//Vector3 forward = (origin - camLoc).Normalize();
		//Vector3 up(0.f, 1.f, 0.f);
		//Vector3 right = forward.Cross(up).Normalize();

		//float view[16] = {
		//	right._x, right._y, right._z, 0.0f,
		//	up._x, up._y, up._z, 0.0f,
		//	forward._x, forward._y, forward._z, 0.0f,
		//	camLoc._x, camLoc._y, camLoc._z, 1.f,
		//};

		const Vector3& pos = transform.GetPosition();
		const Vector3& scale = transform.GetScale();

		Vector3 right, up, forward;
		transform.GetLocalAxes(right, up, forward);

		float model[16] = {
			right._x * scale._x,   right._y * scale._x,   right._z * scale._x,   0.0f,
			up._x * scale._y,   up._y * scale._y,   up._z * scale._y,   0.0f,
			forward._x * scale._z, forward._y * scale._z, forward._z * scale._z, 0.0f,
			pos._x,                pos._y,                pos._z,                1.0f
		};

		float view[16] = {
			right._x,    up._x,    forward._x,    0.0f,
			right._y,    up._y,    forward._y,    0.0f,
			right._z,    up._z,    forward._z,    0.0f,
			camLoc._x, camLoc._y, camLoc._z, 1.0f
		};

		float projection[16] = {
			1.81066f, 0.0f, 0.0f, 0.0f,
			0.0f, 3.21938f, 0.0f, 0.0f,
			0.0f, 0.0f, -1.0202f, -2.0202f,
			0.0f, 0.0f, -1.0f, 0.0f
		};

		struct CB_DATA
		{
			float model[16];
			float view[16];
			float projection[16];
		} cb;

		memcpy(cb.model, model, sizeof(model));
		memcpy(cb.view, view, sizeof(view));
		memcpy(cb.projection, projection, sizeof(projection));

		D3D11_BUFFER_DESC constantBufferDesc = {};
		constantBufferDesc.ByteWidth = sizeof(CB_DATA);
		constantBufferDesc.BindFlags = D3D11_BIND_FLAG::D3D11_BIND_CONSTANT_BUFFER;
		constantBufferDesc.Usage = D3D11_USAGE::D3D11_USAGE_DEFAULT;
		constantBufferDesc.CPUAccessFlags = 0;
		constantBufferDesc.MiscFlags = 0;
		constantBufferDesc.StructureByteStride = 0;

		D3D11_SUBRESOURCE_DATA constantSub = { &cb };

		ID3D11Buffer* constantBuffer = nullptr;
		_device->CreateBuffer(&constantBufferDesc, &constantSub, &constantBuffer);

		_deviceContext->UpdateSubresource(constantBuffer, 0, nullptr, &cb, 0, 0);
		_deviceContext->VSSetConstantBuffers(0, 1, &constantBuffer);

		_deviceContext->VSSetShader(static_cast<ID3D11VertexShader*>(_vertexShader->GetRawShader()), 0, 0);
		_deviceContext->PSSetShader(static_cast<ID3D11PixelShader*>(_pixelShader->GetRawShader()), 0, 0);

		_deviceContext->Draw(mesh.getBufferSize(), 0);
		_swapChain->Present(1, 0);
	}

	void GraphicDevice_DX11::PostRender()
	{

	}

	void GraphicDevice_DX11::CreateDevice()
	{
		//CreateDevice
		D3D_FEATURE_LEVEL featureLevels[] = { D3D_FEATURE_LEVEL_11_0 };
		UINT creationFlags = D3D11_CREATE_DEVICE_BGRA_SUPPORT;

#if _DEBUG
		creationFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

		D3D11CreateDevice(
			0,
			D3D_DRIVER_TYPE_HARDWARE,
			0,
			creationFlags,
			featureLevels,
			ARRAYSIZE(featureLevels),
			D3D11_SDK_VERSION,
			_device.GetAddressOf(),
			0,
			_deviceContext.GetAddressOf()
		);
	}

	void GraphicDevice_DX11::CreateSwapChain()
	{
		DXGI_SWAP_CHAIN_DESC swapChainDesc = {};

		swapChainDesc.OutputWindow = application.GetHWND();
		swapChainDesc.Windowed = true;
		swapChainDesc.BufferCount = 2;
		swapChainDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
		swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
		swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		swapChainDesc.BufferDesc.Width = application.GetWidth();
		swapChainDesc.BufferDesc.Height = application.GetHeight();
		swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		swapChainDesc.BufferDesc.RefreshRate.Numerator = 144;
		swapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
		swapChainDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
		swapChainDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;

		UINT quility = 0;
		_device->CheckMultisampleQualityLevels(DXGI_FORMAT_R8G8B8A8_UNORM, 4, &quility);

		swapChainDesc.SampleDesc.Count = 1;
		swapChainDesc.SampleDesc.Quality = 0;

		Microsoft::WRL::ComPtr<IDXGIDevice>     pDXGIDevice = nullptr;
		Microsoft::WRL::ComPtr<IDXGIAdapter>    pAdapter = nullptr;
		Microsoft::WRL::ComPtr<IDXGIFactory>    pFactory = nullptr;

		MY_ASSERT_MSG(SUCCEEDED(_device->QueryInterface(__uuidof(IDXGIDevice), (void**)pDXGIDevice.GetAddressOf())), "SwapChain생성 실패");
		MY_ASSERT_MSG(SUCCEEDED(pDXGIDevice->GetParent(__uuidof(IDXGIAdapter), (void**)pAdapter.GetAddressOf())), "SwapChain생성 실패");
		MY_ASSERT_MSG(SUCCEEDED(pAdapter->GetParent(__uuidof(IDXGIFactory), (void**)pFactory.GetAddressOf())), "SwapChain생성 실패");
		MY_ASSERT_MSG(SUCCEEDED(pFactory->CreateSwapChain(_device.Get(), &swapChainDesc, _swapChain.GetAddressOf())), "SwapChain생성 실패");

		_swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)_renderTarget.GetAddressOf());
		_device->CreateRenderTargetView(_renderTarget.Get(), nullptr, _renderTargetView.GetAddressOf());

	}

	void GraphicDevice_DX11::CreateDepthStencil()
	{
		D3D11_TEXTURE2D_DESC depthStencilDesc = {};
		depthStencilDesc.BindFlags = D3D11_BIND_FLAG::D3D11_BIND_DEPTH_STENCIL;
		depthStencilDesc.Format = DXGI_FORMAT::DXGI_FORMAT_D24_UNORM_S8_UINT;
		depthStencilDesc.Usage = D3D11_USAGE::D3D11_USAGE_DEFAULT;
		depthStencilDesc.Width = application.GetWidth();
		depthStencilDesc.Height = application.GetHeight();
		depthStencilDesc.ArraySize = 1;
		depthStencilDesc.SampleDesc.Count = 1;
		depthStencilDesc.SampleDesc.Quality = 0;


		MY_ASSERT_MSG(SUCCEEDED(_device->CreateTexture2D(&depthStencilDesc, nullptr, _depthStencilBuffer.GetAddressOf())), "DepthStencilBuffer 생성실패");
		MY_ASSERT_MSG(SUCCEEDED(_device->CreateDepthStencilView(_depthStencilBuffer.Get(), nullptr, _depthStencilView.GetAddressOf())), "DepthStencilView 생성실패");
	}

	void GraphicDevice_DX11::LoadShader()
	{
		_vertexShader = std::make_unique<Shader>(Shader::eStageType::Vertex);
		_vertexShader->Load(L"..\\MyGameEngine_Source\\VertexShader.hlsl");

		_pixelShader = std::make_unique<Shader>(Shader::eStageType::Pixel);
		_pixelShader->Load(L"..\\MyGameEngine_Source\\PixelShader.hlsl");
	}

	void GraphicDevice_DX11::CreateInputLayout()
	{
		D3D11_INPUT_ELEMENT_DESC inputLayoutDesces[2] = {};

		inputLayoutDesces[0].AlignedByteOffset = 0;
		inputLayoutDesces[0].Format = DXGI_FORMAT_R32G32B32_FLOAT;
		inputLayoutDesces[0].InputSlot = 0;
		inputLayoutDesces[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
		inputLayoutDesces[0].SemanticName = "POSITION";
		inputLayoutDesces[0].SemanticIndex = 0;

		inputLayoutDesces[1].AlignedByteOffset = 12;
		inputLayoutDesces[1].Format = DXGI_FORMAT_R32G32B32_FLOAT;
		inputLayoutDesces[1].InputSlot = 0;
		inputLayoutDesces[1].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
		inputLayoutDesces[1].SemanticName = "NORMAL";
		inputLayoutDesces[1].SemanticIndex = 0;


		_device->CreateInputLayout(
			inputLayoutDesces,
			2,
			_vertexShader->GetBlob()->GetBufferPointer(),
			_vertexShader->GetBlob()->GetBufferSize(),
			&_inputLayouts
		);
	}
}