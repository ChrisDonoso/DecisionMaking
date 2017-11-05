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
		void SetDescription(std::string description);
		const std::string& Description() const;
		void AddProperty(std::string key);
		void RemoveProperty(std::string key);
		bool GetProperty(std::string key);
		const std::vector<std::shared_ptr<Transition>>& Transitions();
		std::shared_ptr<State> Update();

		~State();

	private:
		std::shared_ptr<Action> mEnter;
		std::shared_ptr<Action> mExit;
		std::string mName;
		std::string mDescription;
		std::vector<std::shared_ptr<Transition>> mTransitions;
		//std::unordered_set<std::
		std::hash_set<std::string> mPropertyBag;
		//std::map<std::string, bool> mPropertyBag;
	};
}