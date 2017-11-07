#pragma once
#include "pch.h"

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
		void Inspect();
		void Hide();
		std::shared_ptr<Action> GetEnter();
		std::shared_ptr<Action> GetExit();
		std::shared_ptr<Action> GetInspect();
		std::shared_ptr<Action> GetHide();
		const std::string& Name() const;
		//State& operator=(const State& state);
		void SetEnter(std::shared_ptr<Action> enter);
		void SetExit(std::shared_ptr<Action> exit);
		void SetInspect(std::shared_ptr<Action> inspect);
		void SetHide(std::shared_ptr<Action> hide);
		void SetName(std::string name);
		void SetDescription(std::string description);
		const std::string& Description() const;
		void SetInspectionDescription(std::string inspection);
		const std::string& InspectionDescription() const;
		void SetFirstTimeEntered(bool flag);
		const bool& FirstTimeEntered() const;
		void AddProperty(std::string key);
		void RemoveProperty(std::string key);
		bool GetProperty(std::string key);
		const std::vector<std::shared_ptr<Transition>>& Transitions();
		std::shared_ptr<State> Update();

		~State();

	private:
		std::shared_ptr<Action> mEnter;
		std::shared_ptr<Action> mExit;
		std::shared_ptr<Action> mInspect;
		std::shared_ptr<Action> mHide;
		std::string mName;
		std::string mDescription;
		std::string mInspectDescription;
		std::vector<std::shared_ptr<Transition>> mTransitions;
		std::hash_set<std::string> mPropertyBag;
		bool mFirstTimeEntered;
	};
}