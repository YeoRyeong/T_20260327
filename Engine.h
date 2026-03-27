#pragma once

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

protected:

	void Input();
	void Tick();
	void Render();

	UWorld* World;

	int bIsRunning = 1; 
};

