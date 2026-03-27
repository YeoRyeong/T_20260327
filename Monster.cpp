#include "Monster.h"

AMonster::AMonster(int InX, int InY, char InMesh)
{
	X = InX;
	Y = InY;
	Mesh = InMesh;
}

AMonster::~AMonster()
{
}

void AMonster::BeginPlay()
{
	__super::Render();
}

void AMonster::Tick()
{
	__super::Render();
}

void AMonster::Render()
{
	__super::Render();
}
