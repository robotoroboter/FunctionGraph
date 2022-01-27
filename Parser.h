#pragma once
#include <iostream>
#include <string>	//for getline
#include <cmath>

class Parser
{
public:
	std::string removeSpaces(std::string formula);
	float compute(std::string formula, float argument);			//get the integer value of a polynomial function for an argument (x)
private:
	float calculate(float input1, float input2, char operation);	//perform mathematical operation on two arguments
	void error(std::string desc);
	bool isNumber(std::string expression);

	std::string symbols = "+-*/^";	//performable mathematical operations
};

