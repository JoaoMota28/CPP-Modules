/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 16:48:18 by jomanuel          #+#    #+#             */
/*   Updated: 2026/07/19 15:36:16 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "ABC.hpp"

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

int main (void)
{
	A* ptr_a = new A;
	B* ptr_b = new B;
	C* ptr_c = new C;

	identify(ptr_a);
	identify(ptr_b);
	identify(ptr_c);

	identify(*ptr_a);
	identify(*ptr_b);
	identify(*ptr_c);

	delete ptr_a;
	delete ptr_b;
	delete ptr_c;
	
	for (int i = 0; i < 10; i++) {
		Base *ptr = generate();
		identify(ptr);
		identify(*ptr);
		delete ptr;
	}
}