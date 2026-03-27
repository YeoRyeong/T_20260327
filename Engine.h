#pragma once

class UWorld;

class UEngine
{
public:
	UEngine();
	~UEngine();

	void Init();

	void Term();

	void Run();

	inline UWorld* GetWorld() {
		return World;
	}

protected:

	void Input();
	void Tick();
	void Render();

	UWorld* World;

	int bIsRunning = 1; 
};

