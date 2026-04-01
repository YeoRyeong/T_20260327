#include <iostream>
#include "Engine.h"
#include "World.h"

#include <random>

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
	// rand 보다 좀 더 좋은 난수를 얻기 위해서 사용
	std::random_device Randomdevice; // 난수를 만들어줌.
	std::mt19937 RamdomGenerator(Randomdevice());

	// 랜덤
	std::uniform_int_distribution<int>DistX(0, 640);
	std::uniform_int_distribution<int>DistY(0, 480);

	std::uniform_int_distribution<int>DistR(0, 255);
	std::uniform_int_distribution<int>DistG(0, 255);
	std::uniform_int_distribution<int>DistB(0, 255);
	std::uniform_int_distribution<int>DistA(0, 255);


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

		// CPU하는건 GPU가 할 일을 적는것 많이
		// GPU한테 보낼 명령어모음
		SDL_SetRenderDrawColor(MyRender, 192, 0, 16, 255);
		SDL_RenderClear(MyRender); // 색을 지워야함.
	
		for (int i = 0; i < 100; i++)
		{
			// 어떻게 그릴지 명령어 GPU
			// 노란색 붓 고르고
			SDL_SetRenderDrawColor(MyRender, DistR(RamdomGenerator), DistG(RamdomGenerator), 
				DistB(RamdomGenerator), DistA(RamdomGenerator));


			// 사각형 그리기
			SDL_Rect MyRect = { DistX(RamdomGenerator), DistY(RamdomGenerator), DistX(RamdomGenerator), DistY(RamdomGenerator) };
			SDL_RenderDrawRect(MyRender, &MyRect);
		}


		// 그려 CPU -> GPU
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