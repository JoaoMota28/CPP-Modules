/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 19:36:29 by jomanuel          #+#    #+#             */
/*   Updated: 2026/03/04 11:13:09 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(Fixed(0)), _y(Fixed(0))
{

}

Point::Point(Fixed x, Fixed y) : _x(Fixed(x)), _y(Fixed(y))
{
	
}

Point::~Point()
{
	
}

Point::Point(const Point& other) : _x(other._x), _y(other._y)
{
	
}

Point& Point::operator=(const Point& other)
{
	(void) other;
	return *this;
}

Fixed Point::getx() const
{
	return _x;
}

Fixed Point::gety() const
{
	return _y;
}