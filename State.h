#pragma once
#include "pch.h"
//#include "Action.h"
//#include "Transition.h"

namespace DecisionMaking
{
	class Action;
	class Transition;

	class State
	{
	public:
		const State();
		const State(std::string name);
		const State(std::string name, std::shared_ptr<Action> enter);
		const State(std::string name, std::shared_ptr<Action> enter, std::shared_ptr<Action> exit);

		void AddTransition(std::shared_ptr<Transition> transition);
		void AddTransitions();
		void Enter();
		void Exit();
		std::shared_ptr<Action> GetEnter();
		std::shared_ptr<Action> GetExit();
		const std::string& Name() const;
		//State& operator=(const State& state);
		void SetEnter(std::shared_ptr<Action> enter);
		void SetExit(std::shared_ptr<Action> exit);
		void SetName(std::string name);
		const std::vector<std::shared_ptr<Transition>>& Transitions();
		std::shared_ptr<State> Update();

		~State();

	private:
		std::shared_ptr<Action> mEnter;
		std::shared_ptr<Action> mExit;
		std::string mName;
		std::vector<std::shared_ptr<Transition>> mTransitions;
	};
}