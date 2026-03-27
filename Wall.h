#pragma once
#include "Actor.h"
class AWall : public AActor
{
public:
	AWall(int InX, int InY, char InMesh = '*');
	virtual ~AWall();
};

