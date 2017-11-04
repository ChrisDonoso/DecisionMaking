#pragma once
#include "pch.h"
#include "Action.h"

namespace DecisionMaking
{
	class GenericAction : public Action
	{
	public:
		GenericAction();

		virtual void operator()() override;
		GenericAction& operator=(const GenericAction& rhs) = default;

		~GenericAction();
	};
}