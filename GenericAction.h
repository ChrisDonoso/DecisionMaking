#pragma once
#include "pch.h"
#include "Action.h"

namespace DecisionMaking
{
	template<typename T>
	class GenericAction : public Action
	{
	public:
		GenericAction()
		{

		}

		GenericAction(std::function<void(const State&)>)
		{

		}

		virtual void operator()() override
		{

		}

		GenericAction& operator=(const GenericAction& rhs) = default
		{

		};

		~GenericAction()
		{

		}
	};
}