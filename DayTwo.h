#pragma once

#include <iostream>
#include "Common.h"

struct DayTwo
{
	void CompleteTask1()
	{
		std::vector<std::string> input = readFile("Input/DayTwo.txt");

		int valid_count = 0;

		// Process lines
		for (size_t i(0); i < input.size(); ++i)
		{
			std::vector<std::string> split_line = split(input[i], ' ');
			std::string frequency_string = split_line[0];
			int min_freq = atoi(split(frequency_string, '-')[0].c_str());
			int max_freq = atoi(split(frequency_string, '-')[1].c_str());
			char letter_req = split_line[1].at(0);
			std::string password = split_line[2];

			// Check for valid password
			int letter_req_count = 0;
			for (size_t pw_ix(0); pw_ix < password.length(); ++pw_ix)
			{
				if (letter_req == password.at(pw_ix))
				{
					letter_req_count++;
				}
			}

			if (letter_req_count >= min_freq && letter_req_count <= max_freq)
			{
				valid_count++;
			}
		}

		std::cout << "DAY TWO TASK 1: " << valid_count << " valid passwords." << std::endl;
	}

	void CompleteTask2()
	{
		std::vector<std::string> input = readFile("Input/DayTwo.txt");

		int valid_count = 0;

		// Process lines
		for (size_t i(0); i < input.size(); ++i)
		{
			std::vector<std::string> split_line = split(input[i], ' ');
			std::string frequency_string = split_line[0];
			int pos_1 = atoi(split(frequency_string, '-')[0].c_str());
			int pos_2 = atoi(split(frequency_string, '-')[1].c_str());
			char letter_req = split_line[1].at(0);
			std::string password = split_line[2];

			// Check for valid password
			if ((letter_req == password.at(pos_1 - 1)) ^ (letter_req == password.at(pos_2 - 1)))
			{
				valid_count++;
			}
		}

		std::cout << "DAY TWO TASK 2: " << valid_count << " valid passwords." << std::endl;
	}
};
