#pragma once
#ifndef __Microwaves__
#define __Microwaves__
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
	void setLightContainer(System::Windows::Forms::PictureBox^ extPicture);
	void setWavesContainer(System::Windows::Forms::PictureBox^ extPicture);

public:
	Microwaves(System::Windows::Forms::PictureBox ^ light, System::Windows::Forms::PictureBox ^ waves);

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

	//Auxiliar Functions
	void setTimerContainer(System::Windows::Forms::Label^ extLabel);
	void setStateContainer(System::Windows::Forms::Label^ extLabel);
};

#endif // !__Microwaves__