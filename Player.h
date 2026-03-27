#pragma once
#include "Actor.h"
class APlayer : public AActor
{
public:
	APlayer();
	virtual ~APlayer();

	virtual void Tick();
	virtual void Term();
	virtual void Render();
};

