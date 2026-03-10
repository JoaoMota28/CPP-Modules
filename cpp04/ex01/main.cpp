/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 19:50:44 by jomanuel          #+#    #+#             */
/*   Updated: 2026/02/18 16:32:07 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    //Polymorphism

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;

    i->makeSound();
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;

	
    //Array leaks

    const int size = 6;
    Animal* animals[size];

    for (int k = 0; k < size / 2; k++)
        animals[k] = new Dog();
    for (int k = size / 2; k < size; k++)
        animals[k] = new Cat();

    for (int k = 0; k < size; k++)
        delete animals[k];

		
    //Deep copy

    Dog dog1;
    dog1.getBrain()->setIdea(0, "I want food");

    Dog dog2(dog1);

    dog2.getBrain()->setIdea(0, "I want sleep");

    std::cout << "Dog1 idea: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog2 idea: " << dog2.getBrain()->getIdea(0) << std::endl;

	
    //Assignment operator

    Cat cat1;
    cat1.getBrain()->setIdea(0, "I rule the world");

    Cat cat2;
    cat2 = cat1;

    cat2.getBrain()->setIdea(0, "I want tuna");

    std::cout << "Cat1 idea: " << cat1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Cat2 idea: " << cat2.getBrain()->getIdea(0) << std::endl;

    return 0;
}

