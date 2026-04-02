#include "Actor.h"
#include "Engine.h"
#include <iostream>
#include <Windows.h>

AActor::AActor(int InX, int InY, char InMesh) : X(InX), Y(InY), Mesh(InMesh)
{
    R = 0;
    G = 0;
    B = 0;
    //SDL_Surface* My
}

AActor::~AActor()
{
    // 캡쳐 로딩하는 기능
    SDL_FreeSurface(Image); 
    SDL_DestroyTexture(Texture);

}

void AActor::BeginPlay()
{

}

void AActor::Tick()
{

}

void AActor::Render()
{
    //COORD Coordinate;
    //Coordinate.X = X;
    //Coordinate.Y = Y;
    //SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coordinate);

    //std::cout << Mesh;
    //GEngine->Render(X, Y, R, G, B); // 

    GEngine->Render(X, Y, Texture); // texture 이미지 그리기 

}

void AActor::SetActorLocation(int NewX, int NewY)
{
    X = NewX;
    Y = NewY;
}

void AActor::Load(std::string Filename)
{
    Image = SDL_LoadBMP(Filename.c_str()); 

    // SDL_MapRGB(Image->format, 255,255,255) 해당 색상을 RGP에 저장하지않음.
    // 투명으로 저장
    SDL_SetColorKey(Image,SDL_TRUE, SDL_MapRGB(Image->format, 255,255,255)); 

    Texture = SDL_CreateTextureFromSurface(GEngine->GetRenderer(), Image); // GPU에 넘겨줌
}