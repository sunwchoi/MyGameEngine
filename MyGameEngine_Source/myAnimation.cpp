#include "myAnimation.h"
#include "myAnimator.h"
#include "myTime.h"
#include "Transform.h"
#include "myGameObject.h"
#include "myRenderer.h"
#include "myApplication.h"

extern my::Application application;

namespace my
{
	Animation::Animation(const std::wstring& name)
		: Resource(name, eResourceType::Animation)
		, _animator(nullptr)
		, _spriteSheet(nullptr)
		, _index(-1)
		, _time(0)
		, _bComplete(false)
	{
	}

	Animation::~Animation()
	{
	}

	void Animation::Load(const std::wstring& path)
	{
	}

	void Animation::Update()
	{
		if (_bComplete)
			return;

		_time += Time::DeltaTime();

		if (_time > _animationSheet[_index]._duration)
		{
			_time = 0;
			if (_index == _animationSheet.size() - 1)
			{
				_bComplete = true;
				//_completeEvent.Excute();
				return;
			}
			_index++;
		}
	}

	void Animation::Render(HDC hdc)
	{
		if (_spriteSheet == nullptr)
			return;

		//Transform* transform = _animator->GetOwner()->GetComponent<Transform>();
		//Vector2 pos = renderer::mainCamera->CalculatePosition(transform->GetPosition());
	
		//BLENDFUNCTION blendFunction;

		//blendFunction.BlendOp = AC_SRC_OVER;
		//blendFunction.BlendFlags = 0;
		//blendFunction.AlphaFormat = AC_SRC_ALPHA;
		//blendFunction.SourceConstantAlpha = 255;

		//const Sprite& sprite = _animationSheet[_index];
		//if (_bReverse)
		//{
		//	HDC imgHdc = CreateCompatibleDC(hdc);
		//	HBITMAP imgBitmap = CreateCompatibleBitmap(hdc, sprite._size._x, sprite._size._y);
		//	HBITMAP oldBitmap = (HBITMAP)SelectObject(imgHdc, imgBitmap);
		//	DeleteObject(oldBitmap);

		//	StretchBlt(imgHdc, 0, 0, sprite._size._x, sprite._size._y, _spriteSheet->GetHDC(), sprite._leftTop._x + sprite._size._x, sprite._leftTop._y, sprite._size._x * -1, sprite._size._y, SRCCOPY);
		//	AlphaBlend(hdc, pos._x - sprite._size._x / 2, pos._y - sprite._size._y / 2, sprite._size._x, sprite._size._y, imgHdc, 0, 0, sprite._size._x, sprite._size._y, blendFunction);
		//
		//	DeleteObject(imgBitmap);
		//	DeleteDC(imgHdc);
		//}
		//else
		//{
		//	AlphaBlend(hdc, pos._x - sprite._size._x / 2, pos._y - sprite._size._y / 2, sprite._size._x , sprite._size._y, _spriteSheet->GetHDC(), sprite._leftTop._x, sprite._leftTop._y, sprite._size._x, sprite._size._y, blendFunction);
		//}
	

	}

	void Animation::CreateAnimation(Animator* animator, Texture* spriteSheet, Vector2 leftTop, Vector2 size, Vector2 offset, UINT spriteLength, float duration, bool bReverse)
	{
		_animator = animator;
		_spriteSheet = spriteSheet;
		_bReverse = bReverse;
		for (int i = 0; i < spriteLength; i++)
		{
			Sprite sprite;

			sprite._leftTop._x = leftTop._x + (size._x * i);
			sprite._leftTop._y = leftTop._y;
			sprite._size = size;
			sprite._offset = offset;
			sprite._duration = duration;

			_animationSheet.push_back(sprite);
		}
	}

	void Animation::Reset()
	{
		_index = 0;
		_time = 0;
		_bComplete = false;
	}

	void Animation::BindCompleteEvent(const std::function<void()>& func)
	{
		//_completeEvent.Bind(func);
	}
}
