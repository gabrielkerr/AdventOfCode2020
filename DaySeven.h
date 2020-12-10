#pragma once

#include "Common.h"
#include <iostream>
#include <algorithm>
#include <deque>
#include <map>
#include <set>

using namespace std;

struct DaySeven
{
	void CompleteTask1()
	{
		vector<string> lines = readFile("Input/DaySeven.txt");
		
		map<string, set<string> > bag_to_containers_map;
		map<string, set<string> > bag_to_children_map;

		for (string line : lines)
		{
			// Containing bag ends 2 spaces before "contains" 
			size_t ruleSplitPos = line.find("contain") - 1;
			string containingBag = line.substr(0, ruleSplitPos);
			size_t colorEndPos = containingBag.find("bag") - 1;
			string containingColor = containingBag.substr(0, colorEndPos);

			// Parse inner bags
			string innerBagString = line.substr(ruleSplitPos + 9);
			vector<string> bags = split(innerBagString, ',');

			if (containingColor == "shiny yellow")
			{
				cout << "SHINY YELLOW" << endl;
			}
	
			for (string bag : bags)
			{
				removePunctuationFromString(bag);
				ltrim(bag);
				rtrim(bag);

				// If bag does not specify a number, contains no other bags
				if (!(isdigit(bag.at(0))))
				{
					continue;
				}

				// Get number and color
				size_t colorBeginPos = bag.find(" ") + 1;
				colorEndPos = bag.find("bag") - 1;
				size_t numberEndPos = colorBeginPos - 1;

				string bagColor = bag.substr(colorBeginPos, colorEndPos - colorBeginPos);

				bag_to_containers_map[bagColor].insert(containingColor);
				bag_to_children_map[containingColor].insert(bagColor);
			}

		}

		set<string> bagsWithGold = bag_to_containers_map["shiny gold"];

		deque<string> q;
		for (string bag : bagsWithGold)
		{
			q.push_back(bag);
		}

		while (!q.empty())
		{
			// What contains these colors?
			string color = q.front();
			set<string> otherColors = bag_to_containers_map[color];
			for (string otherColor : otherColors)
			{
				if (bagsWithGold.find(otherColor) == bagsWithGold.end())
				{
					q.push_back(otherColor);
				}
			}

			bagsWithGold.insert(color);

			q.pop_front();
		}

		std::cout << bagsWithGold.size() << std::endl;
	}
};