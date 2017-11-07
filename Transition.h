#pragma once
#include "pch.h"

namespace DecisionMaking
{
	class State;
	class Condition;

	class Transition
	{
	public:
		Transition();
		Transition(std::shared_ptr<State> targetState, std::shared_ptr<Condition> condition);

		std::shared_ptr<Condition> GetCondition();
		bool IsTriggered();
		////Transition& operator=();
		void SetCondition(std::shared_ptr<Condition> condition);
		void SetTarget(std::shared_ptr<State> targetState);
		std::shared_ptr<State> Target();

		~Transition();
		
	private:
		std::shared_ptr<Condition> mCondition;
		std::shared_ptr<State> mTarget;
	};
}