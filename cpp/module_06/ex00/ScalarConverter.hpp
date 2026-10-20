//
// Created by Aissam Abouqassime-Eledrissi on 1/13/25.
//
#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cfloat>

class ScalarConverter {
	private:
		static void toChar(double input, std::string remaining, std::string str);
		static void toInt(double input, std::string remaining, std::string str);
		static void toFloat(double input, std::string remaining, std::string str);
		static void toDouble(double input, std::string remaining, std::string str);
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &scalarConverter);
		ScalarConverter& operator=(const ScalarConverter &scalarConverter);
	public:
		static void convert(std::string str);
};