#ifndef DRAWH
#define DRAWH

#include <object.h>

class Draw
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

