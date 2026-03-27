#include <iostream>
#include "Engine.h"
#include "World.h"

using namespace std;


int main()
{
	GEngine->GetWorld()->Load("Map.txt");

	GEngine->Run();

	delete GEngine;

	return 0;
}