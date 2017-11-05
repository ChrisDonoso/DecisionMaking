// DecisionMaking.cpp : Defines the entry point for the console application.
//

#include "pch.h"
//#include "DecisionMaking.h">

#include "StateMachine.h"
#include "State.h"
#include "Action.h"
#include "GenericAction.h"
#include "Condition.h"
#include "GenericCondition.h"
#include "EqualsCondition.h"	
#include "Transition.h"

using namespace std;
using namespace DecisionMaking;
//using namespace Desc

/*namespace DecisionMaking
{*/	
	/*DecisionMaking::DecisionMaking()
	{
	}*/

	/*void Enter(const State& state)
	{
		cout << state.Name() << "::Enter()" << endl;
	}

	void Exit(const State& state)
	{
		cout << state.Name() << "::Exit()" << endl;
	}*/
	
	int main()
	{
		StateMachine game;
		StateMachine AI;

		bool chase = 0;
		bool backtrack = 0;

		/*auto enter = make_shared<GenericAction>(Enter);
		auto exit = make_shared<GenericAction>(Exit);*/

		/*shared_ptr<Action> enter = make_shared<GenericAction>([](const State& state)
		{
			(void)state;
		});*/

		auto enter = make_shared<GenericAction>([](const State& state)
		{
			cout << state.Name() << "::Enter()" << endl;
		});

		auto exit = make_shared<GenericAction>([](const State& state)
		{
			cout << state.Name() << "::Exit()" << endl;
		});

		/*auto genericCondition = make_shared<GenericCondition>([]()
		{
			
		});*/

		/*auto genericCondition = make_shared<GenericCondition>([]()
		{
		
		});*/

		//Creating states.
		shared_ptr<State> one = make_shared<State>("one", enter, exit);
		shared_ptr<State> two = make_shared<State>("two", enter, exit);
		shared_ptr<State> three = make_shared<State>("three", enter, exit);
		shared_ptr<State> four = make_shared<State>("four", enter, exit);
		shared_ptr<State> five = make_shared<State>("five", enter, exit);
		shared_ptr<State> six = make_shared<State>("six", enter, exit);
		shared_ptr<State> seven = make_shared<State>("seven", enter, exit);
		shared_ptr<State> eight = make_shared<State>("eight", enter, exit);
		shared_ptr<State> nine = make_shared<State>("nine", enter, exit);


		//Adding states.
		game.AddState(one);
		game.AddState(two);
		game.AddState(three);
		game.AddState(four);
		game.AddState(five);
		game.AddState(six);
		game.AddState(seven);
		game.AddState(eight);
		game.AddState(nine);

		//Adding states for AI.
		AI.AddState(one);
		AI.AddState(two);
		AI.AddState(three);
		AI.AddState(four);
		AI.AddState(five);
		AI.AddState(six);
		AI.AddState(seven);
		AI.AddState(eight);
		AI.AddState(nine);

		//auto oneToTwo = make_shared<Transition>(one, genericCondition);
		//one->AddTransition(oneToTwo);

		/*
		Another way to possibly add it is

		auto states = { one, two, three, four, five, six, seven, eight, nine};

		game.AddStates(states);

		*/

		game.SetCurrentState(one);
		AI.SetCurrentState(nine);
		//game.SetCurrentState(two);

		shared_ptr<string> command = make_shared<string>();
		string command2;

		//cin >> *command;

		shared_ptr<EqualsCondition> northMovement = make_shared<EqualsCondition>("north", command);
		shared_ptr<EqualsCondition> eastMovement = make_shared<EqualsCondition>("east", command);
		shared_ptr<EqualsCondition> southMovement = make_shared<EqualsCondition>("south", command);
		shared_ptr<EqualsCondition> westMovement = make_shared<EqualsCondition>("west", command);
		//shared_ptr<EqualsCondition> exitCommand = make_shared<EqualsCondition>("exit", command);

		auto oneToTwo = make_shared<Transition>(two, southMovement);
		auto twoToThree = make_shared<Transition>(three, southMovement);
		auto threeToTwo = make_shared<Transition>(two, northMovement);
		auto threeToFour = make_shared<Transition>(four, westMovement);
		auto threeToSeven = make_shared<Transition>(seven, southMovement);
		auto fourToThree = make_shared<Transition>(three, eastMovement);
		auto fourToFive = make_shared<Transition>(five, northMovement);
		auto fourToSix = make_shared<Transition>(six, southMovement);
		auto sixToFour = make_shared<Transition>(four, northMovement);
		auto sixToSeven = make_shared<Transition>(seven, eastMovement);
		auto sevenToEight = make_shared<Transition>(eight, eastMovement);
		auto sevenToSix = make_shared<Transition>(six, westMovement);
		auto eightToSeven = make_shared<Transition>(seven, westMovement);
		auto eightToNine = make_shared<Transition>(nine, eastMovement);
		auto nineToEight = make_shared<Transition>(eight, westMovement);
		/*auto exit = make_shared<Transition>(exitCommand);
		game.AddTransition(exit);*/

		one->AddTransition(oneToTwo);
		two->AddTransition(twoToThree);
		three->AddTransition(threeToTwo);
		three->AddTransition(threeToFour);
		three->AddTransition(threeToSeven);
		four->AddTransition(fourToThree);
		four->AddTransition(fourToFive);
		four->AddTransition(fourToSix);
		six->AddTransition(sixToFour);
		six->AddTransition(sixToSeven);
		seven->AddTransition(sevenToEight);
		seven->AddTransition(sevenToSix);
		eight->AddTransition(eightToSeven);
		eight->AddTransition(eightToNine);
		nine->AddTransition(nineToEight);

		//cout << one->Transitions().size() << endl;

		shared_ptr<State> temp = make_shared<State>();

		while (game.CurrentState() != five)// && (game.CurrentState() != AI.CurrentState()))
		{
			cout << ">";
			cin >> *command;

			//cout << "Current state: " << game.CurrentState()->Name() << endl;

			if (*command == "exit")
			{
				break;
			}

			temp = game.Update();

			// AI Controller
			if (chase)
			{
				AI.SetCurrentState(game.CurrentState());
			}
			else
			{
				if (AI.CurrentState() == nine)
				{
					backtrack = 0;

					if (game.CurrentState() == eight)
					{
						chase = 1;
					}

					AI.SetCurrentState(eight);
				}
				else if (AI.CurrentState() == eight)
				{
					if (game.CurrentState() == nine || game.CurrentState() == seven)
					{
						chase = 1;
					}

					if (backtrack)
					{
						AI.SetCurrentState(nine);
					}
					else
					{
						AI.SetCurrentState(seven);
					}
				}
				else if (AI.CurrentState() == seven)
				{
					if (game.CurrentState() == eight || game.CurrentState() == six)
					{
						chase = 1;
					}

					if (backtrack)
					{
						AI.SetCurrentState(eight);
					}
					else
					{
						AI.SetCurrentState(six);
					}
				}
				else if (AI.CurrentState() == six)
				{
					if (game.CurrentState() == seven || game.CurrentState() == four)
					{
						chase = 1;
					}

					AI.SetCurrentState(four);
				}
				else if (AI.CurrentState() == four)
				{
					if (game.CurrentState() == six || game.CurrentState() == three)
					{
						chase = 1;
					}

					AI.SetCurrentState(three);
				}
				else if (AI.CurrentState() == three)
				{
					if (game.CurrentState() == four || game.CurrentState() == seven || game.CurrentState() == two)
					{
						chase = 1;
					}

					backtrack = 1;
					AI.SetCurrentState(seven);
				}
			}

			if (chase)
			{
				cout << "THE MONSTER IS CHASING YOU! RUN!!!" << endl;
			}

			if (temp != nullptr)
			{
				game.SetCurrentState(temp);
			}
		}

		if (*command != "exit" && game.CurrentState() == five)
		{
			cout << "You have found the exit and escaped the monster!" << endl;
		}
		/*else if (game.CurrentState() == AI.CurrentState())
		{
			cout << "The monster has eaten you and you have died." << endl;
		}*/

		//cout << game.CurrentState()->Name() << endl;

		//game.AddTransition(condition, two);


		//Graph stuff
		{
			//auto states = { one };

			//game.AddStates(states);
			//std::vector<std::list<int>> mAdjacencyList;

			//std::vector<int> mTest;
			////mTest.reserve(3);

			///*int array[10];
			//array[0] = 1;*/
			//mTest.push_back(10);
			//mTest.push_back(22);

			////cout << mTest.size() << "\n" << endl;

			//list<int> testList;
			///*testList.push_back(10);
			//testList.push_back(5);*/

			////mAdjacencyList.push_back(testList);

			///*for (auto n : mAdjacencyList[0])
			//{
			//	cout << n << " ";
			//}

			//cout << endl;*/

			///*for (unsigned int i = 0; i < mAdjacencyList[0].size(); i++)
			//{
			//	cout << mAdjacencyList[0].
			//}*/

			////mAdjacencyList[0].push_back(100);

			///*for (unsigned int i = 0; i < mTest.size(); i++)
			//{
			//	cout << mTest.at(i) << "\n";
			//}*/
			////mTest.at(0) = 1;

			////mTest.reserve(10);
			////mTest[1] = 1;
			////mTest.push_back(10);
			////int node;
			////std::cout << "Test";

			//ifstream graph;

			//graph.open("Graph.txt");

			////mAdjacencyList.
			///*int node;
			//node = graph.get();

			//cout << char(node) << endl;

			//node = graph.get();

			//cout << char(node) << endl;

			//node = graph.get();

			//cout << char(node) << endl;
			//node = graph.get();

			//cout << char(node) << endl;*/



			//for (int i = 0; i < 9; i++)
			//{
			//	testList.clear();

			//	for (int j = 0; j < 9; j++)
			//	{
			//		//node = graph.get();

			//		if (char(graph.get()) == '1')//graph.get() == 1)
			//		{
			//			testList.push_back(j);
			//			//mAdjacencyList[i].push_back(testList);
			//			//mAdjacencyList[i].push_back(j);
			//		}
			//	}

			//	mAdjacencyList.push_back(testList);

			//	if (mAdjacencyList[i].size() > 0)
			//	{
			//		for (auto n : mAdjacencyList[i])
			//		{
			//			cout << n << " ";
			//		}

			//		cout << endl;
			//	}
			//}

			////for (int 1 = 0; i < 9; i++)

			////mAdjacencyList[0].push_back(10);
			////printf("Testtt\n\n");

			////cout << mAdjacencyList.size() << "\n" << endl;

			///*for (unsigned int i = 0; i < mAdjacencyList.size(); i++)
			//{
			//	cout << i << "\n" << endl;
			//}*/
			////cout << "tttt" << endl;

			//graph.close();
		}


		return 0;
	}
//}