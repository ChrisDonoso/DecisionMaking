#pragma once
#include "pch.h"
#include "Condition.h"

namespace DecisionMaking
{
	template<typename T>
	class GenericCondition : public Condition
	{
	public:
		GenericCondition()
		{

		}

		GenericCondition(T&& lambda)
		{

		}//std::shared_ptr<GenericCondition>)//);

		virtual bool operator()() override
		{

		}
		//GenericCondition& operator=(const GenericCondition& rhs) = default;

		~GenericCondition()
		{

		}
	};
}