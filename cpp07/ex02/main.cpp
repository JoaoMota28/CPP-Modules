/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 16:34:45 by jomanuel          #+#    #+#             */
/*   Updated: 2026/07/23 19:39:26 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <exception>
#include "Array.hpp"

template <typename T>
void printArray(const Array<T>& arr, const std::string& name) {
    std::cout << name << " (size: " << arr.size() << "): [ ";
    for (unsigned int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "]" << std::endl;
}

int main() {
    
    Array<int> empty;
    std::cout << "Empty array size: " << empty.size() << std::endl;
    
	
    Array<int> numbers(5);
    printArray(numbers, "Default zero-initialized ints");


    for (unsigned int i = 0; i < numbers.size(); i++) {
        numbers[i] = (i + 1) * 10;
    }
    printArray(numbers, "Modified ints");

    
    Array<int> copyConst(numbers);
    Array<int> assigned;
    assigned = numbers;


    numbers[0] = 999;

    printArray(numbers,     "Original numbers (modified [0] -> 999)");
    printArray(copyConst,   "Copy Constructor (should be 10)       ");
    printArray(assigned,    "Assignment Op    (should be 10)       ");

    
    Array<std::string> strArr(3);
    strArr[0] = "Hello";
    strArr[1] = "42";
    strArr[2] = "Lisboa";
    printArray(strArr, "String Array");

    
    try {
        std::cout << "Attempting to access empty[0]..." << std::endl;
        std::cout << empty[0] << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "Attempting to access numbers[100]..." << std::endl;
        numbers[100] = 42;
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}
