#pragma once

#include "myMath.h"
#include "myMesh.h"
#include "myShader.h"

#include <wrl.h>
#include <d3d11.h>
#include <d3dcompiler.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")

namespace my
{
	class GraphicDevice_DX11
	{
	public:
		GraphicDevice_DX11();
		~GraphicDevice_DX11();
	
		void Initialize();
		void PreRender();
		void RenderMesh(const Mesh& mesh);
		void PostRender();

#if _DEBUG
		void RenderPractice();
#endif // _DEBUG

		const Microsoft::WRL::ComPtr<ID3D11Device>& GetDevice() const { return _device;  };

	private:
		void CreateDevice();
		void CreateSwapChain();
		void CreateDepthStencil();
		void LoadShader();
		void CreateInputLayout();


	private:
		Microsoft::WRL::ComPtr<ID3D11Device>			_device;
		Microsoft::WRL::ComPtr<ID3D11DeviceContext>		_deviceContext;
		
		Microsoft::WRL::ComPtr<ID3D11Texture2D>			_renderTarget;
		Microsoft::WRL::ComPtr<ID3D11RenderTargetView>	_renderTargetView;
		
		Microsoft::WRL::ComPtr<ID3D11Texture2D>			_depthStencilBuffer;
		Microsoft::WRL::ComPtr<ID3D11DepthStencilView>	_depthStencilView;

		Microsoft::WRL::ComPtr<IDXGISwapChain>			_swapChain;

		Microsoft::WRL::ComPtr<ID3D11SamplerState>		_sampler;

		ID3D11Buffer* vertexBuffer = nullptr;
		ID3D11InputLayout* _inputLayouts = nullptr;
		
		std::unique_ptr<Shader> _vertexShader;
		std::unique_ptr<Shader> _pixelShader;
		vector<Vertex> vertexes;


	};
}

