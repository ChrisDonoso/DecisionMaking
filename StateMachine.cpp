#include "pch.h"
#include "StateMachine.h"

namespace DecisionMaking
{
	StateMachine::StateMachine()
	{
	}

	void StateMachine::AddState(std::shared_ptr<State> state)
	{
		//mStates.insert(state->Name, state);
		//mStates.insert("one", state);


		//I think it's one of these two for insertion. I think it's the make_pair, but I'm not sure.
		//http://en.cppreference.com/w/cpp/container/map/emplace


		mStates.emplace(std::make_pair(state->Name(), state));
		
		//mStates.emplace("one", state);


	}

	//void StateMachine::AddStates(std::map<std::string, std::shared_ptr<State>> states)
	//{
	//	//mStates.insert(states);
	//}

	std::shared_ptr<State> StateMachine::CurrentState()
	{
		return mCurrentState;
	}

	void StateMachine::Initialize()
	{

	}

	/*void StateMachine::AddProperty(std::string propertyName, bool flag)
	{
		mPropertyBag.emplace(propertyName, flag);
	}

	bool StateMachine::GetProperty(std::string key)
	{
		return mPropertyBag[key];
	}*/

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
		if (mCurrentState != nullptr)
		{
			mCurrentState->Exit();
		}

		mCurrentState = state;

		mCurrentState->Enter();
	}

	const std::map<std::string, std::shared_ptr<State>>& StateMachine::States()
	{
		// TODO: insert return statement here
		return mStates;
	}

	std::shared_ptr<State> StateMachine::Update()
	{
		/*assert(mCurrentState != nullptr);

		auto targetState = State::Update();

		if (targetState == nullptr)
		{
			targetState = mCurrentState->Update();

			if (targetState != nullptr)
			{
				mCurrentState->Exit();
				mCurrentState = targetState;
				mCurrentState->Enter();
			}
		}

		return targetState;*/
		return mCurrentState->Update();
		//return std::shared_ptr<State>();
	}


	StateMachine::~StateMachine()
	{
	}
}