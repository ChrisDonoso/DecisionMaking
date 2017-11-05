#pragma once
#include "pch.h"
#include "State.h"

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
		/*void AddProperty(std::string propertyName, bool flag);
		bool GetProperty(std::string key);*/
		void AddProperty(std::string key);
		void RemoveProperty(std::string key);
		bool GetProperty(std::string);
		void SetCurrentState(std::shared_ptr<State> state);
		void SetInspecting(bool flag);
		bool Inspecting();
		const std::map<std::string, std::shared_ptr<State>>& States();
		std::shared_ptr<State> Update();

		~StateMachine();

	private:
		std::shared_ptr<State> mCurrentState;
		std::map<std::string, std::shared_ptr<State>> mStates;
		std::hash_set<std::string> mPropertyBag;
		//bool mFirstTimeEntered;
		bool mInspecting;
		//std::map<std::string, bool> mPropertyBag;
	};
}