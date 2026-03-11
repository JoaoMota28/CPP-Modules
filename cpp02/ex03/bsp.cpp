/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 19:36:32 by jomanuel          #+#    #+#             */
/*   Updated: 2026/03/11 15:10:29 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Fixed cross_product(Point const m, Point const n)
{
	return (m.getx() * n.gety()) - (m.gety() * n.getx());
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed fa = cross_product(Point(b.getx() - a.getx(), b.gety() - a.gety()), 
		Point(point.getx() - a.getx(), point.gety() - a.gety()));
	Fixed fb = cross_product(Point(c.getx() - b.getx(), c.gety() - b.gety()), 
		Point(point.getx() - b.getx(), point.gety() - b.gety()));
	Fixed fc = cross_product(Point(a.getx() - c.getx(), a.gety() - c.gety()), 
		Point(point.getx() - c.getx(), point.gety() - c.gety()));
	
	if (fa > 0 && fb > 0 && fc > 0)
		return true;
	else if (fa < 0 && fb < 0 && fc < 0)
		return true;
	return false;
}
