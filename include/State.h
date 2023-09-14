#pragma once

#include "Macro.h"
#include "GameResources.h"

class State
{
public:
	State() = default;
	virtual ~State() = default;

	//virtual funcs
	virtual void processManeger() = 0;
	virtual void update() = 0;
	virtual void Draw() = 0;
	//virtual void Resume() = 0;

protected:
	virtual void initilaize() = 0;

private:
};

