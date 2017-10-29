#ifndef __States__
#define __States__
#pragma once
#include "IAction.h"
#include "Microwave.h"

//======================= Status: Idle
ref class IdleState
{
public:
	IdleState();

	IAction EntryAction;
	IAction Action;
	IAction ExitAction;
};

//======================= Status: Cooking
ref class CookingState : public IAction
{
public:
	void execute(Microwaves^ microwave) override;
};

//======================= Status: OpenDoor
ref class OpenDoorState : public IAction
{
public:
	void execute(Microwaves^ microwave) override;
};

//======================= Status: ExtendTime
ref class ExtendTimeState : public IAction
{
public:
	void execute(Microwaves^ microwave) override;
};

//======================= Status: Complete
ref class CompleteState : public IAction
{
public:
	void execute(Microwaves^ microwave) override;
};


#endif // !__States__