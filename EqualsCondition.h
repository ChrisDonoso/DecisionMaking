#pragma once

#include "pch.h"
#include "Condition.h"

namespace DecisionMaking
{
	class Transition;

	class EqualsCondition : public Condition
	{
	public:
		EqualsCondition();
		EqualsCondition(std::string direction, std::shared_ptr<std::string> command);

		virtual bool operator()() override; // const Transition& transition) override;//const State& state) override;

		EqualsCondition& operator=(const EqualsCondition& rhs) = default;

		std::string GetDirection();

		~EqualsCondition();
	private:
		std::string mDirection;
		std::shared_ptr<std::string> mCommand;
	};
}