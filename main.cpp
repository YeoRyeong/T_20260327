#include <iostream>

#include "Actor.h"
#include "Engine.h"
#include "World.h"
#include "Player.h"
#include "Monster.h"

#include <fstream>
using namespace std;

int main()
{
	UEngine* MyEngine = UEngine::GetInstance();

	MyEngine->GetInstance();
	MyEngine->GetWorld()->Load("Map.txt");
	MyEngine->Run();

	delete MyEngine;
	
	return 0;
}