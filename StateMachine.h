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
		void AddStates(std::initializer_list<std::shared_ptr<State>> states);
		std::shared_ptr<State> CurrentState();
		void Initialize();
		//StateMachine& operator=();
		void AddProperty(std::string key);
		void RemoveProperty(std::string key);
		bool GetProperty(std::string);
		void SetCurrentState(std::shared_ptr<State> state);
		void SetInspecting(bool flag);
		bool Inspecting();
		void SetChase(bool flag);
		bool Chase();
		void SetBacktrack(bool flag);
		bool Backtrack();
		void SetHideSuccessful(bool flag);
		bool HideSuccessful();
		void SetAttemptToHide(bool flag);
		bool AttemptingToHide();
		void SetDead(bool flag);
		bool Dead();
		void SetFirstEncounter(bool flag);
		bool FirstEncounter();
		const std::map<std::string, std::shared_ptr<State>>& States();
		std::shared_ptr<State> Update();

		~StateMachine();

	private:
		std::shared_ptr<State> mCurrentState;
		std::map<std::string, std::shared_ptr<State>> mStates;
		std::hash_set<std::string> mPropertyBag;
		bool mInspecting;
		bool mChase;
		bool mBacktrack;
		bool mHideSuccessful;
		bool mAttemptToHide;
		bool mDead;
		bool mFirstEncounter;
	};
}