#include "Player.h"
#include "Engine.h"

APlayer::APlayer(int InX, int InY, char InMesh)
{
	X = InX;
	Y = InY;
	Mesh = InMesh;
	ZOrder = 5;
}

APlayer::~APlayer()
{
}

void APlayer::BeginPlay()
{
	__super::BeginPlay(); // 부모 함수 사용
}

void APlayer::Tick()
{
	__super::Tick();

	if (UEngine::KeyCode == 'w') //
	{
		Y--;
	}

	if (UEngine::KeyCode == 's')
	{
		Y++;
	}

	if (UEngine::KeyCode == 'a')
	{
		X--;
	}

	if (UEngine::KeyCode == 'd')
	{
		X++;
	}
}

void APlayer::Render()
{
	__super::Render();
}
