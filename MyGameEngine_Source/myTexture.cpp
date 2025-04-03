#include "myTexture.h"
#include "myApplication.h"

extern my::Application application;

namespace my
{

	Texture::Texture(const std::wstring& name)
		: Resource(name, eResourceType::Texture)
	{
	}

	Texture::~Texture()
	{
	}

	HRESULT Texture::Load(const std::wstring& path)
	{
		const std::wstring ext = path.substr(path.find_last_of(L".") + 1);
		
		SetPath(path);
		if (ext == L"bmp")
		{
			_type = eTextureType::Bmp;

			//Load Image
			_bitmap = (HBITMAP)LoadImageW(nullptr, path.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
			if (_bitmap == nullptr)
				return S_FALSE;

			//Save Info
			BITMAP info;

			GetObject(_bitmap, sizeof(BITMAP), &info);
			_width = info.bmWidth;
			_height = info.bmHeight;

			//Create DC
			HDC mainDC = application.getHDC();

			_hdc = CreateCompatibleDC(mainDC);

			//Delete Old Bitmap
			HBITMAP oldBitmap = (HBITMAP)SelectObject(_hdc, _bitmap);

			DeleteObject(oldBitmap);
		}
		else if (ext == L"png")
		{
			_type = eTextureType::Png;

			_image = Gdiplus::Image::FromFile(path.c_str());
			if (_image == nullptr)
				return S_FALSE;

			_width = _image->GetWidth();
			_height = _image->GetHeight();
		}
		else
			return S_FALSE;

		return S_OK;
	}
}

