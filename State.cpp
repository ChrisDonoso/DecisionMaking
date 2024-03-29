#include "pch.h"
#include "State.h"
#include "Action.h"
#include "Transition.h"

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

	void State::Inspect()
	{
		if (mInspect != nullptr)
		{
			(*mInspect)(*this);
		}
	}

	void State::Hide()
	{
		if (mHide != nullptr)
		{
			(*mHide)();
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

	std::shared_ptr<Action> State::GetInspect()
	{
		return mInspect;
	}

	std::shared_ptr<Action> State::GetHide()
	{
		return mHide;
	}

	const std::string & State::Name() const
	{
		return mName;
	}

	//State & State::operator=(const State& state)
	//{
	//	// TODO: insert return statement here
	//}

	void State::SetEnter(std::shared_ptr<Action> enter)
	{
		mEnter = enter;
	}

	void State::SetExit(std::shared_ptr<Action> exit)
	{
		mExit = exit;
	}

	void State::SetInspect(std::shared_ptr<Action> inspect)
	{
		mInspect = inspect;
	}

	void State::SetHide(std::shared_ptr<Action> hide)
	{
		mHide = hide;
	}

	void State::SetName(std::string name)
	{
		mName = name;
	}

	void State::SetDescription(std::string description)
	{
		mDescription = description;
	}

	const std::string & State::Description() const
	{
		return mDescription;
	}

	void State::SetInspectionDescription(std::string inspection)
	{
		mInspectDescription = inspection;
	}

	const std::string & State::InspectionDescription() const
	{
		return mInspectDescription;
	}

	void State::SetFirstTimeEntered(bool flag)
	{
		mFirstTimeEntered = flag;
	}

	const bool& State::FirstTimeEntered() const
	{
		return mFirstTimeEntered;
	}

	void State::AddProperty(std::string key)
	{
		mPropertyBag.insert(key);
	}

	void State::RemoveProperty(std::string key)
	{
		mPropertyBag.erase(key);
	}

	bool State::GetProperty(std::string key)
	{
		return mPropertyBag.find(key) != mPropertyBag.end();
	}

	const std::vector<std::shared_ptr<Transition>>& State::Transitions()
	{
		return mTransitions;
	}

	std::shared_ptr<State> State::Update()
	{
		for (const auto& transition : mTransitions)
		{
			if (transition->IsTriggered())
			{
				return transition->Target();
			}
		}

		return nullptr;
	}
}