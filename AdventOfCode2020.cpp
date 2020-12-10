// AdventOfCode2020.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "DayOne.h"
#include "DayTwo.h"
#include "DayThree.h"
#include "DayFour.h"
#include "DayFive.h"

#include "DaySeven.h"
#include "DayEight.h"

int main()
{
    DayOne day_one;
    day_one.CompleteTask1();
    day_one.CompleteTask2();
    
    DayTwo day_two;
    day_two.CompleteTask1();
    day_two.CompleteTask2();

    DayThree day_three;
    day_three.CompleteTask1();
    day_three.CompleteTask2();

    DayFour day_four;
    day_four.CompleteTask1();
    //--------------------//

    DayFive day_five;
    day_five.CompleteTask1();
    day_five.CompleteTask2();

    // DaySix
    //--------------------//
    //--------------------//

    DaySeven day_seven;
    day_seven.CompleteTask1();
    //--------------------//

    DayEight day_eight;
    day_eight.CompleteTask1();
    day_eight.CompleteTask2(); // Needs a fix

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
