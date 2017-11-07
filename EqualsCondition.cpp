#include "pch.h"
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

	bool EqualsCondition::operator()()
	{
		if (mDirection.compare(*mCommand) == 0)
		{
			return true;
		}

		return false;
	}


	std::string EqualsCondition::GetDirection()
	{
		return mDirection;
	}

	EqualsCondition::~EqualsCondition()
	{
	}
}