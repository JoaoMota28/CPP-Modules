/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 16:34:48 by jomanuel          #+#    #+#             */
/*   Updated: 2026/07/23 19:41:01 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <cstddef>

template <typename T>
class Array
{
	public:
		Array() : _size(0), _array(NULL) {}
		
		Array(unsigned int n) : _size(n), _array( (n > 0) ? new T[n]() : NULL ) {}
		
		Array(Array<T> const &src) : _size(src._size)
		{
			this->_array = (this->_size > 0) ? new T[this->_size] : NULL;
			for (std::size_t i = 0; i < src._size; i++)
				this->_array[i] = src._array[i];
		}
		
		~Array() { delete[] _array; }
		
		Array &operator=(Array const &src)
		{
			if (this != &src)
			{
				T* newArray = (src._size > 0) ? new T[src._size] : NULL;

				for (std::size_t i = 0; i < src._size; i++)
					newArray[i] = src._array[i];

				delete[] this->_array;
				this->_array = newArray;
				this->_size = src._size;
			}
			return *this;
		}

		T& operator[](unsigned int ind)
		{
			if (ind >= _size)
				throw std::out_of_range("Index out of bounds");
			else
				return _array[ind];
		}
		
		const T& operator[](unsigned int ind) const
		{
			if (ind >= _size)
				throw std::out_of_range("Index out of bounds");
			else
				return _array[ind];
		}

		std::size_t size() const { return _size; };
	
	private:
		std::size_t _size;
		T* _array;
};

#endif
