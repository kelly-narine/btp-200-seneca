#include <iostream>
#include "graph.h"
#include "io.h"

/*
Exposes all identifiers in std namespace (in iostream header): 
won't need to have the name qualifier with objects that are part of the std namespace 
(i.e. std::cout, std::cin, etc.)
*/
using namespace std; 

namespace seneca
{
	void getSamples(int samples[], int noOfSamples)
	{
		for (int i = 0; i < noOfSamples; ++i)
		{
			cout << "  >> " << (i + 1) << "/";
			printInt(noOfSamples, 2);
			cout << ": ";
			samples[i] = getInt(1, 1000000);
		}
	}

	int findMax(int arr[], int arrSize)
	{
		int max = arr[0];
		for (int i = 1; i < arrSize; i++)
			if (max < arr[i])
				max = arr[i];

		return max;
	}

	void printSampleBar(int val, int max)
	{
		// Calculate the bar length as the width of the graph, minus
		//   - 2 to account for the left border (`| `)
		//   - 1 to account for the space between the bar and the sample value
		//   - 2 to account for the right border (` |`)
		//   - the number of digits in `max`
		//   and scaled to `max`. This scaling ensures that the largest
		//   sample will always occupy the width of the entire graph.
		int barLength = (GRAPH_WIDTH - 5 - intDigits(max)) * val / max;
		cout << "| ";
		for (int i = 0; i < barLength; ++i)
			cout << '*';
		cout << ' ';
		printInt(val, GRAPH_WIDTH - 5 - barLength);
		cout << " |" << endl;
	}

	void printGraph(int samples[], int noOfSamples, const char* label)
	{
		// find which sample is the biggest. This sample will be used
		//   to scale the other sample so they can be visually compared.
		int max = findMax(samples, noOfSamples);

		printMsg("\n");
		drawLineWithLabel(GRAPH_WIDTH, label);
		for (int i = 0; i < noOfSamples; ++i)
			printSampleBar(samples[i], max);
		drawLine(GRAPH_WIDTH);
	}
}
