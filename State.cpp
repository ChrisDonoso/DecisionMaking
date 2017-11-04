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

	State::State(std::string name, std::shared_ptr<Action> enter, std::shared_ptr<Action> exit)
	{
		SetName(name);
		mEnter = enter;
		mExit = exit;
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

	std::shared_ptr<Action> State::GetEnter()
	{
		return mEnter;
	}

	std::shared_ptr<Action> State::GetExit()
	{
		return mExit;
	}

	const std::string & State::Name() const
	{
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

	const std::vector<std::shared_ptr<Transition>>& State::Transitions()
	{
		return mTransitions;
	}

	std::shared_ptr<State> State::Update()
	{
		return std::shared_ptr<State>();
	}
}