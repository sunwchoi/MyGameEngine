#include "myAnimation.h"
#include "myAnimator.h"
#include "myTime.h"
#include "Transform.h"
#include "myGameObject.h"
#include "myRenderer.h"

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

	HRESULT Animation::Load(const std::wstring& path)
	{
		return E_NOTIMPL;
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
				return;
			}
			_index++;
		}
	}

	void Animation::Render(HDC hdc)
	{
		if (_spriteSheet == nullptr)
			return;

		Transform* transform = _animator->GetOwner()->GetComponent<Transform>();
		Vector2 pos = renderer::mainCamera->CalculatePosition(transform->GetPosition());
	
		BLENDFUNCTION blendFunction;

		blendFunction.BlendOp = AC_SRC_OVER;
		blendFunction.BlendFlags = 0;
		blendFunction.AlphaFormat = AC_SRC_ALPHA;
		blendFunction.SourceConstantAlpha = 125;

		const Sprite& sprite = _animationSheet[_index];
		HDC imgHdc = _spriteSheet->GetHDC();

		// *5인 이유는?
		AlphaBlend(hdc, pos._x, pos._y, sprite._size._x * 10, sprite._size._y * 10, imgHdc, sprite._leftTop._x, sprite._leftTop._y, sprite._size._x, sprite._size._y, blendFunction);
	}

	void Animation::CreateAnimation(Animator* animator, Texture* spriteSheet, Vector2 leftTop, Vector2 size, Vector2 offset, UINT spriteLength, float duration)
	{
		_animator = animator;
		_spriteSheet = spriteSheet;
		
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

}
