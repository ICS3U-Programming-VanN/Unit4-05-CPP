// Copyright (c) 2022 Van Nguyen All rights reserved.
//
// Created by: Van Nguyen
// Created on: November 10, 2022
// This program asks the user how many numbers they plan on adding.
// The user will then be able to add each number and then the program
// will display the sum of the numbers


#include <iostream>

int main() {
    // Initialize Variables
    int counter = 0;
    int sum = 0;

    // Declared Variables
    int totalNumberInt, userAddInt;
    float totalNumberFloat, userAddFloat;
    std::string sumMessage, totalNumberString, userAddString;

    // Asks user for how many numbers they plan to add
    std::cout << "Enter how many numbers you want to add: ";
    std::cin >> totalNumberString;

    // Checks for exceptions
    try {
        // Converts total number to integer
        totalNumberInt = stoi(totalNumberString);

        // Converts total number to float
        totalNumberFloat = stof(totalNumberString);

        // IF the user inputted a negative number or a number with decimals
        if (totalNumberInt < 0 || totalNumberInt != totalNumberFloat) {
            std::cout << "Please enter a whole number!\n" << std::endl;

        // If the user inputted a valid total numbers
        } else {
            // Makes sure that proper number of numbers are added
            // (asks user for all numbers to be added)
            while (counter < totalNumberInt) {
                // Asks user for what number they want to add
                std::cout << "Enter the number you want to add: ";
                std::cin >> userAddString;

                // Checks for exceptions
                try {
                    // Converts the user's number to an integer
                    userAddInt = stoi(userAddString);

                    // Converts the user's number to a float
                    userAddFloat = stof(userAddString);

                    // IF the user wanted to added a negative number
                    // or a number with decimals
                    if (userAddInt < 0 || userAddInt != userAddFloat) {
                        std::cout << "Please enter a whole number!\n"
                        << std::endl;

                        // Returns to the beginning of the loop
                        continue;

                    // If the user tried to zero
                    } else if (userAddInt == 0) {
                        std::cout << "0 <= 0, therefore it will not be added.\n"
                        << std::endl;

                        // Returns to the beginning of the loop
                        continue;

                    // If the user tries to add a valid number
                    } else {
                        // Displays to user what number will be added to the sum
                        std::cout << userAddInt <<
                        " will be added to the sum.\n" << std::endl;

                        // Increments the counter
                        counter++;

                        // Adds user's number to the sum
                        sum += userAddInt;

                        // Ensures that there will not be an empty plus symbol
                        // at the end of the sum message
                        if (counter != totalNumberInt) {
                            // Adds user's number to string that
                            // will later be displayed (with "+"s)
                            sumMessage += userAddString + " + ";

                        // ELSE statement meant to handle
                        // the last number the user plans to add
                        } else {
                            // Adds user's number to string
                            // that will later be displayed
                            sumMessage += userAddString;
                        }
                    }

                // In the event of an exception
                // with the number the user tried to add
                } catch (std::invalid_argument) {
                    std::cout << "Please enter a whole number!\n" << std::endl;
                }
            }
            // If-statement to account for the message if the total number is 0
            if (totalNumberInt != 0) {
                // Displays all the numbers added to sum (and the sum itself)
                std::cout << sumMessage << " = " << sum << std::endl;
            }

            // Displays sum to user
            std::cout << "Sum = " << sum << std::endl;
        }

    // In the event of an exception occurring with the user's total number
    } catch (std::invalid_argument) {
        std::cout << totalNumberString << " is not a valid number!\n"
        << std::endl;
    }

    // Final statement displayed to user regardless of inputs
    std::cout << "Thank you for using this program!" << std::endl;
}
