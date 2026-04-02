#include <iostream>
#include "Engine.h"
#include "World.h"

using namespace std;

//typedef unsigned char byte;
using byte = unsigned char; // 8bit

int main()
{
    //byte Number1 = 3; // 0000 0011
    //byte Number2 = 3; // 0000 0011
    //byte Number3 = 5; // 0000 0101
    //byte Number4 = 7; // 0000 0111
    int InputN = 0;
    int N = 0;

    cin >> InputN;


  
    for (int i = 0; i < InputN; i++)
    {
        cin >> N;
    
        
    }

    return 0;
}
// 4 = 4 ^ 8 ^ 8
// 0000 0100    4
// 0000 1000    8
// 0000 1100    4 ^ 8
// 0000 1000    8
// 0000 0100    4 ^ 8 ^ 8

// 3 0000 1100
// 5 0000 0101
// 7 0000 0111


/*
int SDL_main(int argc, char* argv[])
{
    // bit masking
    // 0000 0001 | 0000 0010
    byte Number1 = SDL_RENDERER_SOFTWARE | SDL_RENDERER_ACCELERATED;
    // 0000 0011

    // 0000 0011
    // 0000 0001 AND
    // 0000 0001
    if (Number1 & SDL_RENDERER_SOFTWARE)
    {

    }

    // 0000 0001
    // 0000 0010 AND
    // 0000 0010
    if (Number1 & SDL_RENDERER_ACCELERATED)
    {

    }


    //GEngine->GetWorld()->Load("Map.txt");
    //
    //GEngine->Run();
    //
    //delete GEngine;
    

	return 0;
}

*/