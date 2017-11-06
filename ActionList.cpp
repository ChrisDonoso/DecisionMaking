#include "pch.h"
#include "ActionList.h"

namespace DecisionMaking
{
	ActionList::ActionList()
	{
	}

	std::vector<std::shared_ptr<Action>>& ActionList::Actions()
	{
		// TODO: insert return statement here
		return mActions;
	}

	void ActionList::operator()()
	{
	}


	ActionList::~ActionList()
	{
	}
}