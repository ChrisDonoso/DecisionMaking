#pragma once
#include "pch.h"

namespace DecisionMaking
{
	class Condition
	{
	public:
		Condition();

		virtual bool operator()() = 0;
		//Condition& operator=();

		virtual ~Condition() = default;
	};
}