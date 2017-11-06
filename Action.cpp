#include "pch.h"
#include "Action.h"

namespace DecisionMaking
{
	Action::Action()
	{
	}

	void Action::SetName(std::string name)
	{
		mName = name;
	}

	std::string Action::GetName()
	{
		return mName;
	}

	/*Action::Action(std::string name)
	{
		mName = name;
	}*/

	/*void Action::operator()(const State& state)
	{
		(void)state;
	}*/

	//Action& Action::operator=(const State& state)
	//{
	//	(void)state;
	//	// TODO: insert return statement here
	//	return 
	//}



	/*Action::~Action()
	{
	}*/
}