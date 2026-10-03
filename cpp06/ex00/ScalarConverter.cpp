/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 10:30:25 by jomanuel          #+#    #+#             */
/*   Updated: 2026/09/30 16:58:10 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	
}

ScalarConverter::ScalarConverter(ScalarConverter const &source)
{
	*this = source;
}

ScalarConverter::~ScalarConverter(void)
{
	
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &source)
{
	if (this != &source)
		(void) source;
	return *this;
}

static bool isChar(const std::string &input)
{
	return (input.length() == 1 && !std::isdigit(static_cast<unsigned char>(input[0])));
}

static bool isInt(const std::string &input)
{
	char *end;
	errno = 0;

	if (input.find_first_not_of("0123456789+-") != std::string::npos)
		return false;

	const long i = std::strtol(input.c_str(), &end, 10);
	
	if (*end != '\0' || errno == ERANGE)
		return false;
	
	if (i > INT_MAX || i < INT_MIN)
		return false;
	
	return true;
}

static bool isDouble(const std::string &input)
{
	char *end;

	if (input.find('.') == std::string::npos && input.find('e') == std::string::npos && input.find('E') == std::string::npos)
		return false;
	if (input.find_first_not_of("0123456789+-eE.") != std::string::npos)
		return false;

	const double d = std::strtod(input.c_str(), &end);
	
	if (*end != '\0')
		return false;
	if (d > DBL_MAX || d < -DBL_MAX)
		return false;
	
	return true;
}

static bool parseFloat(const std::string &input, float &f)
{
	std::istringstream stream(input);
	char suffix;

	if (!(stream >> f))
		return false;
	if (!(stream >> suffix) || suffix != 'f')
		return false;
	stream >> std::ws;
	return stream.eof();
}

static bool isFloat(const std::string &input)
{
	float f;

	if (input.find('.') == std::string::npos && input.find('e') == std::string::npos && input.find('E') == std::string::npos)
		return false;
	
	if (input.find_first_not_of("0123456789+-eE.f") != std::string::npos)
		return false;

	return parseFloat(input, f);
}

static t_type parse_input(const std::string &input)
{
	if (input.empty())
		return INVALID;
	
	if (input == "-inff" || input == "+inff" || input == "nanf" || input == "-inf" || input == "+inf" || input == "nan")
		return (PSEUDOLITERAL);
		
	if (isChar(input))
		return CHAR;
	
	if (isInt(input))
		return INT;

	if (isDouble(input))
		return DOUBLE;

	if (isFloat(input))
		return FLOAT;

	return INVALID;
}

static void print_char(const std::string &input)
{
	char c = input.at(0);
	
	if (std::isprint(static_cast<unsigned char>(c)))
		std::cout << "char: '" << input << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

static void print_int(const std::string &input)
{
	int i = std::atoi(input.c_str());
	
	if (i >= CHAR_MIN && i <= CHAR_MAX)
	{
		char c = static_cast<char>(i);
		
		if (std::isprint(static_cast<unsigned char>(c)))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << std::endl;
}

static void print_float(const std::string &input)
{
	float f;
	parseFloat(input, f);
	double d = static_cast<double>(f);

	if (d > static_cast<double>(CHAR_MIN) - 1.0 && d < static_cast<double>(CHAR_MAX) + 1.0)
	{
		char c = static_cast<char>(f);
		
		if (std::isprint(static_cast<unsigned char>(c)))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
	if (d > static_cast<double>(INT_MIN) - 1.0 && d < static_cast<double>(INT_MAX) + 1.0)
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

static void print_double(const std::string &input)
{
	double d = std::strtod(input.c_str(), NULL);

	if (d > static_cast<double>(CHAR_MIN) - 1.0 && d < static_cast<double>(CHAR_MAX) + 1.0)
	{
		char c = static_cast<char>(d);
		
		if (std::isprint(static_cast<unsigned char>(c)))
			std::cout << "char: '" <<  c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
	if (d > static_cast<double>(INT_MIN) - 1.0 && d < static_cast<double>(INT_MAX) + 1.0)
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	if (d >= -FLT_MAX && d <= FLT_MAX)
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	else
		std::cout << "float: impossible" << std::endl;
	std::cout << "double: " << d << std::endl;
}

static void print_pseudoliteral(const std::string &input)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	if (input == "nanf" || input == "+inff" || input == "-inff")
	{
		std::cout << "float: " << input << std::endl;
		std::cout << "double: " << input.substr(0, input.length() - 1) << std::endl;
	}
	else
	{
		std::cout << "float: " << input << "f" << std::endl;
		std::cout << "double: " << input << std::endl;
	}
}

static void print_invalid()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

static bool isIntegral(const std::string &input, t_type type)
{
	double d;
	double intPart;

	if (type == CHAR || type == INT)
		return true;
	if (type == FLOAT)
	{
		float f;

		if (!parseFloat(input, f))
			return false;
		d = static_cast<double>(f);
	}
	else if (type == DOUBLE)
		d = std::strtod(input.c_str(), NULL);
	else
		return false;
	return std::modf(d, &intPart) == 0.0;
}

void ScalarConverter::convert(std::string input)
{
	t_type type = parse_input(input);

	if (isIntegral(input, type))
		std::cout << std::fixed << std::setprecision(1);

	switch (type)
	{
		case CHAR:
			print_char(input);
			break;
			
		case INT:
			print_int(input);
			break;
			
		case FLOAT:
			print_float(input);
			break;
			
		case DOUBLE:
			print_double(input);
			break;
			
		case PSEUDOLITERAL:
			print_pseudoliteral(input);
			break;
			
		case INVALID:
			print_invalid();
			break;
			
		default:
			std::cout << "An error happened!" << std::endl;
	}
}
