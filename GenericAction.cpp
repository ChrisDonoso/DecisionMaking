#include "GenericAction.h"

namespace DecisionMaking
{
	GenericAction::GenericAction()
	{

	}

	GenericAction::GenericAction(std::function<void(const State&)> function)
	{
		mFunction = function;
	}

	void GenericAction::operator()(const State& state)
	{
		mFunction(state);
	}

	//GenericAction & GenericAction::operator=(const GenericAction & rhs)
	//{
	//	// TODO: insert return statement here
	//}

	GenericAction::~GenericAction()
	{
	}
}