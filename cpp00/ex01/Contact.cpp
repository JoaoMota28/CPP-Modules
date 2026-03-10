/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 12:00:15 by jomanuel          #+#    #+#             */
/*   Updated: 2026/03/04 13:16:18 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) : _first_name(""), _last_name(""), _nickname(""), _phone_number(""), _darkest_secret("")
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

std::string	Contact::get_first_name(void)
{
	return _first_name;
}

void Contact::set_first_name(std::string first_name)
{
	this->_first_name = first_name;
	return ;
}

std::string Contact::get_last_name(void)
{
	return  _last_name;
}

void Contact::set_last_name(std::string last_name)
{
	this->_last_name = last_name;
	return ;
}

std::string Contact::get_nickname(void)
{
	return _nickname;
}

void Contact::set_nickname(std::string nickname)
{
	this->_nickname = nickname;
	return ;
}

std::string Contact::get_phone_number(void)
{
	return _phone_number;
}

void Contact::set_phone_number(std::string phone_number)
{
	this->_phone_number = phone_number;
	return ;
}

std::string Contact::get_darkest_secret(void)
{
	return _darkest_secret;
}

void Contact::set_darkest_secret(std::string darkest_secret)
{
	this->_darkest_secret = darkest_secret;
	return ;
}
