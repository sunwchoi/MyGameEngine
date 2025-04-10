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

	void Texture::Load(const std::wstring& path)
	{
		const std::wstring ext = path.substr(path.find_last_of(L".") + 1);
		
		SetPath(path);
		if (ext == L"bmp")
		{
			_type = eTextureType::Bmp;

			//Load Bitmap
			_bitmap = (HBITMAP)LoadImageW(nullptr, path.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		}
		else if (ext == L"png")
		{
			_type = eTextureType::Png;

			//Load Bitmap
			Gdiplus::Image* image = Gdiplus::Image::FromFile(path.c_str());
			Gdiplus::Bitmap* bitmap = reinterpret_cast<Gdiplus::Bitmap*>(image->Clone());
			bitmap->GetHBITMAP(Gdiplus::Color(0), &_bitmap);
		}

		//Save Info
		BITMAP info;

		GetObject(_bitmap, sizeof(BITMAP), &info);
		_width = info.bmWidth;
		_height = info.bmHeight;

		//Create DC
		HDC mainDC = application.GetHDC();
		
		_hdc = CreateCompatibleDC(mainDC);

		//Delete Old Bitmap
		HBITMAP oldBitmap = (HBITMAP)SelectObject(_hdc, _bitmap);
		
		DeleteObject(oldBitmap);
	}
}

