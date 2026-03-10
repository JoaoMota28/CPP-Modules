/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 12:00:20 by jomanuel          #+#    #+#             */
/*   Updated: 2026/02/09 15:07:06 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _contacts_added(0), _eof_detected(false)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

bool PhoneBook::eof_detected() const
{
	return _eof_detected;
}

bool PhoneBook::valid_phone_number(std::string num)
{
	if (num.length() > 15)
		return false;
	for (int i = 0; i < (int)num.length(); i++)
	{
		if (i == 0 && num[i] == '+')
			continue ;
		if (num[i] >= '0' && num[i] <= '9')
			continue ;
		return false;
	}
	return true;
}

void PhoneBook::add_contact_info(Contact *c, const std::string msg, void (Contact::*funct)(std::string s), bool val)
{
	std::string buff;
	const std::string trim = " \n\t\r";

	while (true)
	{
		std::cout << msg;
		if (!std::getline(std::cin, buff))
		{
			std::cout << "EOF detected, aborting." << std::endl;
			_eof_detected = true;
			return ;
		}
		std::size_t first = buff.find_first_not_of(trim);
		if (first == std::string::npos)
		{
			std::cout << "Field must be non-empty." << std::endl << std::endl;
			continue ;
		}
		std::cout << std::endl;
		std::size_t last = buff.find_last_not_of(trim);
		buff = buff.substr(first, last - first + 1);
		if (val && !valid_phone_number(buff))
		{
			std::cout << "Invalid phone number." << std::endl << std::endl;
			continue ;
		}
		break ;
	}
	(c->*funct)(buff);
	return ;
}

void PhoneBook::add_contact(void)
{
	int index = _contacts_added % 8;
	Contact *cptr = &_contact_array[index];

	add_contact_info(cptr, "Input contact first name: ", &Contact::set_first_name, false);
	if (_eof_detected) return ;
	add_contact_info(cptr, "Input contact last name: ", &Contact::set_last_name, false);
	if (_eof_detected) return ;
	add_contact_info(cptr, "Input contact nickname: ", &Contact::set_nickname, false);
	if (_eof_detected) return ;
	add_contact_info(cptr, "Input contact phone number: ", &Contact::set_phone_number, true);
	if (_eof_detected) return ;
	add_contact_info(cptr, "Input contact darkest secret: ", &Contact::set_darkest_secret, false);
	if (_eof_detected) return ;
	_contacts_added++;
	return ;
}

void::PhoneBook::print_contact_basic_info(int index)
{
	Contact *cptr = &_contact_array[index];
	std::string first_name = cptr->get_first_name();
	std::string last_name = cptr->get_last_name();
	std::string nickname = cptr->get_nickname();
	std::string arr[3] = {first_name, last_name, nickname};

	std::cout << std::setw(10) << index << "|";
	for (int i = 0; i < 3; i++)
	{
		if (arr[i].length() > 10)
			std::cout << std::setw(9) << arr[i].substr(0, 9) << ".";
		else
			std::cout << std::setw(10) << arr[i];
		if (i != 2)
			std::cout << "|";
	}
	std::cout << std::endl;
	return ;
}

void::PhoneBook::print_all_contacts(void)
{
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (_contact_array[i].get_first_name().length() > 0)
			print_contact_basic_info(i);
		else
			break ;
	}
	std::cout << std::endl;
	return ;
}

void PhoneBook::print_full_contact_info(int index)
{
	Contact *cptr = &_contact_array[index];

	std::cout << "First Name: " << cptr->get_first_name() << std::endl;
	std::cout << "Last Name: " << cptr->get_last_name() << std::endl;
	std::cout << "Nickname: " << cptr->get_nickname() << std::endl;
	std::cout << "Phone Number: " << cptr->get_phone_number() << std::endl;
	std::cout << "Darkest Secret: " << cptr->get_darkest_secret() << std::endl;
	return ;
}

void PhoneBook::search_contact(void)
{
	std::string	buff;
	int index;
	char extra;

	PhoneBook::print_all_contacts();
	std::cout << "Input the index of the contact you want to display: ";
	if (!std::getline(std::cin, buff))
	{
		std::cout << "EOF detected, aborting." << std::endl;
		_eof_detected = true;
		return;
	}
	std::istringstream iss(buff);
	if (!(iss >> index) || iss >> extra || index < 0 || index > 7)
		std::cerr << "Invalid index input." << std::endl << std::endl;
	else if (_contact_array[index].get_first_name().empty())
		std::cerr << "Invalid index input." << std::endl << std::endl;
	else
	{
		std::cout << std::endl;
		print_full_contact_info(index);
	}
	return ;
}

void PhoneBook::exit_phonebook(void)
{
	std::cout << "Contacts deleted. Logging off..." << std::endl;
	exit(EXIT_SUCCESS);
	return ;
}

void (PhoneBook::*PhoneBook::phonebook_option_selector(std::string buff))(void)
{
	if (buff == "ADD")
		return &PhoneBook::add_contact;
	else if (buff == "SEARCH")
		return &PhoneBook::search_contact;
	else if (buff == "EXIT")
		return &PhoneBook::exit_phonebook;
	else
		return NULL;
}
