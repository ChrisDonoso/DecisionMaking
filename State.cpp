#include "pch.h"
#include "State.h"
#include "Action.h"

namespace DecisionMaking
{
	State::State()
	{
	}

	State::State(std::string name)
	{
		SetName(name);
	}

	State::State(std::string name, std::shared_ptr<Action> enter)
	{
		SetName(name);
		mEnter = enter;
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

	void State::AddTransition(std::shared_ptr<Transition> transition)
	{
		//mTransitions.insert(transition);
		//mStates.emplace(std::make_pair(state->Name(), state));
		mTransitions.push_back(transition);
	}

	void State::AddTransitions()
	{
	}

	void State::Enter()
	{
		if (mEnter != nullptr)
		{
			(*mEnter)(*this);
		}
	}

	void State::Exit()
	{
		if (mExit != nullptr)
		{
			(*mExit)(*this);
		}
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

	//State & State::operator=(const State& state)
	//{
	//	//(void)state;
	//		//State target = state;
	//	// TODO: insert return statement here
	//	//return state;
	//}

	void State::SetEnter(std::shared_ptr<Action> enter)
	{
		mEnter = enter;
	}

	void State::SetExit(std::shared_ptr<Action> exit)
	{
		mExit = exit;
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