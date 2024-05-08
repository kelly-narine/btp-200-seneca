#include <iostream>
#include "io.h"

using namespace std;

namespace seneca
{
	void drawLine(int length)
	{
		cout << '+';
		for (int i = 0; i < length - 2; ++i)
			cout << '-';
		cout << '+' << '\n';
	}

	int intDigits(int value)
	{
		int count = 0;

		// Count how many times the number can be divided by 10 before the result is 0.
		//   This is an integer division (the fractionary part of the result is discarded).
		do
		{
			value /= 10;
			++count;
		} while (value != 0);

		return count;
	}

	void printInt(int value, int fieldWidth)
	{
		// prints the value
		cout << value;

		// find how many spaces we must add after the value in order to fill the entire field
		int extraSpaces = fieldWidth - intDigits(value);

		// do the filling
		for (int i = 0; i < extraSpaces; ++i)
			cout << ' ';
	}

	void moveCursorBack(int n)
	{
		// `\b` moves the cursor back a single position in the current line
		//   - doesn't move to a previous line
		//   - characters that are already printed on the screen are not erased
		for (int i = 0; i < n; ++i)
			cout << '\b';
	}

	void drawLineWithLabel(int length, const char* text)
	{
		// print the line first (ignore the text)
		cout << '+';
		for (int i = 0; i < length - 2; ++i)
			cout << '-';
		cout << '+';


		if (text)
		{
			// move the cursor back, but leave the first 4 characters in places
			moveCursorBack(length - 4);
			// erase the exiting printed characters (the dashes) and replace them
			//   with the `text` surounded by spaces.
			cout << ' ' << text << ' ';
		}

		cout << endl;
	}

	int getInt(int min, int max)
	{
		int val = min - 1;
		bool done = false;
		while (!done)
		{
			// Extract a value from user.
			// 
			// If the user types a non-integer, this program cannot use the
			//   keyboard anymore (the `cin` object will enter in error mode).
			//   The user must restart the program.
			cin >> val;
			if (val < min || max < val)
			{
				// the value is outside the boundaries of the interval
				cout << "  Invalid value! The value must be between "
					<< min << " and " << max << ".\n  Try again: ";
			}
			else
			{
				// value is good; exit the loop
				done = true;
			}
		}
		return val;
	}

	void printMsg(const char* msg)
	{
		cout << "  " << msg;
	}

	void printErrorMsg(const char* msg)
	{
		cout << "  ERROR: " << msg << endl;
	}

	int menu(int noOfSamples)
	{
		{
			// print the header of the menu
			cout << endl;
			drawLine(GRAPH_WIDTH);
			cout << "| Number of Samples: ";

			// print the number to fill the rest of the line
			// - subtract 21 to account for the characters printed above
			// - subtract 2 to account for the characters that come at the end
			//     of the line: ` |` (see below)
			printInt(noOfSamples, GRAPH_WIDTH - 21 - 2);
			cout << " |" << endl;

			drawLine(GRAPH_WIDTH);
		}

		// print the menu items and the prompt for user to select an item
		cout << "| 1- Set Number of Samples                                      |" << endl;
		cout << "| 2- Enter Samples                                              |" << endl;
		cout << "| 3- Graphs                                                     |" << endl;
		cout << "| 0- Exit                                                       |" << endl;
		cout << "\\ >>                                                            /";
		moveCursorBack(GRAPH_WIDTH - 5);

		return getInt(0, 3);
	}
}
