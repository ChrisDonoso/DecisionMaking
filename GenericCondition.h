#pragma once
#include "pch.h"
#include "Condition.h"

namespace DecisionMaking
{
	class GenericCondition : public Condition
	{
	public:
		GenericCondition();

		virtual bool operator()() override;
		//GenericCondition& operator=(const GenericCondition& rhs) = default;

		~GenericCondition();
	};
}