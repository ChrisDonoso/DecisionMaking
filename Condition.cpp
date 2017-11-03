#include "pch.h"
#include "Condition.h"

namespace DecisionMaking
{

	Condition::Condition()
	{
	}

	bool Condition::operator()()
	{
		return false;
	}


	Condition::~Condition()
	{
	}
}