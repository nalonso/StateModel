#pragma once
#ifndef __IState__
#define __IState__
#include "Microwave.h";
ref class Microwaves;

ref class IState
{
public:
	virtual void pushBtn(Microwaves^ microwave) = 0;
	virtual void openDoor(Microwaves^ microwave) = 0;
	virtual void closeDoor(Microwaves^ microwave) = 0;
	virtual void timeOut(Microwaves^ microwave) = 0;
	virtual System::String^ getName() = 0;
};

ref class IdleState : public IState
{
private:
	void setState(Microwaves^ microwave, IState^ nexState);
public:
	IdleState(Microwaves^ microwave);
	~IdleState();

	void pushBtn(Microwaves^ microwave) override;
	void openDoor(Microwaves^ microwave) override;
	void closeDoor(Microwaves^ microwave) override;
	void timeOut(Microwaves^ microwave) override;
	System::String^ getName() override;
};

ref class CookingState : public IState
{
private:
	void setState(Microwaves^ microwave, IState^ nexState);
public:
	CookingState(Microwaves^ microwave);
	~CookingState();

	void pushBtn(Microwaves^ microwave) override;
	void openDoor(Microwaves^ microwave) override;
	void closeDoor(Microwaves^ microwave) override;
	void timeOut(Microwaves^ microwave) override;
	System::String^ getName() override;
};

ref class ExtendTimeState : public IState
{
private:
	void setState(Microwaves^ microwave, IState^ nexState);
public:
	ExtendTimeState(Microwaves^ microwave);
	~ExtendTimeState();

	void pushBtn(Microwaves^ microwave) override;
	void openDoor(Microwaves^ microwave) override;
	void closeDoor(Microwaves^ microwave) override;
	void timeOut(Microwaves^ microwave) override;
	System::String^ getName() override;
};

ref class OpenDoorState : public IState
{
private:
	void setState(Microwaves^ microwave, IState^ nexState);
public:
	OpenDoorState(Microwaves^ microwave);
	~OpenDoorState();

	void pushBtn(Microwaves^ microwave) override;
	void openDoor(Microwaves^ microwave) override;
	void closeDoor(Microwaves^ microwave) override;
	void timeOut(Microwaves^ microwave) override;
	System::String^ getName() override;
};

ref class CompleteState : public IState
{
private:
	void setState(Microwaves^ microwave, IState^ nexState);
public:
	CompleteState(Microwaves^ microwave);
	~CompleteState();

	void pushBtn(Microwaves^ microwave) override;
	void openDoor(Microwaves^ microwave) override;
	void closeDoor(Microwaves^ microwave) override;
	void timeOut(Microwaves^ microwave) override;
	System::String^ getName() override;
};

#endif // !__IState__