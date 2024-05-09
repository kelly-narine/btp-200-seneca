#ifndef SENECA_MARK_H
#define SENECA_MARK_H

namespace seneca 
{
	/// <summary>
	/// Record of a mark received by a student.
	/// </summary>
	struct Mark
	{
		/// <summary>
		/// The first name of the student.
		/// </summary>
		char m_firstName[20 + 1];
		/// <summary>
		/// The last name of the student.
		/// </summary>
		char m_lastName[30 + 1];
		/// <summary>
		/// The mark the student received (as a number between 0 and 100).
		/// </summary>
		int m_mark;
	};

	/// <summary>
	/// Populate the data for the graph to be displayed. Iterate through array of marks and allocate each
	/// mark to their respective interval. This will be stored in an array.
	/// </summary>
	/// <param name="marksArr">the address of an array with `MAX_NO_RECS` capacity
	///   that will receive the data from file</param> 
	/// <param name="graphDataArr">array to store data to be populated in graph</param>
	/// <param name="numRecords">number of records in the array of Mark</param> 
	void populateMarksInteveralData(Mark* marksArr, int graphData[], int numRecords);

	/// <summary>
	/// Bubble Sort (a Stable Sorting algorithm) the array of Mark objects based on the m_mark field
	/// in descending order.
	/// </summary>
	/// <param name="marksArr">the address of an array with `MAX_NO_RECS` capacity
	///   that will receive the data from file</param> 
	/// <param name="numRecords">number of records in the array of Mark</param>
	void sortMarks(Mark* marksArr, int numRecords);

	/// <summary>
	/// Output the sorted list of object of type Marks to screen. 
	/// </summary>
	/// <param name="marksArr">the address of an array with `MAX_NO_RECS` capacity
	///   that will receive the data from file</param> 
	/// <param name="numRecords">number of records in the array of Mark</param> 
	void printMarksList(Mark* marksArr, int numRecords);



	/* TODO: define the `printReport` function
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*
	* printReport()
	*
	* - use the function `seneca::openFile()` to open the file
	* - if the file is successfully open:
	*   - use the function `seneca::readMarks()` to load the content of the file
	*   - create an array with how many marks are in each interval
	*   - use the function `seneca::printGraph()` to print the *Bar Chart* with the
	*       number of marks in each interval
	*   - sort ascending the collection of marks based on the `m_mark` field
	*   - print all the marks in the sorted collection using the format
	*       `## : [MARK] FIRST_NAME LAST_NAME`
	*       (see sample output)
	*   - use the function `seneca::closeFile()` to close the file
	* - return true if the file was successfully open, false otherwise
	*
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*/

	/// <summary>
	/// This file prints a statistic report of the collection of marks
	/// found in a file. This function will count how many students have
	/// received marks in the interval 0%-10%, 10%-20%, 20%-30%, ..., 90%-100%.
	/// 
	/// Using a *Bar Chart*, this function will display the report in the following format:
	/// 
	/// +--- Students' Mark Distribution -----------------------------------+
	/// 100 | ************************* 3                                   |
	/// 90  | **************** 2                                            |
	/// 80  | ********************************* 4                           |
	/// 70  | ************************* 3                                   |
	/// 60  | ********************************* 4                           |
	/// 50  | ********************************* 4                           |
	/// 40  | ************************************************** 6          |
	/// 30  | *********************************************************** 7 |
	/// 20  | ************************* 3                                   |
	/// 10  | *********************************************************** 7 |
	/// +-------------------------------------------------------------------+
	/// 
	///   and then print the sorted list of all the marks found in the file.
	/// </summary>
	/// <param name="filename">stores the address of an array of characters
	///   representing the filename that holds the data with marks</param>
	/// <returns>true if the data files is opened successfully, false otherwise.</returns>
	bool printReport(const char* filename);
}

#endif 



