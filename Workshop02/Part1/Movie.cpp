#include <iostream>
#include <cstring>
// TODO: include any other header that is necessary for your solution
#include "Movie.h"
#include "DataHandle.h"

using namespace std;

// TODO: put everything in the `seneca` namespace

namespace seneca
{
	/// <summary>
	/// The address of a dynamically-allocated array of
	///   objects of type `Movie`.  This array is the collection of
	///   movies the application manages.
	/// </summary>
	Movie* g_colMovies = nullptr;

	/// <summary>
	/// The number of `Movie` objects in the array `g_colMovies`.
	/// </summary>
	int g_cntMovies = 0;

	// TODO: define below all the functions from this module
	bool loadData(const char fileName[])
	{
		if (g_colMovies != NULL)
		{
			deallocateMemory();
		}

		if (!seneca::openFile(fileName))
		{
			return false;
		}
		else
		{
			g_cntMovies = seneca::getRecordsCount();
			g_colMovies = new Movie[g_cntMovies]();
			for (int cnt = 0; cnt < g_cntMovies; cnt++)
			{
				loadData(&g_colMovies[cnt]);
			}

			seneca::closeFile();
			return true;
		}
	}

	bool loadData(Movie* aMovie)
	{
		bool ok = false;
	
		if (seneca::read(aMovie->m_budget, ',') && seneca::read(aMovie->m_grossIncome, ',') && seneca::read(aMovie->m_rating, ',') && (aMovie->m_title = seneca::read('\n')) != NULL)
		{
			ok = true; // true if the data is read successfully
		}

		return ok;
	}

	void display(int idx)
	{
		if (idx >= g_cntMovies)
		{
			cout << "Index out of bounds." << endl;
		}
		else
		{
			cout << g_colMovies[idx].m_title << ", " << g_colMovies[idx].m_budget << ", $" << g_colMovies[idx].m_grossIncome << ", " << g_colMovies[idx].m_rating << endl;
		}
	}

	void display(const char label[], int startIdx, int endIdx)
	{
		// change the default of INT_MAX to the index of last value in array
		if (endIdx >= g_cntMovies)
		{
			endIdx = g_cntMovies - 1;
		}

		cout << "******** " << label << " ****************\n";
		for (int idx = startIdx; idx <= endIdx; idx++)
		{
			cout << ">> " << g_colMovies[idx].m_title << ", " << g_colMovies[idx].m_budget << ", $" << g_colMovies[idx].m_grossIncome << ", " << g_colMovies[idx].m_rating << endl;
		}
	}

	void deallocateMemory()
	{
		//deallocation of each movie title in the array of type Movie
		for (int i = 0; i < g_cntMovies; i++)
		{
			delete[] g_colMovies[i].m_title;
			g_colMovies[i].m_title = nullptr;
		}

		//deallocation of the array of type Movie
		delete[] g_colMovies;
		g_colMovies = nullptr;
		g_cntMovies = 0;
	}
}

