/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:41:37 by jomanuel          #+#    #+#             */
/*   Updated: 2026/02/16 17:35:18 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>
#include <limits>

class Fixed
{
	public:
		Fixed (void);
		~Fixed (void);
		Fixed(const Fixed&);
		Fixed& operator = (const Fixed&);
		Fixed (const int);
		Fixed (const float);

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		int toInt( void ) const;
		float toFloat( void ) const;

		bool operator== (const Fixed& other) const;
		bool operator> (const Fixed& other) const;
		bool operator< (const Fixed& other) const;
		bool operator>= (const Fixed& other) const;
		bool operator<= (const Fixed& other) const;
		bool operator!= (const Fixed& other) const;

		Fixed operator+ (const Fixed& other) const;
		Fixed operator- (const Fixed& other) const;
		Fixed operator* (const Fixed& other) const;
		Fixed operator/ (const Fixed& other) const;

		Fixed& operator++();    // ++obj
		Fixed& operator--();    // --obj
		Fixed operator++(int);  // obj++
		Fixed operator--(int);  // obj--

		static Fixed& min(Fixed& first, Fixed& second);
		static const Fixed& min(const Fixed& first, const Fixed& second);
		static Fixed& max(Fixed& first, Fixed& second);
		static const Fixed& max(const Fixed& first, const Fixed& second);
		
	private:
		int _num;
		static const int _FRACTIONAL_BITS = 8;
};

std::ostream& operator<< (std::ostream& os, const Fixed& v);

#endif