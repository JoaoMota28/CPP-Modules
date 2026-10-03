/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 17:12:18 by jomanuel          #+#    #+#             */
/*   Updated: 2026/10/03 11:25:41 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <algorithm>
#include <limits>
#include <iterator>

class MaxNumbersException : public std::exception {
	public:
		virtual const char *what() const throw();
};

class NoSpanException : public std::exception {
	public:
		virtual const char *what() const throw();
};

class Span {
	public:
		Span();
		Span(unsigned int N);
		~Span();
		Span(const Span &);
		Span &operator=(const Span &);
	
		void addNumber(int);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;

		template <typename InputIterator>
		void addRange(InputIterator begin, InputIterator end)
		{
			std::vector<int>::size_type count = std::distance(begin, end);
			
			if (count > _size - _v.size())
				throw MaxNumbersException();
			else
				_v.insert(_v.end(), begin, end);
		}

	private:
		unsigned int _size;
		std::vector<int> _v;
	
};

#endif
