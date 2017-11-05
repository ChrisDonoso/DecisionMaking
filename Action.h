#pragma once
#include "pch.h"

namespace DecisionMaking
{
	class State;

	class Action
	{
	public:
		Action();

		virtual void operator()(const State& state) = 0;
		//Action& operator=(const State& state) = default;

		virtual ~Action() = default;
		
	private:
		std::string mName;
	};

}