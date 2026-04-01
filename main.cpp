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

	// 창 생성, title에 한글을 쓰려면 뭔가 추가해야함.-> 도화지
	SDL_Window* MyWindow = SDL_CreateWindow("Hello", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
	
	// GPU, 화면을 그려주려면 붓이 필요함.
	SDL_Renderer* MyRender = SDL_CreateRenderer(MyWindow, -1, 0);

	while (true)
	{
		SDL_Event MyEvent;
		SDL_PollEvent(&MyEvent); // 가져오기만 함.

		if (MyEvent.type == SDL_QUIT) 
		{
			break;
		}
		// GPU한테 보낼 명령어모음
		SDL_SetRenderDrawColor(MyRender, 192, 0, 16, 255);
		SDL_RenderClear(MyRender); // 색을 지워야함.

		SDL_RenderPresent(MyRender);
	}
	
	SDL_DestroyRenderer(MyRender);

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