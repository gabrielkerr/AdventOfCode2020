#pragma once

#include <iostream>
#include <map>

#include "Common.h"

struct DayOne
{
	uint32_t Target = 2020;

	void CompleteTask1()
	{
		std::vector<std::string> sNumbers = readFile("Input/DayOne.txt");
		std::map<int, int> number_to_target_map;
		int final_product = 0;

		// Iterate through strings
		for (size_t i = 0; i < sNumbers.size(); ++i)
		{
			// Assign each number to its target counterpart
			const char* sNum = sNumbers[i].c_str();
			int key_num = atoi(sNum);
			int target_num = Target - key_num;
			number_to_target_map.emplace(std::pair<int, int>(key_num, target_num));

			// Check if the target num is already a key in the map
			if (number_to_target_map.find(target_num) != number_to_target_map.end())
			{
				// Found final product
				final_product = target_num * key_num;
				break;
			}
		}

		std::cout << "DAY ONE TASK 1: Product is " << final_product << std::endl;
		
	}

	void CompleteTask2()
	{
		std::vector<std::string> sNumbers = readFile("Input/DayOne.txt");
		std::map<int, int> number_to_target_map;
		std::map<int, int> number_to_secondary_target_map;
		std::vector<int> number_list;
		int final_product = 0;

		// Iterate through strings
		for (size_t i = 0; i < sNumbers.size(); ++i)
		{
			// Assign each number to its target counterpart
			const char* sNum = sNumbers[i].c_str();
			int key_num = atoi(sNum);
			number_list.push_back(key_num);
			int target_num = Target - key_num;
			number_to_target_map.emplace(std::pair<int, int>(key_num, target_num));
		}

		// If we haven't found the product
		std::map<int, int>::iterator iter;
		for (iter = number_to_target_map.begin(); iter != number_to_target_map.end(); ++iter)
		{
			int secondary_target = iter->second;
			number_to_secondary_target_map.clear();

			// Make primary map
			for (size_t i = 0; i < number_list.size(); ++i)
			{
				int key_num = number_list[i];
				int val = secondary_target - key_num;

				if (val > 0)
				{
					number_to_secondary_target_map[key_num] = val;
				}

				if (number_to_secondary_target_map.find(val) != number_to_secondary_target_map.end())
				{
					final_product = iter->first * key_num * val;
					break;
				}
			}

			if (final_product > 0)
			{
				break;
			}
		}

		std::cout << "DAY ONE PART 2: Product is " << final_product << std::endl;
		
	}
};
