#include <conio.h>
#include "Engine.h"
#include "World.h"

UEngine* UEngine::Instance = nullptr;
int UEngine::KeyCode = 0;

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

void UEngine::InitBuffer()
{
	ScreenBufferHandel[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL,
		CONSOLE_TEXTMODE_BUFFER, NULL);
	ScreenBufferHandel[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL,
		CONSOLE_TEXTMODE_BUFFER, NULL);
}

void UEngine::Clear()
{
	DWORD DW;
	FillConsoleOutputCharacter(ScreenBufferHandel[ActiveScreenBufferIndex], 
		' ', 80 * 25, COORD{ 0, 0 }, &DW);
}

void UEngine::Render(int InX, int InY, char InMesh)
{
	char MeshString[2] = { 0, };
	MeshString[0] = InMesh;

	SetConsoleCursorPosition(ScreenBufferHandel[ActiveScreenBufferIndex],
		COORD{ (SHORT)InX, (SHORT)InY });
	WriteFile(ScreenBufferHandel[ActiveScreenBufferIndex], MeshString, 1, NULL, NULL);
}

void UEngine::Flip()
{
	// 그린 거 붙이기
	SetConsoleActiveScreenBuffer(ScreenBufferHandel[ActiveScreenBufferIndex]);
	ActiveScreenBufferIndex = !ActiveScreenBufferIndex;
}

void UEngine::TermBuffer()
{
	CloseHandle(ScreenBufferHandel[0]);
	CloseHandle(ScreenBufferHandel[1]);
}

// 월드 실행
void UEngine::Input()
{
	KeyCode = _getch();
}

void UEngine::Tick()
{
	World->Tick();
}

void UEngine::Render()
{
	World->Render();
}
