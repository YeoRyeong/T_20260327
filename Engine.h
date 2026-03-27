#pragma once
#include<vector>
#include<Windows.h>


class UWorld;

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

	inline UWorld* GetWorld() {
		return World;
	}

	static int KeyCode; // 정적변수

	// Renderer 로 만들어야함.
	HANDLE ScreenBufferHandel[2];
	int ActiveScreenBufferIndex = 0;

	void InitBuffer();
	void Clear();
	void Render(int InX, int InY, char InMesh);
	void Flip();// 1번인지 2번인지 왔다갔다하는 함수
	void TermBuffer();

protected:

	void Input();
	void Tick();
	void Render();

	UWorld* World;

	int bIsRunning = 1; 
};

