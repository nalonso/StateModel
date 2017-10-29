#include "States.h"


IdleState::IdleState()
{
	throw gcnew System::NotImplementedException();
}

void CookingState::execute(Microwaves ^ microwave)
{
	microwave->timer->setTime();
	microwave->waves->on();
	microwave->light->on();
}

void OpenDoorState::execute(Microwaves ^ microwave)
{
	microwave->timer->pause();
	microwave->waves->off();
	microwave->light->on();
}

void ExtendTimeState::execute(Microwaves ^ microwave)
{
	microwave->timer->addTime();
}

void CompleteState::execute(Microwaves ^ microwave)
{
	microwave->timer->clear();
	microwave->light->off();
	microwave->waves->off();
}
