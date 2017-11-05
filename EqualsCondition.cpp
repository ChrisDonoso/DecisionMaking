#include "EqualsCondition.h"

namespace DecisionMaking
{
	EqualsCondition::EqualsCondition()
	{
	}

	EqualsCondition::EqualsCondition(std::string direction, std::shared_ptr<std::string> command)
	{
		mDirection = direction;
		mCommand = command;
	}

	bool EqualsCondition::operator()()//const Transition& transition)//const State & state)
	{
		if (mDirection.compare(*mCommand) == 0)
		{
			return true;
		}
		//(void)transition;
		return false;
		//return mDirection// = *mCommand;
		/*(void)transition;
		return false;*/
	}


	std::string EqualsCondition::GetDirection()
	{
		return mDirection;
	}

	EqualsCondition::~EqualsCondition()
	{

	}
}