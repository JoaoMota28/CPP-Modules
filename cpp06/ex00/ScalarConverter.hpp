/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 10:30:28 by jomanuel          #+#    #+#             */
/*   Updated: 2026/09/30 17:05:07 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cctype>
#include <climits>
#include <cfloat>
#include <iomanip>
#include <cerrno>
#include <cstdlib>
#include <cmath>
#include <sstream>

typedef enum s_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDOLITERAL,
	INVALID
} t_type;

class ScalarConverter {
	public:
		static void convert(std::string input);

	private:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &source);
		~ScalarConverter(void);
		ScalarConverter &operator=(ScalarConverter const &source);
};

#endif
