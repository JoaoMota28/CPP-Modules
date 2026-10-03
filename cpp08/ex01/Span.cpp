/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 17:12:44 by jomanuel          #+#    #+#             */
/*   Updated: 2026/10/03 11:23:29 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

const char *MaxNumbersException::what() const throw()
{
	return "Maximum number of integers that can be stored was reached.";
}

const char *NoSpanException::what() const throw()
{
	return "This list does not have enough values to have a span.";
}

Span::Span() : _size(0), _v()
{
	
}

Span::Span(unsigned int N) : _size(N), _v()
{
	_v.reserve(N);
}

Span::~Span()
{
	
}

Span::Span(const Span &src) : _size(src._size), _v(src._v)
{
	
}

Span &Span::operator=(const Span &src)
{
	if (this != &src)
	{
		this->_size = src._size;
		this->_v = src._v;
	}
	
	return *this;
}
	
void Span::addNumber(int n)
{
	if (_v.size() < _size)
		_v.push_back(n);
	else
		throw MaxNumbersException();
}

unsigned int Span::shortestSpan() const
{
	if (_v.size() < 2)
		throw NoSpanException();
	else
	{
		std::vector<int> s(_v);
		std::sort(s.begin(), s.end());
		
		unsigned int min = std::numeric_limits<unsigned int>::max();
		
		for (std::vector<int>::const_iterator it = s.begin() + 1; it != s.end(); ++it)
		{
			unsigned int diff = static_cast<unsigned int>(*it) - static_cast<unsigned int>(*(it - 1));
			if (diff < min)
				min = diff;
		}

		return min;
	}
}

unsigned int Span::longestSpan() const
{
	if (_v.size() < 2)
		throw NoSpanException();
	else
		return (static_cast<unsigned int>(*std::max_element(_v.begin(), _v.end())) - static_cast<unsigned int>(*std::min_element(_v.begin(), _v.end())));
}
