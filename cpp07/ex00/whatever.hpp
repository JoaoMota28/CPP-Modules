/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 12:28:01 by jomanuel          #+#    #+#             */
/*   Updated: 2026/07/23 15:04:54 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T& x, T& y) {
	T temp = x;
	x = y;
	y = temp;
}

template <typename T>
const T& min(const T& x, const T& y) {
	return (x < y) ? x : y;
}

template <typename T>
const T& max(const T& x, const T& y) {
	return (x > y) ? x : y;
}

#endif
