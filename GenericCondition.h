#pragma once
#include "pch.h"
#include "Condition.h"

namespace DecisionMaking
{
	class GenericCondition : public Condition
	{
	public:
		GenericCondition();
		/*{

		}*/

		//GenericCondition::GenericCondition(std::function<void(const State&)> function);

		//GenericCondition(T&& lambda)
		//{

		//}//std::shared_ptr<GenericCondition>)//);

		virtual bool operator()() override; // const Transition& transition) override; // const State& state) override;
		/*{

		}*/
		GenericCondition& operator=(const GenericCondition& rhs) = default;

		~GenericCondition();
		/*{

		}*/
	private:
		//std::function<void(const State&)> mFunction;
	};
}