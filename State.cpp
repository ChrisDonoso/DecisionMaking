#include "pch.h"
#include "State.h"

namespace DecisionMaking
{
	State::State()
	{
	}


	State::~State()
	{
	}

	State::State(std::string name)
	{
		SetName(name);
	}

	void State::AddTransition()
	{
	}

	void State::AddTransitions()
	{
	}

	void State::Enter()
	{
	}

	void State::Exit()
	{
	}

	//std::shared_ptr<Action> State::GetEnter()
	//{
	//	return std::shared_ptr<Action>();
	//}

	//std::shared_ptr<Action> State::GetExit()
	//{
	//	return std::shared_ptr<Action>();
	//}

	const std::string & State::Name()
	{
		// TODO: insert return statement here
		return mName;
	}

	void State::SetEnter()
	{
	}

	void State::SetExit()
	{
	}

	void State::SetName(std::string name)
	{
		mName = name;
	}

	//const std::vector<std::shared_ptr<Transition>>& State::Transitions()
	//{
	//	// TODO: insert return statement here
	//}

	std::shared_ptr<State> State::Update()
	{
		return std::shared_ptr<State>();
	}
}