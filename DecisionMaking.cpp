// DecisionMaking.cpp : Defines the entry point for the console application.
//

#include "pch.h"
//#include "DecisionMaking.h"
#include <vector>
#include <list>
#include <fstream>

using namespace std;

/*namespace DecisionMaking
{*/	
	/*DecisionMaking::DecisionMaking()
	{
	}*/
	
	int main()
	{
		std::vector<std::list<int>> mAdjacencyList;
		//std::cout << "Test";

		ifstream graph;

		graph.open("Graph.txt");

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (graph.get() == 1)
				{
					//mAdjacencyList.
				}
			}
		}

		printf("Testtt\n\n");

		graph.close();

		return 0;
	}
//}