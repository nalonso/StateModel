#include "Countdown.h"

Countdown::Countdown(Microwaves^ microwave)
{
	this->minute = 0;
	this->timer = (gcnew System::Windows::Forms::Timer);
	this->timer->Interval = 1000;
	this->timer->Tick += gcnew System::EventHandler(this, &Countdown::onTick);
	this->microwave = microwave;
}

void Countdown::setTextExternalLabel()
{
	System::String^ auxLabel = "";
	int minute = this->minute / 60;
	int seconds = this->minute - (minute * 60);
	auxLabel = (minute.ToString())->PadLeft(2, L'0') + ":" + (seconds.ToString())->PadLeft(2, L'0');
	if (this->externalLabel != nullptr)
		this->externalLabel->Text = auxLabel;
}

void Countdown::setExternalLabel(System::Windows::Forms::Label^ extLabel)
{
	this->externalLabel = extLabel;
}

void Countdown::onTick(System::Object^ obj, System::EventArgs^ event)
{
	this->setTextExternalLabel();
	if (this->minute > 0)
	{
		this->minute--;
	}
	else
	{
		this->clear();
		try
		{
			this->microwave->timeOut();
		}
		catch (const std::exception&)
		{
		}
	}
}

void Countdown::setTime()
{
	this->setTime(60);
}

void Countdown::setTime(int time)
{
	this->minute = time;
	this->setTextExternalLabel();
	this->timer->Start();
}

void Countdown::addTime()
{
	this->addTime(60);
}

void Countdown::addTime(int time)
{
	this->minute += time;
	this->setTextExternalLabel();
}

void Countdown::pause()
{
	this->timer->Stop();
}

void Countdown::clear()
{
	this->pause();
	this->minute = 0;
	this->setTextExternalLabel();
}