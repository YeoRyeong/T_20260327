#pragma once
#include "Actor.h"
class AGoal : public AActor
{
public:
	AGoal(int InX = 5, int InY = 5, char InMesh = 'G');
	virtual ~AGoal();
};

