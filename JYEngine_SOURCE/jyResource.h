#pragma once
#include "jyEntity.h"

namespace jy
{
	// 추상 클래스는 메모리 할당 불가.
	// 상속 받아서만 사용해야 함.
	class Resource abstract : public Entity
	{
	public:
		Resource(enums::eResourceType type);
		virtual ~Resource();

		// 순수가상함수. 실제 메모리 할당이 불가능해지는 문법
		virtual HRESULT Load(const std::wstring& path) = 0;
		
		const std::wstring& GetPath() { return mPath; }
		void SetPath(const std::wstring& path) { mPath = path; }
	private:
		const enums::eResourceType mType;
		std::wstring mPath;
	};
}
