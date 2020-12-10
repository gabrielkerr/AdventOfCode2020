#pragma once


#include <iostream>
#include <map>
#include <set>

#include "Common.h"

using namespace std;

struct DayFour
{
	void CompleteTask1()
	{
		vector<string> lines = readFile("Input/DayFour.txt");
		int numValidPassports = 0;
		
		// If no cid, that's okay
		// If any other field is mising, BATSU
		set<string> requiredSet = { "byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid" }; // cid is optional
		set<string> passportSet;
		
		int i = 0;
		for (string line : lines)
		{
			// If new line, check passport
			if (line.length() == 0)
			{
				i++;
				if (passportSet == requiredSet)
				{
					numValidPassports++;
				}

				passportSet.clear();
			}
			// Split line into fields and add to passportSet
			else
			{
				vector<string> fieldValuePairs = split(line, ' ');
				for (string fv : fieldValuePairs)
				{
					vector<string> pair = split(fv, ':');
					if (pair[0] != "cid") // cid is optional
					{
						passportSet.insert(pair[0]);
					}
				}
			}
		}

		cout << "DAY FOUR TASK 1: " << numValidPassports << " valid passports." << endl;
	}

	void CompleteTask2()
	{
		vector<string> lines = readFile("Input/DayFour.txt");
		int numValidPassports = 0;
		
		// If no cid, that's okay
		// If any other field is mising, BATSU
		set<string> requiredSet = { "byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid" }; // cid is optional
		set<string> passportSet;
		map<string, string> passportData;
		
		int i = 0;
		for (string line : lines)
		{
			// If new line, check passport
			if (line.length() == 0)
			{
				i++;
				if (passportSet == requiredSet)
				{
					// More validation required
					// Validate byr (To number between 1920 - 2002) // is digit
					if (!isBYRValid(passportData["byr"]))
					{
						break;	
					}
					// Validate iyr (To number between 2010 - 2020) // is digit
					if (!isIYRValid(passportData["iyr"]))
					{
						break;	
					}
					// Validate eyr (To number between 2020 - 2030) // is digit
					if (!isEYRValid(passportData["eyr"]))
					{
						break;	
					}
					// Validate hgt (ends in cm or in, 150-193 and 59-76 respectively) // std::string.find, string::npos, std::string.substr
					// Validate hcl (# followed by 6 chars, 0-9, a-f) // is digit
					// Validate ecl (One of amb, blu, brn, gry, grn, hzl, oth) Use a set
					// Validate pid (9 digit number including leading 0s)
					numValidPassports++;
				}

				passportSet.clear();
			}
			// Split line into fields and add to passportSet
			else
			{
				vector<string> fieldValuePairs = split(line, ' ');
				for (string fv : fieldValuePairs)
				{
					vector<string> pair = split(fv, ':');
					if (pair[0] != "cid") // cid is optional
					{
						passportSet.insert(pair[0]);
						passportData[pair[0]] = pair[1];
					}
				}
			}
		}

		cout << "DAY FOUR TASK 2: " << numValidPassports << " TRULY valid passports." << endl;
	}

	bool isBYRValid(const string& byr)
	{
		bool valid = false;
		if (isStringNumber(byr))
		{
			int numByr = atoi(byr.c_str());
			if (isNumberWithinRange(numByr, 1920, 2002))
			{
				valid = true;
			}
		}

		return valid;
	}

	bool isIYRValid(const string& iyr)
	{
		bool valid = false;
		if (isStringNumber(iyr))
		{
			int numIyr = atoi(iyr.c_str());
			if (isNumberWithinRange(numIyr, 2010, 2020))
			{
				valid = true;
			}
		}

		return valid;
	}

	bool isEYRValid(const string& eyr)
	{
		bool valid = false;
		if (isStringNumber(eyr))
		{
			int numEyr = atoi(eyr.c_str());
			if (isNumberWithinRange(numEyr, 2020, 2030))
			{
				valid = true;
			}
		}

		return valid;
	}
};
