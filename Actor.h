#pragma once
class AActor
{
public:
	AActor(int InX, int InY, int InMesh);
	virtual ~AActor();

	virtual void Tick();
	virtual void Term();
	virtual void Render();
};

