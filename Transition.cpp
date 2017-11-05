#include "pch.h"
#include "Transition.h"
#include "Condition.h"

namespace DecisionMaking
{
	Transition::Transition()
	{
	}

	Transition::Transition(std::shared_ptr<State> targetState, std::shared_ptr<Condition> condition)
	{
		SetTarget(targetState);
		SetCondition(condition);
	}

	std::shared_ptr<Condition> Transition::GetCondition()
	{
		return mCondition;
	}

	bool Transition::IsTriggered()
	{
		return  (*mCondition)(); // (*this);
		//return mCondition->operator();
		//return false;
	}

	void Transition::SetCondition(std::shared_ptr<Condition> condition)
	{
		mCondition = condition;
	}

	void Transition::SetTarget(std::shared_ptr<State> targetState)
	{
		mTarget = targetState;
	}

	std::shared_ptr<State> Transition::Target()
	{
		return mTarget;
	}

	//std::shared_ptr<State> Transition::Target()
	//{
	//	return std::shared_ptr<State>();
	//}


	Transition::~Transition()
	{
	}
}