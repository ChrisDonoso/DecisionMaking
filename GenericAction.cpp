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

	GenericAction::GenericAction(std::function<void()> function)
	{
		mFunction2 = function;
	}

	void GenericAction::operator()(const State& state)
	{
		mFunction(state);
	}

	void GenericAction::operator()()
	{
		mFunction2();
	}

	//GenericAction & GenericAction::operator=(const GenericAction & rhs)
	//{
	//	// TODO: insert return statement here
	//}

	GenericAction::~GenericAction()
	{
	}
}