#include <iostream>
#include "mark.h"
#include "file.h"
#include "io.h"
#include "graph.h"

namespace seneca 
{		
	void populateMarksInteveralData(Mark* marksArr, int graphDataArr[], int numRecords)
	{
		for (int cnt = 0; cnt < numRecords; cnt++)
		{
			if (marksArr[cnt].m_mark > 90)
			{
				graphDataArr[0]++;
			}
			else if (marksArr[cnt].m_mark > 80 && marksArr[cnt].m_mark <= 90)
			{
				graphDataArr[1]++;
			}
			else if (marksArr[cnt].m_mark > 70 && marksArr[cnt].m_mark <= 80)
			{
				graphDataArr[2]++;
			}
			else if (marksArr[cnt].m_mark > 60 && marksArr[cnt].m_mark <= 70)
			{
				graphDataArr[3]++;
			}
			else if (marksArr[cnt].m_mark > 50 && marksArr[cnt].m_mark <= 60)
			{
				graphDataArr[4]++;
			}
			else if (marksArr[cnt].m_mark > 40 && marksArr[cnt].m_mark <= 50)
			{
				graphDataArr[5]++;
			}
			else if (marksArr[cnt].m_mark > 30 && marksArr[cnt].m_mark <= 40)
			{
				graphDataArr[6]++;
			}
			else if (marksArr[cnt].m_mark > 20 && marksArr[cnt].m_mark <= 30)
			{
				graphDataArr[7]++;
			}
			else if (marksArr[cnt].m_mark > 10 && marksArr[cnt].m_mark <= 20)
			{
				graphDataArr[8]++;
			}
			else
			{
				graphDataArr[9]++;
			}
		}
	}

	// Bubble Sort (a Stable Sorting algorithm) the array and display the results in descending order
	void sortMarks(Mark* marksArr, int numRecords)
	{
		/*
		int iteration = numRecords;
		while (iteration > 0)
		{
			int k = 0;
			while (k < numRecords)
			{
				if (marksArr[k].m_mark < marksArr[k + 1].m_mark)
				{
					// comparison of two marks to switch places as needed (two adjacent marks in array)
					Mark* mark1 = &marksArr[k]; // Pointer point to address of the mark in array at specified index
					Mark* mark2 = &marksArr[k + 1];
					Mark tempMark = *mark1; // store the value of mark1 in a tempMark variable
					*mark1 = *mark2; // value of mark1 equal to the value of mark2
					*mark2 = tempMark; // value of mark2 equal to the value of tempMark
				}
				k++;
			}
			iteration--;
		}
		*/

		for (int i = 0; i < numRecords - 1; ++i)
		{
			for (int j = i + 1; j < numRecords; ++j)
			{
				if (marksArr[i].m_mark < marksArr[j].m_mark)
				{
					//Mark temp = marksArr[i];
					//marksArr[i] = marksArr[j];
					//marksArr[j] = temp;
					Mark* mark1 = &marksArr[i]; // Pointer point to address of the mark in array at specified index
					Mark* mark2 = &marksArr[j];
					Mark tempMark = *mark1; // store the value of mark1 in a tempMark variable
					*mark1 = *mark2; // value of mark1 equal to the value of mark2
					*mark2 = tempMark; // value of mark2 equal to the value of tempMark
				}
			}
		}

	}

	// output the sorted list of marks
	void printMarksList(Mark* marksArr, int numRecords)
	{
		for (int cnt = 0; cnt < numRecords; cnt++)
		{
			printInt(cnt + 1, 3);
			std::cout << ": [";
			printInt(marksArr[cnt].m_mark, 3);
			std::cout << "] " << marksArr[cnt].m_firstName << " " << marksArr[cnt].m_lastName << std::endl;
		}
		std::cout << "----------------------------------------" << std::endl;
	}

	bool printReport(const char* filename)
	{
		Mark marksArr[MAX_NO_RECS] = {};
		bool isOpen = seneca::openFile(filename);
		if (isOpen) 
		{
			int numRecords = seneca::readAllMarks(marksArr); 
			int graphDataArr[10] = {};
			populateMarksInteveralData(marksArr, graphDataArr, numRecords);
			printGraph(graphDataArr, 10, "Students' Mark Distribution");
			sortMarks(marksArr, numRecords);
			printMarksList(marksArr, numRecords);
	
			seneca::closeFile(); 
		}

		return isOpen;
	}

}
