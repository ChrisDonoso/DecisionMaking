#pragma once
#include "State.h"
#include "pch.h"

namespace DecisionMaking
{
	class StateMachine : public State
	{
	public:
		StateMachine();

		void AddState();
		void AddStates();
		std::shared_ptr<State> CurrentState();
		void Initialize();
		//StateMachine& operator=();
		void SetCurrentState();
		const std::map<std::string, std::shared_ptr<State>>& States();
		std::shared_ptr<State> Update();

		~StateMachine();

	private:
		std::shared_ptr<State> mCurrentState;
		std::map<std::string, std::shared_ptr<State>> mStates;
	};
}