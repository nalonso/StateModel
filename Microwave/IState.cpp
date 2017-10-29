#include "IState.h"

/*================ IdleState ================*/
void IdleState::setState(Microwaves^ microwave, IState^ nexState)
{
	IState^ aux = microwave->currentState;
	microwave->currentState = nexState;
	delete aux;
}

IdleState::IdleState(Microwaves^ microwave)
{
	if(microwave->onChangeState != nullptr)
		microwave->onChangeState(this->getName());
	microwave->timer->clear();
	microwave->waves->off();
	microwave->light->off();
}

IdleState::~IdleState()
{
}

void IdleState::pushBtn(Microwaves^ microwave)
{
	this->setState(microwave, gcnew CookingState(microwave));
}

void IdleState::openDoor(Microwaves ^ microwave)
{
	this->setState(microwave, gcnew OpenDoorState(microwave));
}

void IdleState::closeDoor(Microwaves ^ microwave)
{
}

void IdleState::timeOut(Microwaves ^ microwave)
{
}

System::String ^ IdleState::getName()
{
	return "Idle";
}

/*================ CookingState ================*/
void CookingState::setState(Microwaves^ microwave, IState^ nexState)
{
	IState^ aux = microwave->currentState;
	microwave->currentState = nexState;
	delete aux;
}

CookingState::CookingState(Microwaves^ microwave)
{
	if (microwave->onChangeState != nullptr)
	 microwave->onChangeState(this->getName());
	microwave->timer->setTime();
	microwave->light->on();
	microwave->waves->on();
}

CookingState::~CookingState()
{
}

void CookingState::pushBtn(Microwaves^ microwave)
{
	this->setState(microwave, gcnew ExtendTimeState(microwave));
}

void CookingState::openDoor(Microwaves ^ microwave)
{
	this->setState(microwave, gcnew OpenDoorState(microwave));
}

void CookingState::closeDoor(Microwaves ^ microwave)
{
}

void CookingState::timeOut(Microwaves ^ microwave)
{
	this->setState(microwave, gcnew CompleteState(microwave));
}

System::String ^ CookingState::getName()
{
	return "Cooking";
}

/*================ ExtendTimeState ================*/
void ExtendTimeState::setState(Microwaves^ microwave, IState^ nexState)
{
	IState^ aux = microwave->currentState;
	microwave->currentState = nexState;
	delete aux;
}

ExtendTimeState::ExtendTimeState(Microwaves^ microwave)
{
	if (microwave->onChangeState != nullptr)
		microwave->onChangeState(this->getName());
	microwave->timer->addTime();
}

ExtendTimeState::~ExtendTimeState()
{
}

void ExtendTimeState::pushBtn(Microwaves^ microwave)
{
	this->setState(microwave, gcnew ExtendTimeState(microwave));
}

void ExtendTimeState::openDoor(Microwaves ^ microwave)
{
	this->setState(microwave, gcnew OpenDoorState(microwave));
}

void ExtendTimeState::closeDoor(Microwaves ^ microwave)
{
}

void ExtendTimeState::timeOut(Microwaves ^ microwave)
{
	this->setState(microwave, gcnew CompleteState(microwave));
}

System::String ^ ExtendTimeState::getName()
{
	return "ExtendTime";
}

/*================ OpenDoorState ================*/
void OpenDoorState::setState(Microwaves^ microwave, IState^ nexState)
{
	IState^ aux = microwave->currentState;
	microwave->currentState = nexState;
	delete aux;
}

OpenDoorState::OpenDoorState(Microwaves^ microwave)
{
	if (microwave->onChangeState != nullptr)
		microwave->onChangeState(this->getName());
	microwave->timer->pause();
	microwave->light->on();
	microwave->waves->off();
}

OpenDoorState::~OpenDoorState()
{
}

void OpenDoorState::pushBtn(Microwaves^ microwave)
{
}

void OpenDoorState::openDoor(Microwaves ^ microwave)
{
}

void OpenDoorState::closeDoor(Microwaves ^ microwave)
{
	this->setState(microwave, gcnew IdleState(microwave));
}

void OpenDoorState::timeOut(Microwaves ^ microwave)
{
}

System::String ^ OpenDoorState::getName()
{
	return "OpenDoor";
}

/*================ CompleteState ================*/
void CompleteState::setState(Microwaves^ microwave, IState^ nexState)
{
	IState^ aux = microwave->currentState;
	microwave->currentState = nexState;
	delete aux;
}

CompleteState::CompleteState(Microwaves^ microwave)
{
	if (microwave->onChangeState != nullptr)
		microwave->onChangeState(this->getName());
	microwave->timer->clear();
	microwave->light->off();
	microwave->waves->off();
}

CompleteState::~CompleteState()
{
}

void CompleteState::pushBtn(Microwaves^ microwave)
{
}

void CompleteState::openDoor(Microwaves ^ microwave)
{
	this->setState(microwave, gcnew OpenDoorState(microwave));
}

void CompleteState::closeDoor(Microwaves ^ microwave)
{
}

void CompleteState::timeOut(Microwaves ^ microwave)
{
}

System::String ^ CompleteState::getName()
{
	return "Complete";
}
