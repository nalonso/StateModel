#pragma once
#ifndef __Waves__
#define __Waves__

ref class IStateWave;

ref class Wave
{
private:
	System::Windows::Forms::PictureBox^ waveContainer;
public:
	Wave(System::Windows::Forms::PictureBox^ container);
	~Wave();
	IStateWave^ currentState;

	void on();
	void off();

	void setImage(System::String^ path);
};

ref class IStateWave
{
public:
	virtual void on(Wave^ wave) = 0;
	virtual void off(Wave^ wave) = 0;
	virtual System::String^ getState() = 0;
};

ref class OnWaveState : public IStateWave
{
private:
	void setState(Wave^ wave, IStateWave^ newState);
public:
	OnWaveState(Wave^ wave);
	~OnWaveState();

	void on(Wave^ wave) override;
	void off(Wave^ wave) override;
	System::String^ getState() override;
};

ref class OffWaveState : public IStateWave
{
private:
	void setState(Wave^ wave, IStateWave^ newState);
public:
	OffWaveState(Wave^ wave);
	~OffWaveState();

	void on(Wave^ wave) override;
	void off(Wave^ wave) override;
	System::String^ getState() override;
};

#endif // !__Light__