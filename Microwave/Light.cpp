#include "Light.h"

Light::Light(System::Windows::Forms::PictureBox ^ container)
{
	this->lightContainer = container;
	this->currentState = (gcnew OffLightState(this));
}

Light::~Light()
{
}

void Light::on()
{
	this->currentState->on(this);
}

void Light::off()
{
	this->currentState->off(this);
}

void Light::setImage(System::String ^ path)
{
	this->lightContainer->ImageLocation = path;
}

void OnLightState::setState(Light ^ light, IStateLight ^ newState)
{
	IStateLight^ aux = light->currentState;
	light->currentState = newState;
	delete aux;
}

OnLightState::OnLightState(Light ^ light)
{
	light->setImage(L"C:\\Personal\\Microwaves\\Microwave\\Microwave\\Resource\\lightOn.jpg");
}

OnLightState::~OnLightState()
{
}

void OnLightState::on(Light ^ light)
{
}

void OnLightState::off(Light ^ light)
{
	this->setState(light, gcnew OffLightState(light));
}

System::String ^ OnLightState::getState()
{
	return L"On";
}

void OffLightState::setState(Light ^ light, IStateLight ^ newState)
{
	IStateLight^ aux = light->currentState;
	light->currentState = newState;
	delete aux;
}

OffLightState::OffLightState(Light ^ light)
{
	light->setImage(L"C:\\Personal\\Microwaves\\Microwave\\Microwave\\Resource\\lightOff.jpg");
}

OffLightState::~OffLightState()
{
}

void OffLightState::on(Light ^ light)
{
	this->setState(light, gcnew OnLightState(light));
}

void OffLightState::off(Light ^ light)
{
}

System::String ^ OffLightState::getState()
{
	return L"Off";
}
