#pragma once

#include <set>
#include "Common.h"

using namespace std;

struct DayFive
{
	void CompleteTask1()
	{
		vector<string> lines = readFile("Input/DayFive.txt");

		int maxSeatID = 0;

		for (string boardingPass : lines)
		{
			int seatID = getSeatID(boardingPass);

			maxSeatID = max(seatID, maxSeatID);
		}

		cout << "DAY 5 TASK 1: Max seat ID is " << maxSeatID << endl;
	}

	void CompleteTask2()
	{
		vector<string> lines = readFile("Input/DayFive.txt");

		int minSeatID = 892; // Found from task 1
		int maxSeatID = 0;

		set<int> seatIDs;

		for (string boardingPass : lines)
		{
			int seatID = getSeatID(boardingPass);
			seatIDs.insert(seatID);

			maxSeatID = max(seatID, maxSeatID);
			minSeatID = min(seatID, minSeatID);
		}

		for (int i(minSeatID + 1); i < maxSeatID; ++i)
		{
			if (seatIDs.find(i) == seatIDs.end())
			{
				cout << "DAY 5 TASK 2: My seat ID is " << i << endl;
				break;
			}
		}
	}

	int getSeatID(const string &boardingPass)
	{
		int seatID = 0;

		int row = getSeatRow(boardingPass);
		int col = getSeatColumn(boardingPass);

		seatID = (row * 8) + col;

		return seatID;
	}

	int getSeatRow(const string& boardingPass)
	{
		int row = 0;
		int min = 0;
		int max = 127;

		// Calculate middle
		int mid = (min + (max - 1)) / 2;

		string rowSequence = boardingPass.substr(0, 7);

		for (size_t i(0); i < rowSequence.length(); ++i)
		{
			mid = (min + (max - 1)) / 2;

			// Take lower half of current range
			if (rowSequence.at(i) == 'F')
			{
				max = mid;
				row = max;
			}
			// Take top half of current range
			else
			{
				min = mid + 1;
				row = min;
			}
		}

		return row;
	}

	int getSeatColumn(const string& boardingPass)
	{
		int column = 0;
		int min = 0;
		int max = 7;
		// Calculate middle
		int mid = (min + (max - 1)) / 2;

		string colSequence = boardingPass.substr(7, 3);

		for (size_t i(0); i < colSequence.length(); ++i)
		{
			mid = (min + (max - 1)) / 2;

			// Take lower half of current range
			if (colSequence.at(i) == 'L')
			{
				max = mid;
				column = max;
			}
			// Take top half of current range
			else
			{
				min = mid + 1;
				column = min;
			}
		}

		return column;
	}
};
