#include "GenericCondition.h"

namespace DecisionMaking
{
	GenericCondition::GenericCondition()
	{
	}

	bool GenericCondition::operator()()
	{
		return false;
	}

	GenericCondition::~GenericCondition()
	{
	}
}