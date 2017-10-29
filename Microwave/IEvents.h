#ifndef __IEvents__
#define __IEvents__
#pragma once

ref class IEvents
{
public:
	virtual void pushBtn() = 0;
	virtual void openDoor() = 0;
	virtual void closeDoor() = 0;
	virtual void timeOut() = 0;
}
#endif // !__IEvents__