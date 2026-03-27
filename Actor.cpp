#include <Windows.h>
#include <iostream>
#include "Actor.h"

AActor::AActor(int InX, int InY, char InMesh) : X(InX), Y(InY), Mesh(InMesh)
{

}

AActor::~AActor()
{

}

void AActor::BeginPlay()
{
}

void AActor::Tick()
{
}

void AActor::Render()
{
	// 콘솔화면 커서
	COORD Coordinate;
	Coordinate.X = X;
	Coordinate.Y = Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coordinate);

	std::cout << Mesh;
}

// Actor 위치 지정
void AActor::SetActorLocation(int NewX, int NewY)
{
	X = NewX;
	Y = NewY;
}
