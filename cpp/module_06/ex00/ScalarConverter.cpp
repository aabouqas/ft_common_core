#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string str) {
	double	number;
	char	*remaining = NULL;


	std::cout << std::fixed << std::setprecision(1);

	number = std::strtod(str.c_str(), &remaining);

    if (str.length() == 1 && !isdigit(*str.c_str())) {
        char c = *str.c_str();
        if (isprint(c))
            std::cout << "char: '" << c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;

        std::cout << "int: " << static_cast<int> (c) << std::endl;
        std::cout << "float : " << static_cast<float> (c) << 'f' << std::endl;
        std::cout << "double : " << static_cast<double> (c) << std::endl;
        return ;
    }
	toChar(number, remaining, str);
	toInt(number, remaining, str);
	toFloat(number, remaining, str);
	toDouble(number, remaining, str);
}

void ScalarConverter::toChar(double input, std::string remaining, std::string str) {
	char c;

    if (!remaining.empty() && (remaining != "f" || (remaining == "f" && str.find('.') == std::string::npos))) {
        std::cout << "char: impossible" << std::endl;
        return ;
    }

	if (input < 0 || input > CHAR_MAX || isnan(input)) {
		std::cout << "char: impossible" << std::endl;
		return ;
	}

	c = static_cast<char> (input);

	if (!isprint(c)) {
		std::cout << "char: Non displayable" << std::endl;
		return ;
	}
	std::cout << "char: '" << c << "'" << std::endl;
}

void ScalarConverter::toInt(double input, std::string remaining, std::string str) {
	int number;

    if (!remaining.empty() && (remaining != "f" || (remaining == "f" && str.find('.') == std::string::npos))) {
        std::cout << "int: impossible" << std::endl;
        return ;
    }

	if ((input > INT_MAX || input < INT_MIN) || isnan(input)) {
		std::cout << "int: impossible" << std::endl;
		return ;
	}

	number = static_cast<int> (input);
	std::cout << "int: " << number << std::endl;
}

void ScalarConverter::toFloat(double input, std::string remaining, std::string str) {
	float number;

    if (!remaining.empty() && (remaining != "f" || (remaining == "f" && str.find('.') == std::string::npos))) {
        std::cout << "float: impossible" << std::endl;
        return ;
    }

	number = static_cast<float> (input);

	std::cout << "float: " << number << "f" << std::endl;
}

void ScalarConverter::toDouble(double input, std::string remaining, std::string str) {

    if (!remaining.empty() && (remaining != "f" || (remaining == "f" && str.find('.') == std::string::npos))) {
        std::cout << "double: impossible" << std::endl;
        return ;
    }
	std::cout << "double: " << input << std::endl;
}


ScalarConverter::ScalarConverter() {
}

ScalarConverter::~ScalarConverter() {

}

ScalarConverter::ScalarConverter(const ScalarConverter &scalarConverter) {
	*this = scalarConverter;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &scalarConverter) {
	(void) scalarConverter;
	return *this;
}
