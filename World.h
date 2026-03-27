#pragma once
#include <vector>
#include <string>

class AActor;

class UWorld
{
public:
	UWorld();
	virtual ~UWorld();

	// Actor 생성
	template <typename T> // 아무 타입이나 가능하게 
	AActor* SpawnActor()
	{
		AActor* NewActor = new T;
		Actors.push_back(NewActor); // 동적으로 배열을 늘려서 해당 배열에 Actor를 보관

		return NewActor;
	}

	void Load(std::string LoadMapName); // 맵 불러오기

	// 반환한 Actor에 vecter를 가져옴
	inline std::vector<class AActor*>& GetActors() 
	{
		return Actors;
	}

	void Tick();

	void Render();

protected:
	// Actors 멤버 변수의 복사본이 아닌 실제 메모리 주소를 반환
	std::vector<class AActor*> Actors;
};

