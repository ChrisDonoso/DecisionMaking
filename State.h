#pragma once
#include "pch.h"
#include "Action.h"
#include "Transition.h"

namespace DecisionMaking
{
	class State
	{
	public:
		State();
		State(std::string name);

		void AddTransition();
		void AddTransitions();
		void Enter();
		void Exit();
		//std::shared_ptr<Action> GetEnter();
		//std::shared_ptr<Action> GetExit();
		const std::string& Name();
		//State& operator=();
		void SetEnter();
		void SetExit();
		void SetName(std::string name);
		//const std::vector<std::shared_ptr<Transition>>& Transitions();
		std::shared_ptr<State> Update();

		~State();

	private:
		//std::shared_ptr<Action> mEnter;
		//std::shared_ptr<Action> mExit;
		std::string mName;
		//std::vector<std::shared_ptr<Transition>> mTransitions;
	};
}