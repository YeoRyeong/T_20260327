#include "World.h"

//#include <fstream>

#include "Actor.h"
#include "Player.h"
#include "Monster.h"
#include "Goal.h"
#include "Wall.h"
#include "Floor.h"

UWorld::UWorld()
{	
}

UWorld::~UWorld()
{
	for (auto Actor : Actors)
	{
		delete Actor;
		//Actor = nullptr;
	}

	Actors.clear();
}

void UWorld::Load(std::string LoadMapName)
{
	SpawnActor<APlayer>()->SetActorLocation(1, 1);


}

void UWorld::Tick()
{
	for (auto Actor : Actors)
	{
		Actor->Tick();
	}
}


void UWorld::Render()
{
	for (auto Actor : Actors)
	{
		Actor->Render();
	}
}
