#ifndef TICKABLE_H
#define TICKABLE_H

#include "dll_header.h" 


class DECLSPEC Tickable
{
public:
	bool tickEnabled()const { return tickable; }
	void enable() { tickable = true; }
	void disable() { tickable = false; }

protected:
	virtual void on_update(const float delta_time) = 0;
	virtual void on_fixed_update(const float delta_time) = 0;

private:
	bool tickable = true;
};

#endif