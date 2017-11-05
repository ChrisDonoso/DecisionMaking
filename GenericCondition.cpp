#include "GenericCondition.h"

namespace DecisionMaking
{
	GenericCondition::GenericCondition()
	{
	}

	/*GenericCondition::GenericCondition(std::function<void(const State&)> function)
	{
		mFunction = function;
	}*/
	/*GenericCondition::GenericCondition(std::shared_ptr<GenericCondition>)
	{
	}*/

	bool GenericCondition::operator()()//const Transition& transition)
	{
		//(void)transition;
		return false;
	}

	//GenericCondition& GenericCondition::operator=(const GenericCondition & rhs)
	//{
	//	// TODO: insert return statement here
	//}

	GenericCondition::~GenericCondition()
	{
	}
}