#pragma once
#ifndef __Microwaves__
#define __Microwaves__
#include "TypeDef.h"
#include "IState.h"
#include "Countdown.h"
#include "Light.h"
#include "Waves.h"
#include <gcroot.h>
ref class IState;
ref class Countdown;

public ref class Microwaves
{
private:
	System::Windows::Forms::Label^ state;
	void showCurrentState();
	System::String^ getCurrentState();

public:
	Microwaves();

	IState^ currentState;
	Countdown^ timer;
	Light^ light;
	Wave^ waves;

	void soundBeper();

	//events
	void pushBtn();
	void openDoor();
	void closeDoor();
	void timeOut();

	//Set Callbacks Functions
	void setCallbackChangeTimer(callback^ function);
	void setCallbackChangeState(callback^ function);
	void setCallbackChangeLight(callback^ function);
	void setCallbackChangeWave(callback^ function);

	callback^ onChangeState;
};

#endif // !__Microwaves__