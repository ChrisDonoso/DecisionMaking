#pragma once
#include "State.h"
#include "pch.h"

namespace DecisionMaking
{
	class StateMachine : public State
	{
	public:
		StateMachine();

		void AddState(std::shared_ptr<State> state);
		void AddStates(std::map<std::string, std::shared_ptr<State>> states);
		std::shared_ptr<State> CurrentState();
		void Initialize();
		//StateMachine& operator=();
		void SetCurrentState(std::shared_ptr<State> state);
		const std::map<std::string, std::shared_ptr<State>>& States();
		std::shared_ptr<State> Update();

		~StateMachine();

	private:
		std::shared_ptr<State> mCurrentState;
		std::map<std::string, std::shared_ptr<State>> mStates;
	};
}