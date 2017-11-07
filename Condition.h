#pragma once
#include "pch.h"

namespace DecisionMaking
{
	class Transition;

	class Condition
	{
	public:
		Condition();

		virtual bool operator()() = 0;
		Condition& operator=(const Condition& rhs) = default;

		virtual ~Condition() = default;
	};
}