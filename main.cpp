#include <iostream>
#include "Engine.h"
#include "World.h"

#include "SDL.h"
// 사용할 라이브러리 복사
// include 경로 추가
// lib 경로 추가
// libaray 파일 등록


// 사용할 라이브러리 파일 추가
#pragma comment(lib, "SDL2")
#pragma comment(lib, "SDL2main")

using namespace std;


int SDL_main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* MyWindow = SDL_CreateWindow("Hello", 100, 100, 640, 480, SDL_WINDOW_SHOWN); // 창 생성, title에 한글을 쓰려면 뭔가 추가해야함.

	while (true)
	{
		SDL_Event MyEvent;
		SDL_PollEvent(&MyEvent); // 가져오기만 함.

		if (MyEvent.type == SDL_QUIT)
		{
			break;
		}
	}
	SDL_DestroyWindow(MyWindow);

	SDL_Quit();

	return 0;
}


// 
// int main()
// {
// 	GEngine->GetWorld()->Load("Map.txt");
// 
// 	GEngine->Run();
// 
// 	delete GEngine;
// 
// 	return 0;
// }