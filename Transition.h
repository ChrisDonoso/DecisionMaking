#pragma once
#include "pch.h"
#include "Condition.h"
#include "State.h"

namespace DecisionMaking
{
	class Transition
	{
	public:
		Transition();

		std::shared_ptr<Condition> GetCondition();
		bool IsTriggered();
		//Transition& operator=();
		void SetCondition();
		void SetTarget();
		std::shared_ptr<State> Target();

		~Transition();
		
	private:
		std::shared_ptr<Condition> mCondition;
		std::shared_ptr<State> mTarget;
	};
}