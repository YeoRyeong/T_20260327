#pragma once

#include <vector>
#include <Windows.h>
#include <iostream>
#include "SDL.h"

// 사용할 라이브러리 파일 추가
#pragma comment(lib, "SDL2")
#pragma comment(lib, "SDL2main")

class AActor;
class UWorld;
class UResourceManager;

struct SDL_Window;
struct SDL_Renderer;

class UEngine
{
protected:
	UEngine();

	static UEngine* Instance;

public:
	~UEngine();

	static UEngine* GetInstance()
	{
		if (Instance == nullptr)
		{
			Instance = new UEngine();
		}

		return Instance;
	}

	void Init();
	void Term();

	void Run();
	void Stop() 
	{
		bIsRunning = false;
	}
	
	inline UWorld* GetWorld()
	{
		return World;
	}

	static int KeyCode;

	//Renderer
	HANDLE ScreenBufferHandle[2];
	int ActiveScreenBufferIndex = 0;

	void InitBuffer();
	void Clear();
	void Render(int InX, int InY, char InMesh);
	void Render(int InX, int InY, int R, int G, int B);
	void Render(int InX, int InY, SDL_Texture* InTexture);

	void Flip();
	void TermBuffer();

	const SDL_Event& GetEvent()
	{
		return MyEvent;
	}

	inline float GetDeltaSeconds() const
	{
		return DeltaSeconds;
	}

	inline SDL_Renderer* GetRenderer() const
	{
		return MyRender;
	}

	inline SDL_Window* GetWindow() const
	{
		return MyWindow;
	}

	inline UResourceManager* GetResourceManager()
	{
		return ResourceManager;
	}

protected:
	void Input();
	void Tick();
	void Render();

	class UWorld* World;

	int bIsRunning : 1;

	SDL_Window* MyWindow;
	SDL_Renderer* MyRender;
	SDL_Event MyEvent;

	float DeltaSeconds;

	UResourceManager* ResourceManager;
};


#define GEngine			UEngine::GetInstance()