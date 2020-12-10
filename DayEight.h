#pragma once

#include "Common.h"
#include <iostream>
#include <map>

using namespace std;

struct DayEight
{
	void CompleteTask1()
	{
		vector<string> instructions = readFile("Input/DayEight.txt");
		size_t numInstructions = instructions.size();

		vector<int> visited(numInstructions, 0);

		size_t i = 0;
		size_t increment = 1;
		int accumulator = 0;
		
		while (i < instructions.size())
		{
			// Check if we have already visited this instruction
			if (visited[i] != 0)
			{
				break;
			}
			visited[i] = 1;

			increment = 1;

			string instruction = instructions[i];
			string op = split(instruction, ' ')[0];

			if (op != "nop")
			{
				string valString = split(instruction, ' ')[1];
				int val = atoi(valString.substr(1).c_str());
				if (valString.at(0) == '-')
				{
					val *= -1;
				}

				// Update increment
				if (op == "acc")
				{
					accumulator += val;
				}
				else if (op == "jmp")
				{
					increment = val;
				}
			}

			i += increment;
		}

		cout << "DAY EIGHT TASK 1: Accumulator is " << accumulator << endl;
	}

	void CompleteTask2()
	{
		vector<string> instructions = readFile("Input/DayEight.txt");
		size_t numInstructions = instructions.size();

		vector<int> visited(numInstructions, 0);

		size_t i = 0;
		size_t increment = 1;
		int accumulator = 0;
		bool testing = true;
		set<size_t> testedIndices;
		
		while (i < instructions.size())
		{
			// Check if we have already visited this instruction
			// Reset everything if we have.
			if (visited[i] != 0)
			{
				i = 0;
				accumulator = 0;
				testing = true;
				std::fill(visited.begin(), visited.end(), 0);
			}
			visited[i] = 1;

			increment = 1;

			string instruction = instructions[i];
			string op = split(instruction, ' ')[0];
			string valString = split(instruction, ' ')[1];
			int val = atoi(valString.substr(1).c_str());
			if (valString.at(0) == '-')
			{
				val *= -1;
			}

			if (op != "nop")
			{

				// Update increment
				if (op == "acc")
				{
					accumulator += val;
				}
				else if (op == "jmp")
				{
					if (testing && testedIndices.find(i) == testedIndices.end())
					{
						// Do nothing
						testing = false;
						testedIndices.insert(i);
					}
					else
					{
						increment = val;
					}
				}
			}
			else if (testing && testedIndices.find(i) == testedIndices.end())
			{
				testing = false;
				testedIndices.insert(i);
				increment = val;
			}

			i += increment;
		}

		cout << "DAY EIGHT TASK 2: Accumulator is " << accumulator << endl;
	}
};
