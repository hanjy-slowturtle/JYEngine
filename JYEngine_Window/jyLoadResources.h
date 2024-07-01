#pragma once
#include "../JYEngine_SOURCE/jyResources.h"
#include "../JYEngine_SOURCE/jyTexture.h"

namespace jy
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"hayoung", L"C:\\Users\\WD\\source\\repos\\JYEngine\\Resources\\hayoung_wedding_nude.jpg");
		Resources::Load<graphics::Texture>(L"heena", L"C:\\Users\\WD\\source\\repos\\JYEngine\\Resources\\heena_nude.jpg");
	}
}