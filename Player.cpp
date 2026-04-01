#include "Player.h"
#include "Engine.h"

#include <iostream>

APlayer::APlayer(int InX, int InY, char InMesh)
{
	X = InX;
	Y = InY;
	Mesh = InMesh;
	ZOrder = 100;

	R = 255;
	G = 0;
	B = 0;
}

APlayer::~APlayer()
{
}

void APlayer::BeginPlay()
{
	__super::BeginPlay();

}

void APlayer::Tick()
{
	__super::Tick();
	
	SDL_GetTicks64();

	SDL_Event Event = GEngine->GetEvent();
	
	if (Event.type == SDL_KEYDOWN)
	{
		SDL_Keycode KeyCode = Event.key.keysym.sym;

		if (KeyCode == SDLK_w)
		{
			Y--;
			// callback
			// std::function<void>
		}
		if (KeyCode == SDLK_s)
		{
			Y++;
		}
		if (KeyCode == SDLK_a)
		{
			X--;
		}
		if (KeyCode == SDLK_d)
		{
			X++;
		}
		if (KeyCode == SDLK_ESCAPE)
		{
			GEngine->Stop();
		}
	}


}

void APlayer::Render()
{
	//AActor::Render();
	__super::Render();
}