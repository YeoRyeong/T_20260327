#include "Monster.h"

AMonster::AMonster(int InX, int InY, char InMesh)
{
	X = InX;
	Y = InY;
	Mesh = InMesh;
	ZOrder = 50;

	R = 255;
	G = 255;
	B = 255;
	Load("Data/monster.bmp");
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
