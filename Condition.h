#pragma once
#include "pch.h"

namespace DecisionMaking
{
	//class State;
	class Transition;

	class Condition
	{
	public:
		Condition();

		virtual bool operator()() = 0; // const Transition& transition) = 0;//const State& state) = 0;
		Condition& operator=(const Condition& rhs) = default;

		virtual ~Condition() = default;
	};
}