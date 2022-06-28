#ifndef DRAW_H
#define DRAW_H

#include "object.h"
#include "dll_header.h"

class DECLSPEC Draw
{
	friend class Application;

public:
	Draw(const bool cDraw = true) {
		this->canDraw = cDraw;
	}

protected:
	virtual void drawn() = 0;
	
	bool canDraw;
};
#endif // !DRAWH

