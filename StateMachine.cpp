#include "pch.h"
#include "StateMachine.h"

namespace DecisionMaking
{
	StateMachine::StateMachine()
	{
	}

	void StateMachine::AddState(std::shared_ptr<State> state)
	{
		//mStates.insert("one", state);
	}

	void StateMachine::AddStates(std::map<std::string, std::shared_ptr<State>> states)
	{
		states.
	}

	std::shared_ptr<State> StateMachine::CurrentState()
	{
		return std::shared_ptr<State>();
	}

	void StateMachine::Initialize()
	{
	}

	void StateMachine::SetCurrentState()
	{
	}

	const std::map<std::string, std::shared_ptr<State>>& StateMachine::States()
	{
		// TODO: insert return statement here
		return mStates;
	}

	std::shared_ptr<State> StateMachine::Update()
	{
		return std::shared_ptr<State>();
	}


	StateMachine::~StateMachine()
	{
	}
}