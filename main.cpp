#include <iostream>
#include <string>

#include "Engine.h"
#include "World.h"

using namespace std;

void Sort(int* InData, int InLength, int (*Compare)(int A, int B))
{
	for (int FirstIndex = 0; FirstIndex < InLength; FirstIndex++)
	{
		for (int SecondIndex = 0; SecondIndex < InLength; SecondIndex++)
		{
			if (InData[FirstIndex] < InData[SecondIndex])
			{
				int Temp = InData[FirstIndex];
				InData[FirstIndex] = InData[SecondIndex];
				InData[SecondIndex] = Temp;
			}
		}
	}
	for (int i = 0; i < InLength; i++)
	{
		cout << InData[i] << " ";

	}
}

int Compare()
{
	cout << "Compare Function" << endl;
	return 0;
}

int main()
{
	cout << Compare << endl; // 주소값만 나옴.

	//함수 포인터
	int(*CompareFunction)(void); // 주소를 변수로 만듬.
	CompareFunction = Compare;

	cout << CompareFunction << endl;

	CompareFunction();

	int Data[10] = { 9, 1, 3, 5, 4, 6, 7, 8, 2, 10 };
	
	int FirstIndex = 0;
	int SecondIndex = 0;

	//Sort(Data, 10);

	return 0;
}