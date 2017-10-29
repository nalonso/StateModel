#pragma once
#ifndef __CountdownTimer__
#define __CountdownTimer__
#include "TypeDef.h"
#include "Microwave.h"
#include <gcroot.h>
#include <exception>
ref class Microwaves;

public ref class Countdown
{
private:
	Microwaves^ microwave;
	int minute;
	System::Windows::Forms::Timer^ timer;

public:
	Countdown(Microwaves^ microwave);

	void setTextExternalLabel();

	callback^ onChangeState;

	void onTick( System::Object^ obj, System::EventArgs^ event);
	void setCallback(callback^ function);

	void setTime();
	void setTime(int time);
	void addTime();
	void addTime(int time);

	void pause();

	void clear();
	
};

#endif // !__CountdownTimer__