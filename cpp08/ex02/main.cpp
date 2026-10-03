/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 11:32:21 by jomanuel          #+#    #+#             */
/*   Updated: 2026/07/25 16:25:03 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "Top:  " << mstack.top() << std::endl;

    mstack.pop();

    std::cout << "Size: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    std::cout << "Stack elements from bottom to top:" << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack);


    std::list<int> mlist;

    mlist.push_back(5);
    mlist.push_back(17);

    std::cout << "Top:  " << mlist.back() << std::endl;

    mlist.pop_back();

    std::cout << "Size: " << mlist.size() << std::endl;

    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    mlist.push_back(0);

    std::list<int>::iterator it2 = mlist.begin();
    std::list<int>::iterator ite2 = mlist.end();

    ++it2;
    --it2;
    std::cout << "List elements from start to end:" << std::endl;
    while (it2 != ite2)
    {
        std::cout << *it2 << std::endl;
        ++it2;
    }


    MutantStack<int> mstack2;
    mstack2.push(10);
    mstack2.push(20);
    mstack2.push(30);

    std::cout << "Reverse iteration (top to bottom): ";
    for (MutantStack<int>::reverse_iterator rit = mstack2.rbegin(); rit != mstack2.rend(); ++rit)
    {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    const MutantStack<int> constStack(mstack2);
    std::cout << "Const iteration: ";
    for (MutantStack<int>::const_iterator cit = constStack.begin(); cit != constStack.end(); ++cit)
    {
        std::cout << *cit << " ";
    }
    std::cout << std::endl;


    MutantStack<int, std::vector<int> > vecStack;
    vecStack.push(100);
    vecStack.push(200);
    vecStack.push(300);

    std::cout << "MutantStack using std::vector: ";
    for (MutantStack<int, std::vector<int> >::iterator it3 = vecStack.begin(); it3 != vecStack.end(); ++it3)
    {
        std::cout << *it3 << " ";
    }
    std::cout << std::endl;

    return 0;
}
