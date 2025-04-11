#include "myAnimator.h"
#include "myAnimation.h"
#include "myAssert.h"

namespace my
{
	Animator::Animator()
	{
	}

	Animator::~Animator()
	{
	}

	void Animator::Initialize()
	{
	}

	void Animator::Update()
	{
		if (_activeAnimation)
			_activeAnimation->Update();
	}

	void Animator::LateUpdate()
	{
	}

	void Animator::Render(HDC hdc)
	{
		if (_activeAnimation)
		{
			_activeAnimation->Render(hdc);
			if (_bLoop && _activeAnimation->isComplete())
				_activeAnimation->Reset();
		}
	}

	void Animator::CreateAnimation(const std::wstring& name, Texture* spriteSheet, Vector2 leftTop, Vector2 size, Vector2 offset, UINT spriteLength, float duration, bool bReverse /*= false*/)
	{
		Animation* animation = FindAnimation(name);
		if (animation)
			return;

		animation = new Animation(name);
		animation->CreateAnimation(this, spriteSheet, leftTop, size, offset, spriteLength, duration, bReverse);

		_animations.insert(make_pair(name, animation));
	}

	Animation* Animator::FindAnimation(const std::wstring& name)
	{
		std::map<std::wstring, Animation*>::iterator it = _animations.find(name);
		if (it == _animations.end())
			return nullptr;
	
		return it->second;
	}

	void Animator::PlayAnimation(const std::wstring& name, bool bLoop /*= true*/)
	{
		Animation* animation = FindAnimation(name);
		if (animation == nullptr)
			return;

		if (_activeAnimation != animation)
		{
			_activeAnimation = animation;
			_activeAnimation->Reset();
			_bLoop = bLoop;
		}
	}

	void Animator::BindCompleteEvent(const std::wstring& name, const std::function<void()>& func)
	{
		Animation* animation = FindAnimation(name);
		MY_ASSERT_MSG(animation != nullptr, "없는 애니메이션 이름이 들어와선 안됩니다.");

		animation->BindCompleteEvent(func);
	}

}
