#include <conio.h>
#include "Engine.h"
#include "World.h"

UEngine::UEngine()
{
	Init();
}

UEngine::~UEngine()
{
	Term();
}

void UEngine::Init()
{
	bIsRunning = true; // true면 실행

	World = new UWorld(); // 월드를 불러옴
}

void UEngine::Term()
{
	delete World;
	World = nullptr;
}

void UEngine::Run()
{
	while (bIsRunning) // true시 월드 실행
	{
		Input();
		Tick();
		Render();
	}
}

// 월드 실행
void UEngine::Input()
{
	int KeyCode = _getch();
}

void UEngine::Tick()
{
	World->Tick();
}

void UEngine::Render()
{
	World->Render();
}
