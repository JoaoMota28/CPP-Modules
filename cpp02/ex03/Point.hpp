/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 19:36:27 by jomanuel          #+#    #+#             */
/*   Updated: 2026/03/04 11:18:32 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <cmath>
#include <limits>
#include "Fixed.hpp"

class Point
{
	public:
		Point(void);
		Point(Fixed x, Fixed y);
		~Point();
		Point(const Point&);
		Point& operator=(const Point&);
		Fixed getx() const;
		Fixed gety() const;

	private:
		Fixed const _x;
		Fixed const _y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif