#pragma once

class State
{
	State() = default;
	~State() = default;

	//virtual funcs
	virtual void processManeger() = 0;
	virtual void update() = 0;
	virtual void Draw() = 0;
	//virtual void Resume() = 0;

protected:
	virtual void initilaize() = 0;

private:
};

