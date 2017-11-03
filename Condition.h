#pragma once
#include "pch.h"

namespace DecisionMaking
{
	class Condition
	{
	public:
		Condition();

		bool operator()();
		//Condition& operator=();

		~Condition();
	};
}