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

		/*auto enter = make_shared<GenericAction>(Enter);
		auto exit = make_shared<GenericAction>(Exit);*/

		auto enter = make_shared<GenericAction>([](const State& state)
		{
			cout << state.Name() << "::Enter()" << endl;
		});

		/*auto exit = make_shared<GenericAction>([](const State& state)
		{
			cout << state.Name() << "::Exit()" << endl;
		});*/

		/*auto genericCondition = make_shared<GenericCondition>([]()
		{
		
		});*/

		//Creating states.
		shared_ptr<State> one = make_shared<State>("one");//, enter, exit);
		shared_ptr<State> two = make_shared<State>("two");//, enter, exit);
		shared_ptr<State> three = make_shared<State>("three");//, enter, exit);
		shared_ptr<State> four = make_shared<State>("four");//, enter, exit);
		shared_ptr<State> five = make_shared<State>("five");//, enter, exit);
		shared_ptr<State> six = make_shared<State>("six");//, enter, exit);
		shared_ptr<State> seven = make_shared<State>("seven");//, enter, exit);
		shared_ptr<State> eight = make_shared<State>("eight");//, enter, exit);
		shared_ptr<State> nine = make_shared<State>("nine");//, enter, exit);


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

		//auto oneToTwo = make_shared<Transition>(one, genericCondition);
		//one->AddTransition(oneToTwo);

		/*
		Another way to possibly add it is

		auto states = { one, two, three, four, five, six, seven, eight, nine};

		game.AddStates(states);

		*/

		game.SetCurrentState(one);

		cout << game.CurrentState()->Name() << endl;

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