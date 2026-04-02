#include "Player.h"
#include "Engine.h"
#include "GamePlayStatics.h"

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

	Load("Data/player.bmp");
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

	SDL_Event Event = GEngine->GetEvent();
	
	if (Event.type == SDL_KEYDOWN)
	{
		SDL_Keycode KeyCode = Event.key.keysym.sym;

		if (KeyCode == SDLK_w)
		{
			Y--;
			// callback
			// std::function<void>
			SpriteIndexY = 2;
			SpriteIndexX = 0;
		}
		if (KeyCode == SDLK_s)
		{
			Y++;
			SpriteIndexY = 3;
			SpriteIndexX = 0;
		}
		if (KeyCode == SDLK_a)
		{
			X--;
			SpriteIndexY = 0;
			SpriteIndexX = 0;
		}
		if (KeyCode == SDLK_d)
		{
			X++;
			SpriteIndexY = 1;
			SpriteIndexX = 0;

		}
		if (KeyCode == SDLK_ESCAPE)
		{
			GEngine->Stop();
		}
	}

	ElapsedTime += UGamePlayStatics::GetWorldDeltaSecondes(); // 프레임 
	if (ElapsedTime >= ExecutionTime)
	{
		SpriteIndexX++;
		SpriteIndexX = SpriteIndexX % 5;
		ElapsedTime = 0;
	}
}

void APlayer::Load(std::string Filename)
{
	Image = SDL_LoadBMP(Filename.c_str());

	// SDL_MapRGB(Image->format, 255,255,255) 해당 색상을 RGP에 저장하지않음.
	// 투명으로 저장
	SDL_SetColorKey(Image, SDL_TRUE, SDL_MapRGB(Image->format, 255, 0, 255));

	Texture = SDL_CreateTextureFromSurface(GEngine->GetRenderer(), Image); // GPU에 넘겨줌
}

void APlayer::Render()
{
	int TileSize = 30;
	int SpriteSizeX = Image->w / 5;
	int SpriteSizeY = Image->h / 5;



	SDL_Rect SourceRect = { SpriteIndexX * SpriteSizeX, SpriteIndexY * SpriteSizeY ,SpriteSizeX, SpriteSizeY };
	SDL_Rect DestinationRect = { X * TileSize, Y * TileSize, TileSize, TileSize };
	SDL_RenderCopy(GEngine->GetRenderer(), Texture, &SourceRect, &DestinationRect);

}