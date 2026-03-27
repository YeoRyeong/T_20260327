#include <iostream>
#include "Actor.h"
#include "Engine.h"

using namespace std;

int main()
{
	UEngine* MyEngine = new UEngine;

	MyEngine->GetWorld();
	MyEngine->Run();

	delete MyEngine;
	
	return 0;
}