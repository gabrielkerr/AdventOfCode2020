#pragma once

#include <iostream>
#include "Common.h"

struct DayThree
{
	int slopeX = 3;
	int slopeY = 1;
	void CompleteTask1()
	{
		
		std::vector<std::string> lines = readFile("Input/DayThree.txt");

		int xPos = slopeX;
		int yPos = slopeY;
		int numTrees = 0;
		int maxLineIndex = lines[0].length() - 1;

		for (size_t i(yPos); i < lines.size(); ++i)
		{
			if (xPos > maxLineIndex)
			{
				int diff = xPos - maxLineIndex;
				xPos = diff - 1;
			}

			if (lines[i].at(xPos) == '#')
			{
				numTrees++;
			}

			xPos += slopeX;
			
			
		}

		std::cout << "DAY THREE TASK 1: " << numTrees << " trees." << std::endl;
	}
	
	void CompleteTask2()
	{
		
		std::vector<std::string> lines = readFile("Input/DayThree.txt");

		int maxLineIndex = lines[0].length() - 1;
		int treeProduct = 1;

		std::vector<std::vector<int> > slopes = { {1, 1}, {3, 1}, {5, 1}, {7, 1}, {1, 2} };

		for (size_t slope_ix(0); slope_ix < slopes.size(); ++slope_ix)
		{
			int numTrees = 0;
			int slopeX = slopes[slope_ix][0];
			int xPos = slopeX;
			int slopeY = slopes[slope_ix][1];
			int yPos = slopeY;
			
			for (size_t i(slopeY); i < lines.size(); i+=slopeY)
			{
				if (xPos > maxLineIndex)
				{
					int diff = xPos - maxLineIndex;
					xPos = diff - 1;
				}

				if (lines[i].at(xPos) == '#')
				{
					numTrees++;
				}

				xPos += slopeX;
			}

			treeProduct *= numTrees;
		}

		std::cout << "DAY THREE TASK 2: " << treeProduct << std::endl;
	}
};
