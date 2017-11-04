#pragma once
#include "pch.h"

namespace DecisionMaking
{
	class Action
	{
	public:
		Action();

		virtual void operator()() = 0;
		//Action& operator=();

		virtual ~Action() = default;
		
	private:
		std::string mName;
	};

}