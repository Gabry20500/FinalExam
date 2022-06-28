#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include "dll_header.h" 

class DECLSPEC Object
{
public:
	Object(const std::string user_Name, bool active = true);


	void activate() { isActive = true; }
	void deactivate() { isActive = false; };
	bool has_activity()const { return isActive; }
	std::string get_name()const { return userName; }
	
	bool isActive;
protected:
	
	std::string userName;
};

#endif

