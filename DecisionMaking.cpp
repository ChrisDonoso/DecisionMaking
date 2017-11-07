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

#define FIVE_SECONDS 5000
#define TEN_SECONDS 10000

using namespace std;
using namespace DecisionMaking;
	
int main(void)
{
	StateMachine game;
	StateMachine AI;

	AI.Initialize();
	game.Initialize();

	// Enter Action
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
	});

	// Exit Action
	auto exit = make_shared<GenericAction>([](const State& state)
	{
		cout << "You have left the " << state.Name() << ".\n" << endl;
	});

	// Inspect Action
	auto inspect = make_shared<GenericAction>([](const State& state)
	{
		cout << state.InspectionDescription() << endl << endl;
	});

	// Hide Action
	auto hide = make_shared<GenericAction>([&game]()
	{
		if (game.HideSuccessful())
		{
			cout << "You have successfully hidden from the monster.\n" << endl;
		}
		else
		{
			cout << "You have unsuccessfully hidden from the monster and have been eaten.\n" << endl;
			game.SetDead(true);
		}
	});

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

	auto gameStates = { one, two, three, four, five, six, seven, eight, nine };

	// Adding states for game state machine (player).
	game.AddStates(gameStates);

	auto AIStates = { twoMonster, threeMonster, fourMonster, sixMonster, sevenMonster, eightMonster, nineMonster };

	// Adding states for AI state machine.
	AI.AddStates(AIStates);

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

	// Add descriptions for the states.
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

	// Add inspection descriptions for the states.
	one->SetInspectionDescription("You find nothing.");
	two->SetInspectionDescription("You inspect the painting further, and it no longer appears to be crying, but smiling.");
	three->SetInspectionDescription("You notice a few of the strange contraption's spikes on the ground.");
	four->SetInspectionDescription("You further inspect the weapon rack to look for a working weapon, but have no luck.");
	six->SetInspectionDescription("You find nothing.");
	seven->SetInspectionDescription("You notice a book sticking out of one of the shelves, and open it. You find a key inside! *Plays Legend of Zelda chest\nopening music.*");
	eight->SetInspectionDescription("You notice a weird circular pattern on the ground, and walk inside of it. All of a sudden your body feels light, and\nyou find yourself in a different room.");
	nine->SetInspectionDescription("Among all of the bones on the ground, in the center of the room you see what appears to be a fresh mutilated corpse.");

	game.SetCurrentState(one);
	AI.SetCurrentState(nineMonster);

	shared_ptr<string> command = make_shared<string>();

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

	seven->AddProperty("key");

	shared_ptr<State> temp = make_shared<State>();

	cout << "**Type 'list' to get a list of available commands at any moment.**\n" << endl;

	// Intro Description
	game.CurrentState()->Enter();

	bool validCommand;

	clock_t timer = 0;

	srand(static_cast<unsigned int>(time(nullptr)));

	while (game.CurrentState() != five && !game.Dead())
	{
		temp = nullptr;

		// Only print lengthy description upon first time entering state
		game.CurrentState()->SetFirstTimeEntered(false);

		validCommand = false;

		// User enters a command
		while (!validCommand || *command == "list")
		{
			validCommand = false;
			timer = clock();

			cout << ">";
			cin >> *command;

			if (AI.Chase())
			{
				if (AI.FirstEncounter())
				{
					AI.SetFirstEncounter(false);

					if (clock() - timer >= TEN_SECONDS && AI.Chase())
					{
						cout << "\nYou took too long to react and the monster has eaten you!" << endl;
						game.SetDead(true);
						break;
					}
				}
				else
				{
					if (clock() - timer >= FIVE_SECONDS && AI.Chase())
					{
						cout << "\nYou took too long to react and the monster has eaten you!" << endl;
						game.SetDead(true);
						break;
					}
				}
			}

			// Convert user input to lower case
			for (unsigned int i = 0; i < command->length(); i++)
			{
				(*command)[i] = (char)tolower((*command)[i]);
			}

			// Show the user a list of commands
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

		// Player took to long to respond and has died in this case
		if (game.Dead())
		{
			break;
		}

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
				game.SetAttemptToHide(true);

				game.SetHideSuccessful(rand() % 2);

				if (game.HideSuccessful())
				{
					AI.SetChase(false);
				}
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
			}
			else
			{
				temp = game.Update();

				if (game.AttemptingToHide())
				{
					if (game.HideSuccessful())
					{
						game.SetHideSuccessful(false);
					}

					game.SetAttemptToHide(false);
				}
			}
		}

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

		if (AI.Chase() && !game.Dead() && game.CurrentState() != five)
		{
			if (AI.FirstEncounter())
			{
				cout << "You feel some kind of liquid drip onto your head. You run your fingers through your hair, it feels sticky. You try to\nbrush it off but another drop hits your head. You "
					"look up and are immediately struck with fear. Standing right above\nyou is some kind of grey and purple demon with six legs and the biggest horns you've ever seen. It opens its "
					"mouth to\nroar and you notice it has very sharp jagged teeth. The monster changes its stance as if it's going to start chasing\nyou. LEAVE THE ROOM OR HIDE('hide')!!!\n" << endl;
			}
			else
			{
				cout << "THE MONSTER IS CHASING YOU! RUN!!!\n" << endl;
			}
		}

		if (temp != nullptr)
		{
			game.SetCurrentState(temp);
		}
	}

	return 0;
}