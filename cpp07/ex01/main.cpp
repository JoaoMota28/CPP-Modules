/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 15:09:00 by jomanuel          #+#    #+#             */
/*   Updated: 2026/07/23 16:22:14 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template <typename T>
void printElem(const T& elem) {
	std::cout << elem << " ";
}

class Number {
private:
    int _n;

public:
    Number(void) : _n(0) {}
    Number(int n) : _n(n) {}
    int getValue(void) const { return this->_n; }
};

std::ostream &operator<<(std::ostream & o, Number const & instance) {
    o << instance.getValue();
    return o;
}

void addOne(int &n)
{
	n = n + 1;
}

int main(void)
{
	int arr[] = {0, 1, 2, 3, 4, 5};

	std::cout << "Initial Array: ";
	for (int i = 0; i < 6; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	
	std::cout << "Final Array: ";
	::iter(arr, 6, addOne);
	for (int i = 0; i < 6; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	
	
	const int new_arr[] = {5, 4, 3, 2, 1, 0};

	std::cout << "Array: ";
	::iter(new_arr, 6, printElem<int>);
	std::cout << std::endl;
	

	std::string str_arr[] = {"Hello", "42", "Lisboa", "C++"};

	std::cout << "String Array: ";
	::iter(str_arr, 4, printElem<std::string>);
	std::cout << std::endl;


	Number num_arr[3] = {Number(10), Number(20), Number(30)};

	std::cout << "Custom Class Array: ";
	::iter(num_arr, 3, printElem<Number>);
	std::cout << std::endl;

	return 0;
}
