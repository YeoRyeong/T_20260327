#pragma once
class AActor
{
public:
	AActor(int InX = 0, int InY = 0, char InMesh = ' ');
	virtual ~AActor();

	virtual void BeginPlay();
	virtual void Tick();
	virtual void Render();

	void SetActorLocation(int NeX, int NeY);
	const int& GetZOrder() 
	{ 
		return ZOrder; 
	}
protected:
	int X;
	int Y;
	int ZOrder; // 그릴 때 어디를 그리는 지 확인
	char Mesh;
};

