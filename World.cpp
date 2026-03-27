#include "World.h"

#include <fstream>

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
	//SpawnActor<APlayer>()->SetActorLocation(1, 1);
	
	std::ifstream MapStream(LoadMapName);
	
	int Y = 0;

	while(!MapStream.eof())
	{
		std::string Line;
		std::getline(MapStream, Line); // ∏ ¿ª ¿–¿Ω

		for (int X = 0; X < Line.length(); ++X)
		{
			if (Line[X] == '*')
			{
				SpawnActor<AWall>()->SetActorLocation(X, Y);
			}

			else if (Line[X] == ' ')
			{
				SpawnActor<AFloor>()->SetActorLocation(X, Y);
			}

			else if (Line[X] == 'G')
			{
				SpawnActor<AGoal>()->SetActorLocation(X, Y);
			}

			else if (Line[X] == 'M')
			{
				SpawnActor<AMonster>()->SetActorLocation(X, Y);
			}

			else if (Line[X] == 'P')
			{
				SpawnActor<APlayer>()->SetActorLocation(X, Y);
			}
		}

		Y++;
	}
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
