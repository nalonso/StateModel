#include "Waves.h"

Wave::Wave()
{
	this->currentState = (gcnew OffWaveState(this));
}

Wave::~Wave()
{
}

void Wave::on()
{
		this->currentState->on(this);
}

void Wave::off()
{
		this->currentState->off(this);
}

void Wave::setCallback(callback^ function)
{
	this->onChangeState = function;
}

void OnWaveState::setState(Wave ^ wave, IStateWave ^ newState)
{
	IStateWave^ aux = wave->currentState;
	wave->currentState = newState;
	delete aux;
}

OnWaveState::OnWaveState(Wave ^ wave)
{
	if (wave->onChangeState != nullptr)
		wave->onChangeState(L"C:\\Personal\\Microwaves\\Microwave\\Microwave\\Resource\\microwavesOn.gif");
}

OnWaveState::~OnWaveState()
{
}

void OnWaveState::on(Wave ^ wave)
{
}

void OnWaveState::off(Wave ^ wave)
{
	this->setState(wave, gcnew OffWaveState(wave));
}

System::String ^ OnWaveState::getState()
{
	return L"On";
}

void OffWaveState::setState(Wave ^ wave, IStateWave ^ newState)
{
	IStateWave^ aux = wave->currentState;
	wave->currentState = newState;
	delete aux;
}

OffWaveState::OffWaveState(Wave ^ wave)
{
	if (wave->onChangeState != nullptr)
		wave->onChangeState(L"C:\\Personal\\Microwaves\\Microwave\\Microwave\\Resource\\microwavesOff.gif");
}

OffWaveState::~OffWaveState()
{
}

void OffWaveState::on(Wave ^ wave)
{
	this->setState(wave, gcnew OnWaveState(wave));
}

void OffWaveState::off(Wave ^ wave)
{
}

System::String ^ OffWaveState::getState()
{
	return L"Off";
}
