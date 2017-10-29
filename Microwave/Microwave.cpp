#include "Microwave.h"

void Microwaves::showCurrentState()
{
	this->onChangeState (this->getCurrentState());
}

Microwaves::Microwaves()
{
	this->light = (gcnew Light());
	this->waves = (gcnew Wave());
	this->timer = (gcnew Countdown(this));
	this->currentState = (gcnew IdleState(this));
}

void Microwaves::soundBeper()
{
}

System::String^ Microwaves::getCurrentState()
{
	return currentState->getName();
}

void Microwaves::pushBtn()
{
	this->currentState->pushBtn(this);
	this->showCurrentState();
}

void Microwaves::openDoor()
{
	this->currentState->openDoor(this);
	this->showCurrentState();
}

void Microwaves::closeDoor()
{
	this->currentState->closeDoor(this);
	this->showCurrentState();
}

void Microwaves::timeOut()
{
	this->currentState->timeOut(this);
	this->showCurrentState();
}

void Microwaves::setCallbackChangeTimer(callback^ function)
{
	this->timer->setCallback(function);
}

void Microwaves::setCallbackChangeState(callback^ function)
{
	this->onChangeState = function;
}

void Microwaves::setCallbackChangeLight(callback^ function)
{
	this->light->setCallback(function);
}

void Microwaves::setCallbackChangeWave(callback^ function)
{
	this->waves->setCallback(function);
}
