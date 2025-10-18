#include "myShader.h"
#include "myAssert.h"
#include "myApplication.h"
#include "myGraphicDevice_DX11.h"

extern my::Application application;

namespace my
{
	Shader::Shader(eStageType stageType)
		: Resource(L"ShaderResource", eResourceType::Shader)
		, _blob(nullptr)
		, _rawShader(nullptr)
		, _stageType(stageType)
	{
	}

	Shader::~Shader()
	{
	}

	void Shader::Load(const std::wstring& path)
	{
		MY_ASSERT_MSG((uint8)eStageType::Count == 2 && _stageType != eStageType::Count, "stage 타입은 Vertex, Pixel 둘 중 하나");

		DWORD shaderFlags = D3DCOMPILE_ENABLE_STRICTNESS;
		shaderFlags |= D3DCOMPILE_DEBUG;
		shaderFlags |= D3DCOMPILE_SKIP_OPTIMIZATION;

		ID3DBlob* errorBlob = nullptr;
		HRESULT rv = D3DCompileFromFile(
			path.c_str(),
			nullptr,
			D3D_COMPILE_STANDARD_FILE_INCLUDE,
			"main",
			_stageType == eStageType::Vertex ? "vs_5_0" : "ps_5_0",
			shaderFlags,
			0,
			&_blob,
			&errorBlob
		);

		if (errorBlob)
		{
			OutputDebugStringA((char*)errorBlob->GetBufferPointer());
			errorBlob->Release();
		}
		MY_ASSERT_MSG(SUCCEEDED(rv), "Shader 컴파일 실패");

		const Microsoft::WRL::ComPtr<ID3D11Device>& device = application.GetGraphicDevice()->GetDevice();
		
		if (_stageType == eStageType::Vertex)
		{
			ID3D11VertexShader* vertexShader = nullptr;

			device->CreateVertexShader(_blob->GetBufferPointer(), _blob->GetBufferSize(), nullptr, &vertexShader);
			_rawShader = vertexShader;
		}
		else if (_stageType == eStageType::Pixel)
		{
			ID3D11PixelShader* pixelShader = nullptr;

			device->CreatePixelShader(_blob->GetBufferPointer(), _blob->GetBufferSize(), nullptr, &(pixelShader));
			_rawShader = pixelShader;
		}
	}

}
