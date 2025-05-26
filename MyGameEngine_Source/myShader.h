#pragma once

#include "myResource.h"
#include "Common.h"

#include <d3d11.h>
#include <d3dcompiler.h>
#include <wrl.h>

namespace my
{

	class Shader : public Resource
	{
	public:
		enum class eStageType : uint8
		{
			Vertex = 0,
			Pixel,

			Count
		};

	public:
		explicit Shader(eStageType stageType);
		virtual ~Shader() override;

		virtual void Load(const std::wstring& path) override;

		//Shader Ŭ������ �Ľ̿뵵�̱⶧���� Getter�� ���� const�� ������ ����
		ID3D11DeviceChild* GetRawShader() const { return _rawShader; };
		ID3DBlob* GetBlob() const { return _blob; };

	private:
		explicit Shader(const Shader& other) : Resource( L"Shader", eResourceType::Shader ) {}
		Shader& operator=(const Shader& other) {}

	private:
		ID3DBlob*			_blob;
		ID3D11DeviceChild*	_rawShader;
		eStageType			_stageType;
	};
}

