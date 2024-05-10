
// This prevents VS compiler from issuing warnings/errors related to utilization
//   of unsafe string functions.  Has no effect in g++.
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
// TODO: include any other header that is necessary for your solution
#include "DataHandle.h"

using namespace std;

// TODO: put everything in the `seneca` namespace
namespace seneca
{
	/// <summary>
	/// The file descriptor; will be set when a file is open with
	///   `openFile`, and reset when the file is closed with `closeFile`.
	/// </summary>
	FILE* g_fptr;

	bool openFile(const char filename[])
	{
		bool allGood = false;
		if (g_fptr == nullptr)
		{
			g_fptr = fopen(filename, "r");
			allGood = g_fptr != nullptr;
		}
		return allGood;
	}

	void closeFile()
	{
		if (g_fptr)
		{
			fclose(g_fptr);
			g_fptr = nullptr;
		}
	}

	int getRecordsCount()
	{
		int noOfRecs = -1;

		if (g_fptr != nullptr)
		{
			// get current position in the file.
			auto currentPosition = ftell(g_fptr);

			// go to the begining of the file
			std::fseek(g_fptr, 0, SEEK_SET);

			// start counting from "0"
			noOfRecs = 0;

			// read from file a character at a time, and count '\n'
			char ch{};
			while (fscanf(g_fptr, "%c", &ch) == 1)
			{
				noOfRecs += (ch == '\n');
			}

			// done counting, reposition the cursor to the original location
			fseek(g_fptr, currentPosition, SEEK_SET);
		}
		return noOfRecs;
	}

	// TODO: define below all the functions from this module
	char* read(char delim)
	{
		int numChar = 0;
		auto position = ftell(g_fptr);
		char c = '\0';
		while (fscanf(g_fptr, "%c", &c) == 1 && c != delim)
		{
			numChar++;
		}

		fseek(g_fptr, position, SEEK_SET);

		char* token = nullptr;
		token = new char[numChar + 1](); // if array is not initialized properly then garbage values will also get appended to result
		int i = 0;
		char d = '\0';
		while (fscanf(g_fptr, "%c", &d) == 1 && d != delim)
		{
			token[i] = d;	
			i++;
		}
		return token; 
	}

	bool read(int& val, char delim) // pass reference to int; where the value is stored in first parameter
	{
		char* characterArr = seneca::read(delim);
		if (characterArr != nullptr)
		{
			val = atoi(characterArr);
			delete[] characterArr;
			characterArr = nullptr;
			return true;
		}
		else
		{
			return false;
		}
	}

	bool read(long& val, char delim) // pass reference to int; where the value is stored in first parameter
	{
		char* characterArr = seneca::read(delim);
		if (characterArr != NULL)
		{
			val = atol(characterArr);
			delete[] characterArr;
			characterArr = nullptr;
			return true;
		}
		else
		{
			return false;
		}
	}

	bool read(double& val, char delim) // pass reference to int; where the value is stored in first parameter
	{
		char* characterArr = seneca::read(delim);
		if (characterArr != NULL)
		{
			val = atof(characterArr);
			delete[] characterArr;
			characterArr = nullptr;
			return true;
		}
		else
		{
			return false;
		}
	}
}
