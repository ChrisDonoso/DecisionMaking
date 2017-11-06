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

		int value;
		bool validCommand;

		/*bool chase = 0;
		bool backtrack = 0;*/

		/*auto enter = make_shared<GenericAction>(Enter);
		auto exit = make_shared<GenericAction>(Exit);*/

		/*shared_ptr<Action> enter = make_shared<GenericAction>([](const State& state)
		{
			(void)state;
		});*/

		auto enter = make_shared<GenericAction>([](const State& state)
		{
			if (state.FirstTimeEntered())
			{
				cout << state.Description() << endl << endl;
			}
			else
			{
				cout << "You have entered the " << state.Name() << ".\n" << endl;
			}
			//cout << state.Name() << "::Enter()" << endl;

			//state.SetDescription("asdas");
			//cout << state.Description() << endl;
		});

		auto exit = make_shared<GenericAction>([](const State& state)
		{
			//(void)state;
			cout << "You have left the " << state.Name() << ".\n" << endl;
			//cout << state.Name() << "::Exit()" << endl;
			//cout << state.Description() << endl;
		});

		auto inspect = make_shared<GenericAction>([](const State& state)
		{
			//(void)state;
			cout << state.InspectionDescription() << endl << endl;
			//cout << state.Name() << "::Exit()" << endl;
			//cout << state.Description() << endl;
		});

		auto hide = make_shared<GenericAction>([&game]()
		{
			//(void)state;
			if (game.HideSuccessful())
			{
				cout << "You have successfully hidden from the monster.\n" << endl;
			}
			else
			{
				cout << "You have unsuccessfully hidden from the monster and have been eaten.\n" << endl;
				game.SetDead(true);
			}
			//if (state.)
			//return (value % 2 == 0);
			//cout << state.Name() << "::Exit()" << endl;
			//cout << state.Description() << endl;
		});

		/*inspect->SetName("inspect");
		hide->SetName("hide");*/

		//auto hide = make_shared<GenericAction>([&value]()
		//{
		//	//(void)state;
		//	//cout << "You have successfully hidden from the monster." << endl;
		//	//if (state.)
		//	return (value % 2 == 0);
		//	//cout << state.Name() << "::Exit()" << endl;
		//	//cout << state.Description() << endl;
		//});

		/*auto genericCondition = make_shared<GenericCondition>([]()
		{
			
		});*/

		/*auto genericCondition = make_shared<GenericCondition>([]()
		{
		
		});*/

		//Creating states.
		shared_ptr<State> one = make_shared<State>("Foyer", enter, exit); //one
		shared_ptr<State> two = make_shared<State>("Dining Hall", enter, exit); //two
		shared_ptr<State> three = make_shared<State>("Torture Chamber", enter, exit); //three
		shared_ptr<State> four = make_shared<State>("Barracks", enter, exit); //four
		shared_ptr<State> five = make_shared<State>("Garden", enter, exit); //five 
		shared_ptr<State> six = make_shared<State>("Workshop", enter, exit); //six
		shared_ptr<State> seven = make_shared<State>("Library", enter, exit); //seven
		shared_ptr<State> eight = make_shared<State>("Laboratory", enter, exit); //eight
		shared_ptr<State> nine = make_shared<State>("Catacombs", enter, exit); //nine

		shared_ptr<State> twoMonster = make_shared<State>("Dining Hall");
		shared_ptr<State> threeMonster = make_shared<State>("Torture Chamber");
		shared_ptr<State> fourMonster = make_shared<State>("Barracks");
		shared_ptr<State> sixMonster = make_shared<State>("Workshop");
		shared_ptr<State> sevenMonster = make_shared<State>("Library");
		shared_ptr<State> eightMonster = make_shared<State>("Laboratory");
		shared_ptr<State> nineMonster = make_shared<State>("Catacombs");

		//game.SetInspect(inspect);

		one->SetInspect(inspect);
		two->SetInspect(inspect);
		three->SetInspect(inspect);
		four->SetInspect(inspect);
		five->SetInspect(inspect);
		six->SetInspect(inspect);
		seven->SetInspect(inspect);
		eight->SetInspect(inspect);
		nine->SetInspect(inspect);

		one->SetHide(hide);
		two->SetHide(hide);
		three->SetHide(hide);
		four->SetHide(hide);
		five->SetHide(hide);
		six->SetHide(hide);
		seven->SetHide(hide);
		eight->SetHide(hide);
		nine->SetHide(hide);

		//Add descriptions for the states.
		one->SetDescription("You wake up in an unknown location, slightly dazed and confused. You look around you and you appear to be in the entry\nroom of a 12th century Gothic castle, "
			"the walls garnished with red drapes, the cielings with broken chandeliers, and\nbroken statues encompassing the room. "
			"The castle has a damp and cold feeling, as if it has not been inhabited for\nawhile. You notice some big wooden doors to the South.");
		two->SetDescription("As you enter the room, the doors behind you slam shut. You try to open them, but have no luck. You notice a long wooden\ntable in the center "
			"of the room, with chandeliers hanging above it, and ripped flags hanging on the cobblestone walls.\nThere is a big eerire painting of a girl crying hanging on the center of the "
			"wall on the right side of the room. You\nnotice a door to the South.");
		three->SetDescription("You enter a small room with no windows. In the middle of the room you find an odd looking contraption that almost looks\nlike a coffin. You smell something "
			"wretched coming from it, and open it. Upon opening it, you notice sharp metal spikes\nhanging from the cover, and lying in the contraption is a skeleton. You quickly close it and look for an exit. "
			"You\nnotice doors to the North, South, and West sides of the room.");
		four->SetDescription("You enter a small room, and in the middle you notice a forge, and in one of the corners you notice a furnace with an\nanvil next to it. Hanging on the walls are racks littered with "
			"broken weapons. You notice doors to the North, East, and\nSouth.");
		five->SetDescription("You open the locked door with your key, and have found a secret passage that leads to the garden outside. You have\nfound freedom and are happy that you got out of there alive!");
		six->SetDescription("You enter a room with a workbench in the middle of it. There are nails scattered on the floor and tools scattered\naccross the workbench. You notice doors to the North and East.");
		seven->SetDescription("You enter a very large room with bookshelves as high as the ceiling lining the walls. You look up and notice a mural\npainted on the ceiling. The mural seems dull and worn out, but "
			"You can tell that it must have been majestic when it was\npainted. You notice doors to the East and West.");
		eight->SetDescription("You enter a room with vials and tubes spread out on a table. There are papers with diagrams and formulas spread\nthroughout the entire room on the floors and walls. This "
			"appears to be a lab of some sort. You notice doors to the East and West.");
		nine->SetDescription("You enter a very dark room. The air feels damp and cold, and you reach your hands out to try and find a wall to walk\nalong. You feel something cold with an odd texture. "
			"Your eyes adjust, and you notice that the walls are lined with\nbones and skulls. Your heart sinks, and the hair on the back of your neck rises. You quickly look for an exit, and \nnotice "
			"that the only exit is the way you came, from the East.");

		one->SetInspectionDescription("You find nothing.");
		two->SetInspectionDescription("You inspect the painting further, and it no longer appears to be crying, but smiling.");
		three->SetInspectionDescription("You notice a few of the strange contraption's spikes on the ground.");
		four->SetInspectionDescription("You further inspect the weapon rack to look for a working weapon, but have no luck.");
		six->SetInspectionDescription("You find nothing.");
		seven->SetInspectionDescription("You notice a book sticking out of one of the shelves, and open it. You find a key inside! *Plays Legend of Zelda chest\nopening music.*");
		eight->SetInspectionDescription("You notice a weird circular pattern on the ground, and walk inside of it. All of a sudden your body feels light, and\nyou find yourself in a different room.");
		nine->SetInspectionDescription("Among all of the bones on the ground, in the center of the room you see what appears to be a fresh mutilated corpse.");

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
		/*AI.AddState(one);
		AI.AddState(two);
		AI.AddState(three);
		AI.AddState(four);
		AI.AddState(five);
		AI.AddState(six);
		AI.AddState(seven);
		AI.AddState(eight);
		AI.AddState(nine);*/

		AI.AddState(twoMonster);
		AI.AddState(threeMonster);
		AI.AddState(fourMonster);
		AI.AddState(sixMonster);
		AI.AddState(sevenMonster);
		AI.AddState(eightMonster);
		AI.AddState(nineMonster);

		//auto oneToTwo = make_shared<Transition>(one, genericCondition);
		//one->AddTransition(oneToTwo);

		/*
		Another way to possibly add it is

		auto states = { one, two, three, four, five, six, seven, eight, nine};

		game.AddStates(states);

		*/

		game.SetCurrentState(one);
		AI.SetCurrentState(nineMonster);
		//game.SetCurrentState(two);

		shared_ptr<string> command = make_shared<string>();
		string command2;

		//cin >> *command;

		shared_ptr<EqualsCondition> northMovement = make_shared<EqualsCondition>("north", command);
		shared_ptr<EqualsCondition> eastMovement = make_shared<EqualsCondition>("east", command);
		shared_ptr<EqualsCondition> southMovement = make_shared<EqualsCondition>("south", command);
		shared_ptr<EqualsCondition> westMovement = make_shared<EqualsCondition>("west", command);
		//shared_ptr<EqualsCondition> inspectCondition = make_shared<EqualsCondition>("inspect", command);
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

		seven->AddProperty("key");//, true);
		//seven->RemoveProperty("key");

		//cout << seven->GetProperty("key") << endl;

		//cout << one->Transitions().size() << endl;

		shared_ptr<State> temp = make_shared<State>();

		// Intro Description
		game.CurrentState()->Enter();

		// Put in Initialize method?
		AI.SetChase(false);
		AI.SetBacktrack(false);
		AI.SetAttemptToHide(false);
		AI.SetFirstEncounter(true);
		game.SetAttemptToHide(false);
		game.SetDead(false);

		while (game.CurrentState() != five && !game.Dead())// && (game.CurrentState() != AI.CurrentState()))
		{
			//cout << game.CurrentState()->Description() << endl;
			temp = nullptr;

			// Only print lengthy description upon first time entering state
			game.CurrentState()->SetFirstTimeEntered(false);

			validCommand = false;

			// User enters a command
			while (!validCommand || *command == "list")
			{
				validCommand = false;

				cout << ">";
				cin >> *command;

				if (*command == "list")
				{
					if (AI.Chase())
					{
						cout << "Available Commands: 'north', 'east', 'south', 'west', 'hide', 'inspect', 'exit'(Ends Game)." << endl;
					}
					else
					{
						cout << "Available Commands: 'north', 'east', 'south', 'west', 'inspect', 'exit'(Ends Game)." << endl;
					}
				}

				if (AI.Chase())
				{
					if (*command == "north" || *command == "east" || *command == "south" || *command == "west" || *command == "hide" || *command == "inspect" || *command == "exit")
					{
						validCommand = true;
					}
				}
				else
				{
					if (*command == "north" || *command == "east" || *command == "south" || *command == "west" || *command == "inspect" || *command == "exit")
					{
						validCommand = true;
					}
				}
			}

			cout << endl;

			//strcpy((char*)&command, (char*)tolower(&command));
			//command = tolower(command);

			//cout << "Current state: " << game.CurrentState()->Name() << endl;

			// Exit the game
			if (*command == "exit")
			{
				break;
			}
			
			// If the player is being chased, they can hide
			if (AI.Chase())
			{
				if (*command == "hide")
				{
					//game.SetHide(true);
					game.SetAttemptToHide(true);

					value = rand();

					game.SetHideSuccessful(value % 2 == 0);

					if (game.HideSuccessful())
					{
						AI.SetChase(false);
					}

					//cout << game.HideSuccessful () << endl;
					//game.SetHide(game.CurrentState()->Hide());
				}
				else
				{
					game.SetAttemptToHide(false);
				}
			}

			// Inspect the room
			if (*command == "inspect")
			{
				game.SetInspecting(true);

				if (game.CurrentState() == seven)
				{
					game.AddProperty("key");
					game.CurrentState()->RemoveProperty("key");
				}
				//else if (game.CurrentState() == eight)
				//{
				//	temp = four;
				//	//game.SetCurrentState(four);
				//}

				//game.SetInspecting(true);
			}
			else
			{
				game.SetInspecting(false);
			}

			// Player cannot enter the Garden (State five) unless they have the key - this is the exit and triggers game over
			if (*command == "north" && game.CurrentState() == four)
			{
				if (game.GetProperty("key"))
				{
					temp = game.Update();
				}
				else
				{
					cout << "The door appears to be locked.\n" << endl;
				}
			}
			else
			{	
				if (game.CurrentState() == eight && game.Inspecting())
				{
					game.CurrentState()->Inspect();
					game.SetInspecting(false);
					game.CurrentState()->Exit();
					temp = four;
					temp->Enter();

					// Player has teleported away from the monster
					if (AI.CurrentState() != threeMonster && AI.CurrentState() != sixMonster)
					{
						AI.SetChase(false);
					}
					//temp = game.Update();
					//game.CurrentState()
					//temp = four;

					//temp = game.Update();
					//temp = four;
				}
				else
				{
					temp = game.Update();
				}
			}

			/*if (game.CurrentState() == four && game.GetProperty("key") && *command == "north")
			{
				temp = game.Update();
			}
			else
			{
				temp = game.Update();
			}*/

			/** AI Controller **/
			// AI follows player
			if (AI.Chase())
			{
				if (game.CurrentState() == two)
				{
					AI.SetCurrentState(twoMonster);
				}
				else if (game.CurrentState() == three)
				{
					AI.SetCurrentState(threeMonster);
				}
				else if (game.CurrentState() == four)
				{
					AI.SetCurrentState(fourMonster);
				}
				else if (game.CurrentState() == six)
				{
					AI.SetCurrentState(sixMonster);
				}
				else if (game.CurrentState() == seven)
				{
					AI.SetCurrentState(sevenMonster);
				}
				else if (game.CurrentState() == eight)
				{
					AI.SetCurrentState(eightMonster);
				}
				else if (game.CurrentState() == nine)
				{
					AI.SetCurrentState(nineMonster);
				}
				//AI.SetCurrentState(game.CurrentState());
			}
			// AI is not chasing player, it moves in its patrol formation
			else
			{
				if (AI.CurrentState() == nineMonster)
				{
					AI.SetBacktrack(false);

					if (game.CurrentState() == eight)
					{
						AI.SetChase(true);
					}

					AI.SetCurrentState(eightMonster);
				}
				else if (AI.CurrentState() == eightMonster)
				{
					if (game.CurrentState() == nine || game.CurrentState() == seven)
					{
						AI.SetChase(true);
					}

					if (AI.Backtrack())
					{
						AI.SetCurrentState(nineMonster);
					}
					else
					{
						AI.SetCurrentState(sevenMonster);
					}
				}
				else if (AI.CurrentState() == sevenMonster)
				{
					if (game.CurrentState() == eight || game.CurrentState() == six)
					{
						AI.SetChase(true);
					}

					if (AI.Backtrack())
					{
						AI.SetCurrentState(eightMonster);
					}
					else
					{
						AI.SetCurrentState(sixMonster);
					}
				}
				else if (AI.CurrentState() == sixMonster)
				{
					if (game.CurrentState() == seven || game.CurrentState() == four)
					{
						AI.SetChase(true);
					}

					AI.SetCurrentState(fourMonster);
				}
				else if (AI.CurrentState() == fourMonster)
				{
					if (game.CurrentState() == six || game.CurrentState() == three)
					{
						AI.SetChase(true);
					}

					AI.SetCurrentState(threeMonster);
				}
				else if (AI.CurrentState() == threeMonster)
				{
					if (game.CurrentState() == four || game.CurrentState() == seven || game.CurrentState() == two)
					{
						AI.SetChase(true);
					}

					AI.SetBacktrack(true);
					AI.SetCurrentState(sevenMonster);
				}
			}

			if (AI.Chase() && !game.Dead())
			{
				if (AI.FirstEncounter())
				{
					AI.SetFirstEncounter(false);

					cout << "\nYou feel some kind of liquid drip onto your head. You run your fingers through your hair, it feels sticky. You try to\nbrush it off but another drop hits your head. You "
						"look up and are immediately struck with fear. Standing right above\nyou is some kind of grey and purple demon with six legs and the biggest horns you've ever seen. It opens its "
						"mouth to\nroar and you notice it has very sharp jagged teeth. The monster changes its stance as if it's going to start chasing\nyou. LEAVE THE ROOM OR HIDE!!!\n" << endl;
				}
				else
				{
					cout << "\nTHE MONSTER IS CHASING YOU! RUN!!!\n" << endl;
				}
			}

			if (temp != nullptr)
			{
				game.SetCurrentState(temp);
			}
		}

		/*if (*command != "exit" && game.CurrentState() == five)
		{
			cout << game.CurrentState()->Description() << endl;
		}*/

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