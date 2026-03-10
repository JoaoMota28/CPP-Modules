/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:41:39 by jomanuel          #+#    #+#             */
/*   Updated: 2026/02/17 15:50:02 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed (void) : _num(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed (void)
{
	//std::cout << "Destructor called" << std::endl;
}


Fixed::Fixed(const Fixed& other) : _num(other.getRawBits())
{
	//std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_num = other.getRawBits();
	return *this;
}

Fixed::Fixed (const int val)
{
	if (val > (std::numeric_limits<int>::max() >> _FRACTIONAL_BITS)  || val < (std::numeric_limits<int>::min() >> _FRACTIONAL_BITS))
	{
		std::cout << "Value cannot be represented, set to 0" << std::endl;
		_num = 0;
	}
	else
		_num = val << _FRACTIONAL_BITS;
}

Fixed::Fixed (const float val)
{
	if (val > (std::numeric_limits<int>::max() >> _FRACTIONAL_BITS)  || val < (std::numeric_limits<int>::min() >> _FRACTIONAL_BITS))
	{
		std::cout << "Value cannot be represented, set to 0" << std::endl;
		_num = 0;
	}
	else
		_num = static_cast<int>(round(val * (1 << _FRACTIONAL_BITS)));
}

int Fixed::getRawBits( void ) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return _num;
}

void Fixed::setRawBits( int const raw )
{
	//std::cout << "setRawBits member function called" << std::endl;
	_num = raw;
}

// Add / Subtract 0.5 to truncate to correct rounded integer

int Fixed::toInt( void ) const
{
	if (_num >= 0)
		return (_num + (1 << (_FRACTIONAL_BITS - 1))) >> _FRACTIONAL_BITS;
	else
		return (_num - (1 << (_FRACTIONAL_BITS - 1))) >> _FRACTIONAL_BITS;
}

float Fixed::toFloat( void ) const
{
	return static_cast<float>(_num) / (1 << _FRACTIONAL_BITS);
}

std::ostream& operator<< (std::ostream& os, const Fixed& v)
{
	return os << v.toFloat();
}

bool Fixed::operator== (const Fixed& other) const
{
	return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator> (const Fixed& other) const
{
	return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator< (const Fixed& other) const
{
	return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator>= (const Fixed& other) const
{
	return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator<= (const Fixed& other) const
{
	return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator!= (const Fixed& other) const
{
	return this->getRawBits() != other.getRawBits();
}

Fixed Fixed::operator+ (const Fixed& other) const
{
	Fixed result;
	result.setRawBits(this->getRawBits() + other.getRawBits());
	return result;
}

Fixed Fixed::operator- (const Fixed& other) const
{
	Fixed result;
	result.setRawBits(this->getRawBits() - other.getRawBits());
	return result;
}

Fixed Fixed::operator* (const Fixed& other) const
{
	Fixed result;
	result.setRawBits((this->getRawBits() * other.getRawBits()) >> _FRACTIONAL_BITS);
	return result;
}

Fixed Fixed::operator/ (const Fixed& other) const
{
	Fixed result;
	result.setRawBits((this->getRawBits() << _FRACTIONAL_BITS) / other.getRawBits());
	return result;
}

Fixed& Fixed::operator++()
{
	this->_num++;
	return *this;
}

Fixed& Fixed::operator--()
{
	this->_num--;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->_num++;
	return temp;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->_num--;
	return temp;
}

Fixed& Fixed::min(Fixed& first, Fixed& second)
{
	if (first < second)
		return first;
	return second;
}

const Fixed& Fixed::min(const Fixed& first, const Fixed& second)
{
	if (first < second)
		return first;
	return second;
}

Fixed& Fixed::max(Fixed& first, Fixed& second)
{
	if (first > second)
		return first;
	return second;
}

const Fixed& Fixed::max(const Fixed& first, const Fixed& second)
{
	if (first > second)
		return first;
	return second;
}
