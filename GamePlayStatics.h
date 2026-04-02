#pragma once
#include "Engine.h"

class UGamePlayStatics
{
public:
	UGamePlayStatics();
	virtual ~UGamePlayStatics();

	inline static float GetWorldDeltaSecondes()
	{
		return GEngine->GetDeltaSeconds();
	}
};

