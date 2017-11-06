#pragma once
#include "pch.h"

namespace DecisionMaking
{
	class State;

	class Action
	{
	public:
		Action();
		//Action(std::string name);

		virtual void operator()(const State& state) = 0;
		virtual void operator()() = 0;

		void SetName(std::string name);
		std::string GetName();
		//virtual bool operator()() = 0;
		//Action& operator=(const State& state) = default;

		virtual ~Action() = default;
		
	private:
		std::string mName;
	};

}