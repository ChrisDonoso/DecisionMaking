#pragma once

#include "pch.h"
#include "Action.h"

namespace DecisionMaking
{
	class State;

	class GenericAction : public Action
	{
	public:
		GenericAction();
		GenericAction(std::function<void(const State&)> function);
		GenericAction(std::function<void()> function);

		virtual void operator()(const State& state) override;
		virtual void operator()() override;
		//GenericAction& operator=(const GenericAction& rhs) = default;

		~GenericAction();

		private:
			std::function<void(const State&)> mFunction;
			std::function<void()> mFunction2;
	};
}