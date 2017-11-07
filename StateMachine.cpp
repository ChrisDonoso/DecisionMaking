#include "pch.h"
#include "StateMachine.h"

namespace DecisionMaking
{
	StateMachine::StateMachine()
	{
	}

	void StateMachine::AddState(std::shared_ptr<State> state)
	{	
		mStates.emplace(state->Name(), state);
	}

	void StateMachine::AddStates(std::initializer_list<std::shared_ptr<State>> states)
	{
		for (const auto& state : states)
		{
			mStates.emplace(state->Name(), state);
		}
	}

	std::shared_ptr<State> StateMachine::CurrentState()
	{
		return mCurrentState;
	}

	void StateMachine::Initialize()
	{
		mInspecting = false;
		mChase = false;
		mBacktrack = false;
		mHideSuccessful = false;
		mAttemptToHide = false;
		mDead = false;
		mFirstEncounter = true;
	}

	void StateMachine::AddProperty(std::string key)
	{
		mPropertyBag.insert(key);
	}

	void StateMachine::RemoveProperty(std::string key)
	{
		mPropertyBag.erase(key);
	}

	bool StateMachine::GetProperty(std::string key)
	{
		return mPropertyBag.find(key) != mPropertyBag.end();
	}

	void StateMachine::SetCurrentState(std::shared_ptr<State> state)
	{
		mCurrentState = state;
	}

	void StateMachine::SetInspecting(bool flag)
	{
		mInspecting = flag;
	}

	bool StateMachine::Inspecting()
	{
		return mInspecting;
	}

	void StateMachine::SetChase(bool flag)
	{
		mChase = flag;
	}

	bool StateMachine::Chase()
	{
		return mChase;
	}

	void StateMachine::SetBacktrack(bool flag)
	{
		mBacktrack = flag;
	}

	bool StateMachine::Backtrack()
	{
		return mBacktrack;
	}

	void StateMachine::SetHideSuccessful(bool flag)
	{
		mHideSuccessful = flag;
	}

	bool StateMachine::HideSuccessful()
	{
		return mHideSuccessful;
	}

	void StateMachine::SetAttemptToHide(bool flag)
	{
		mAttemptToHide = flag;
	}

	bool StateMachine::AttemptingToHide()
	{
		return mAttemptToHide;
	}

	void StateMachine::SetDead(bool flag)
	{
		mDead = flag;
	}

	bool StateMachine::Dead()
	{
		return mDead;
	}

	void StateMachine::SetFirstEncounter(bool flag)
	{
		mFirstEncounter = flag;
	}

	bool StateMachine::FirstEncounter()
	{
		return mFirstEncounter;
	}

	const std::map<std::string, std::shared_ptr<State>>& StateMachine::States()
	{
		return mStates;
	}

	std::shared_ptr<State> StateMachine::Update()
	{
		assert(mCurrentState != nullptr);

		auto targetState = State::Update();

		if (targetState == nullptr)
		{
			targetState = mCurrentState->Update();

			if (mInspecting)
			{
				mCurrentState->Inspect();
			}
			
			if (mAttemptToHide)
			{
				mCurrentState->Hide();
			}

			if (targetState != nullptr)
			{
				mCurrentState->Exit();
				mCurrentState = targetState;
				mCurrentState->Enter();
			}
		}

		return targetState;
	}


	StateMachine::~StateMachine()
	{
	}
}