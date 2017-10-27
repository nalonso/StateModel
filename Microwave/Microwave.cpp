#include "Microwave.h"

void Microwaves::showCurrentState()
{
	this->state->Text = this->getCurrentState();
}

Microwaves::Microwaves(System::Windows::Forms::PictureBox ^ light, System::Windows::Forms::PictureBox ^ waves)
{
	this->setLightContainer(light);
	this->setWavesContainer(waves);
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

void Microwaves::setTimerContainer(System::Windows::Forms::Label ^ extLabel)
{
	this->timer->setExternalLabel(extLabel);
}

void Microwaves::setStateContainer(System::Windows::Forms::Label ^ extLabel)
{
	this->state = extLabel;
	this->showCurrentState();
}

void Microwaves::setLightContainer(System::Windows::Forms::PictureBox ^ extPicture)
{
	this->light = (gcnew Light(extPicture));
}

void Microwaves::setWavesContainer(System::Windows::Forms::PictureBox ^ extPicture)
{
	this->waves = (gcnew Wave(extPicture));
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
