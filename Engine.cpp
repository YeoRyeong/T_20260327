#include "Engine.h"
#include "Actor.h"
#include "World.h"
#include "ResourceManager.h"

UEngine* UEngine::Instance = nullptr;

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
	SDL_Init(SDL_INIT_EVERYTHING);

	MyWindow = SDL_CreateWindow("Hello", 100, 100, 1024, 768, SDL_WINDOW_SHOWN);

	// GPU, 화면을 그려주려면 붓이 필요함.
	MyRender = SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE); //  SDL_RENDERER_PRESENTVSYNC 하드웨어에서 프레임을 맞춰줌.
	//MyRender = SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_SOFTWARE); //  SDL_RENDERER_SOFTWARE GPU대신 CPU 사용 성능이 떨어짐.
	
	ResourceManager = new UResourceManager();
	
	bIsRunning = true;

	InitBuffer();

	World = new UWorld();
}

void UEngine::Term()
{
	SDL_DestroyRenderer(MyRender);

	SDL_DestroyWindow(MyWindow);

	SDL_Quit();

	delete World;
	TermBuffer();
	World = nullptr;

	delete ResourceManager;
}


void UEngine::Run()
{
	Uint64 LastTime;

	while (bIsRunning)
	{
		LastTime = SDL_GetTicks64(); // 이벤트 하기 전에 시간을 구해야함.

		SDL_PollEvent(&MyEvent); // 가져오기만 함.

		Input();
		Tick();
		Render();

		DeltaSeconds = (float)(SDL_GetTicks64() - LastTime) / 1000.0f; // m/s
		// SDL_Log("%f s", DeltaSeconds);
	}
}


void UEngine::InitBuffer()
{
	ScreenBufferHandle[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	ScreenBufferHandle[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	CONSOLE_CURSOR_INFO ConsoleCursorInfo;
	ConsoleCursorInfo.dwSize = 1;
	ConsoleCursorInfo.bVisible = FALSE;

	SetConsoleCursorInfo(ScreenBufferHandle[0], &ConsoleCursorInfo);
	SetConsoleCursorInfo(ScreenBufferHandle[1], &ConsoleCursorInfo);

}

void UEngine::Clear()
{
	// CPU하는건 GPU가 할 일을 적는것 많이
	// GPU한테 보낼 명령어모음
	SDL_SetRenderDrawColor(MyRender, 255, 255, 255, 255);
	SDL_RenderClear(MyRender);

	// Console Clear
	DWORD DW;
	FillConsoleOutputCharacter(ScreenBufferHandle[ActiveScreenBufferIndex], ' ', 80 * 25, COORD{ 0, 0 }, &DW);
}

void UEngine::Render(int InX, int InY, char InMesh)
{
	char MeshString[2] = { 0, };
	MeshString[0] = InMesh;

	SetConsoleCursorPosition(ScreenBufferHandle[ActiveScreenBufferIndex], COORD{ (SHORT)InX, (SHORT)InY });
	WriteFile(ScreenBufferHandle[ActiveScreenBufferIndex], MeshString, 1, NULL, NULL);
}

void UEngine::Render(int InX, int InY, int R, int G, int B)
{
	int TileSize = 30;
	SDL_SetRenderDrawColor(MyRender, R, G, B, 255);
	SDL_Rect MyRect = { InX * TileSize, InY * TileSize, TileSize, TileSize };
	//SDL_RenderDrawPoint(MyRender, InX, InY);
	SDL_RenderFillRect(MyRender, &MyRect);
}

void UEngine::Render(int InX, int InY, SDL_Texture* InTexture)
{
	int TileSize = 30;
	
	SDL_Rect MyRect = { InX * TileSize, InY * TileSize, TileSize, TileSize };
	SDL_RenderCopy(MyRender, InTexture, nullptr, &MyRect);
}

void UEngine::Flip()
{
	SetConsoleActiveScreenBuffer(ScreenBufferHandle[ActiveScreenBufferIndex]);
	ActiveScreenBufferIndex = !ActiveScreenBufferIndex;
}

void UEngine::TermBuffer()
{
	CloseHandle(ScreenBufferHandle[0]);
	CloseHandle(ScreenBufferHandle[1]);
}

void UEngine::Input()
{
	//if (_kbhit())
	//{
	//	KeyCode = _getch();
	//}
}

void UEngine::Tick()
{
	if (MyEvent.type == SDL_QUIT)
	{

		bIsRunning = false;
	}

	World->Tick();
}

void UEngine::Render()
{


	World->Render();

	// 그려 CPU -> GPU
	SDL_RenderPresent(MyRender);
}