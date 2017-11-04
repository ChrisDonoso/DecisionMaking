#include "GenericAction.h"

namespace DecisionMaking
{
	std::function<void(const State&)> mFunction;

	GenericAction::GenericAction()
	{

	}

	GenericAction::GenericAction(std::function<void(const State&)> function)
	{
		mFunction = function;
		//ActionFunction(function);
	}

	void GenericAction::operator()(const State& state)
	{
		mFunction(state);
		//(void)state;
	}

	//GenericAction & GenericAction::operator=(const GenericAction & rhs)
	//{
	//	// TODO: insert return statement here
	//}

	GenericAction::~GenericAction()
	{
	}
}