#include <iostream>
#include "Engine.h"
#include "World.h"

using namespace std;

//typedef unsigned char byte;
using byte = unsigned char; // 8bit
using uint64 = unsigned long long;

int SDL_main(int argc, char* argv[])
{


    GEngine->GetWorld()->Load("Map.txt");
    
    GEngine->Run();
    
    delete GEngine;
    

	return 0;
}