#include "jyTexture.h"
#include "jyApplication.h"

// 해당 전역변수가 조재함을 알리는 키워드 extern
extern jy::Application application;

namespace jy
{
	namespace graphics
	{
		Texture::Texture()
			: Resource(enums::eResourceType::Texture)
		{
		}
		Texture::~Texture()
		{
		}
		HRESULT Texture::Load(const std::wstring& path)
		{
			std::wstring ext
				= path.substr(path.find_last_of(L".") + 1);

			if (ext == L"bmp")
			{
				mType = eTextureType::Bmp;
				mBitmap = (HBITMAP) LoadImageW(
					nullptr,
					path.c_str(),
					IMAGE_BITMAP,
					0,
					0,
					LR_LOADFROMFILE |
					LR_CREATEDIBSECTION
				);

				if (mBitmap == nullptr)
				{
					return S_FALSE;
				}

				BITMAP info = {};
				GetObject(mBitmap, sizeof(BITMAP), &info);

				mWidth = info.bmWidth;
				mHeight = info.bmHeight;

				HDC mainDC = application.GetHDC();
				mHdc = CreateCompatibleDC(mainDC);

				HBITMAP prevBitmap = (HBITMAP)SelectObject(mHdc, mBitmap);
				DeleteObject(prevBitmap);
			}
			else if (ext == L"png" || ext == L"jpg")
			{
				mType = eTextureType::Png;
				mImage = Gdiplus::Image::FromFile(path.c_str());
				if (mImage == nullptr)
				{
					return S_FALSE;
				}

				mWidth = mImage->GetWidth();
				mHeight = mImage->GetHeight();
			}

			return S_OK;
		}
	}
}