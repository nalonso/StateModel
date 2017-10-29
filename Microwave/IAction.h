#ifndef __IAction__
#define __IAction__
#include "Microwave.h"
#pragma once
ref class Microwave;

ref class IAction
{
public:
	virtual void execute(Microwaves^ microwave) = 0;
};
#endif // !__IAction__