#pragma once
#include "myResource.h"

#include <mmsystem.h>
#include <dinput.h>
#pragma comment(lib, "Msimg32.lib");
#pragma comment(lib, "winmm.lib");

#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib");

namespace my
{

    class Texture :
        public Resource
    {
    public:
        enum class eTextureType
        {
            Bmp,
            Png,

            Count
        };

    public:
        Texture(const std::wstring& name);
        ~Texture();

        void Load(const std::wstring& path) override;

        const HDC       GetHDC() const { return _hdc; }
        const UINT      GetHeight() const { return _height; }
        const UINT      GetWidth() const { return _width; }

    private:
        eTextureType    _type;

        HBITMAP         _bitmap;
        HDC             _hdc;

        UINT			_height;
        UINT			_width;
    };
}

