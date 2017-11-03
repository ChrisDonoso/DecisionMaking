#include "pch.h"
#include "Transition.h"

namespace DecisionMaking
{
	Transition::Transition()
	{
	}

	std::shared_ptr<Condition> Transition::GetCondition()
	{
		return std::shared_ptr<Condition>();
	}

	bool Transition::IsTriggered()
	{
		return false;
	}

	void Transition::SetCondition()
	{

	}

	void Transition::SetTarget()
	{

	}

	//std::shared_ptr<State> Transition::Target()
	//{
	//	return std::shared_ptr<State>();
	//}


	Transition::~Transition()
	{
	}
}