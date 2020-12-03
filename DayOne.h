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

		// If we haven't found the product
		if (final_product == 0)
		{
			std::map<int, int>::iterator iter;
			for (iter = number_to_target_map.begin(); iter != number_to_target_map.end(); ++iter)
			{
				int key = iter->first;
				int target = iter->second;

				if (number_to_target_map.find(target) != number_to_target_map.end())
				{
					// Found final product
					final_product = target * key;
					break;
				}
			}
		}

		std::cout << "DAY ONE: Product is " << final_product << std::endl;
		
	}
};
