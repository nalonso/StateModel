#pragma once
#ifndef __Light__
#define __Light__
#include "TypeDef.h"

ref class IStateLight;

ref class Light
{
private:
public:
	Light();
	~Light();
	IStateLight^ currentState;
	callback^ onChangeState;

	void on();
	void off();

	void setCallback(callback^ function);
};

ref class IStateLight
{
public:
	virtual void on(Light^ light) = 0;
	virtual void off(Light^ light) = 0;
	virtual System::String^ getState() = 0;
};

ref class OnLightState : public IStateLight
{
private:
	void setState(Light^ light, IStateLight^ newState);
public:
	OnLightState(Light^ light);
	~OnLightState();

	void on(Light^ light) override;
	void off(Light^ light) override;
	System::String^ getState() override;
};

ref class OffLightState : public IStateLight
{
private:
	void setState(Light^ light, IStateLight^ newState);
public:
	OffLightState(Light^ light);
	~OffLightState();

	void on(Light^ light) override;
	void off(Light^ light) override;
	System::String^ getState() override;
};

#endif // !__Light__