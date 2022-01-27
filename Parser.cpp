#include "Parser.h"

std::string Parser::removeSpaces(std::string formula) {
	std::string newFormula;
	for (int i = 0; i < formula.length(); i++) {
		if (formula[i] != ' ')
			newFormula += formula[i];
	}
	return newFormula;
}

float Parser::compute(std::string formula, float argument) {
	int bracket_number = 0;
	for (char symbol : symbols) {
		for (int i = formula.length() - 1; i >= 0; i--) {	//searching for the symbol in the formula
			if (formula[i] == ')') {
				bracket_number++;
			}
			else if (formula[i] == '(') {
				bracket_number--;
			}
			else if (formula[i] == symbol and bracket_number == 0) {
				float part1;
				if (symbol == '-' and i == 0) //for negative numbers (dont treat negative as subtraction)
					part1 = 0;
				else
					part1 = compute(formula.substr(0, i), argument);
				float part2 = compute(formula.substr(i + 1, formula.length() - i - 1), argument);
				float result = calculate(part1, part2, symbol);
				return result;
			}
		}
		if (bracket_number != 0)
			error("unclosed brackets in the formula");
	}
	if (formula[0] == '(' and formula[formula.length() - 1] == ')')	//removing the brackets
		return compute(formula.substr(1, formula.length() - 2), argument);
	if (formula == "x")
		return argument;
	if (isNumber(formula))
		return std::stoi(formula);
	else
		error("unknown expression in the formula: " + formula);
}

float Parser::calculate(float input1, float input2, char operation) {
	switch (operation) {
	case '+':
		return input1 + input2;
	case '-':
		return input1 - input2;
	case '*':
		return input1 * input2;
	case '/':
		return input1 / input2;
	case '^':
		return pow(input1, input2);
	}
}

void Parser::error(std::string desc) {
	std::cout << "Error: " << desc << std::endl;
	system("pause");
	exit(-1);

}

bool Parser::isNumber(std::string sequence) {
	bool isNegative = 0;
	if (sequence[0] == '-')
		isNegative = 1;
	while (sequence[0 + isNegative] == '0') {	//removing unnecessary zeros at the beginning (after the optional minus sign)
		sequence = sequence.substr(1 + isNegative, sequence.length() - 1 - isNegative); //if there's the minus sign, it will be removed
	}
	if (isNegative)
		sequence = '-' + sequence; //bringing back the minus sign
	int expresionToInt;
	try {
		expresionToInt = std::stoi(sequence);
	}
	catch (...) {
		error("(exception while checking if a number) unknown expression in the sequence of characters: " + sequence);
	}
	std::string expressionNewString = std::to_string(expresionToInt);
	if (expressionNewString == sequence)
		return true;
	else
		return false;
}