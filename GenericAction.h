#pragma once
#include "pch.h"
#include "Action.h"

namespace DecisionMaking
{
	class State;
	//template<typename T>
	class GenericAction : public Action
	{
	public:

		//typedef std::function<void(const State&)> ActionFunction;

		GenericAction();
		/*{

		}*/

		//ActionFunction Function() const;

		GenericAction(std::function<void(const State&)> function);
		/*{

		}*/

		/*void setFunction(ActionFunction function)
		{

		}*/

		virtual void operator()(const State& state) override;
		/*{

		}*/

		GenericAction& operator=(const GenericAction& rhs) = default;
		/*{

		};*/

		~GenericAction();
		/*{

		}*/
	};
}