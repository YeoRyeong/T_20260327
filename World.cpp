#include <fstream>
#include "World.h"
#include "Actor.h"

// 액터를 생성, 액터 가져오기
UWorld::UWorld()
{

}

UWorld::~UWorld()
{
	for (auto Actor : Actors)
	{
		delete Actor;
		Actor = nullptr;
	}

	Actors.clear();
}

void UWorld::Load(std::string LoadMapName)
{


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
