#ifndef UTILITY_H_
#define UTILITY_H_

#include <iostream>
#include <iomanip>
#include <memory>
#include <string>
#include "Investment.h"

using namespace std;

// Function to get a valid double input from the user
double getValidDoubleInput(const string& prompt);

// Function to get a valid integer input from the user
int getValidIntInput(const string& prompt);

// Function to get a valid character input from the user
char getValidCharInput(const string& prompt);

// Get Initial Investment Data, Will return an instance of Investment class
unique_ptr<Investment> getInitialData();

#endif // UTILITY_H_