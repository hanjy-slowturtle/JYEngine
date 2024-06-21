#include "jyTime.h"

namespace jy
{
	LARGE_INTEGER Time::CpuFrequency = {};
	LARGE_INTEGER Time::PrevFrequency = {};
	LARGE_INTEGER Time::CurrentFrequency = {};
	float Time::DeltaTimeValue = 0.0f;

	void Time::Initialize()
	{
		// Cpu 고유 진동수
		QueryPerformanceFrequency(&CpuFrequency);

		// 프로그램이 시작 했을 때 현재 진동수
		QueryPerformanceCounter(&PrevFrequency);
	}
	void Time::Update()
	{
		QueryPerformanceCounter(&CurrentFrequency);

		float diffFrequency = static_cast<float>(CurrentFrequency.QuadPart - PrevFrequency.QuadPart);
		DeltaTimeValue = diffFrequency / static_cast<float>(CpuFrequency.QuadPart);
		PrevFrequency.QuadPart = CurrentFrequency.QuadPart;
	}
	void Time::Render(HDC hdc)
	{
		static float time = 0.0f;

		time += DeltaTimeValue;
		float fps = 1.0f / DeltaTimeValue;

		wchar_t str[100] = L"";
		swprintf_s(str, 100, L"FPS: %d, Time: %f, DeltaTimeValue: %f", (int)fps, time, DeltaTimeValue);
		int len = wcsnlen_s(str, 100);

		TextOut(hdc, 0, 0, str, len);
	}
}