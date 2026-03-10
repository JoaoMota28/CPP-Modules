/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 12:00:23 by jomanuel          #+#    #+#             */
/*   Updated: 2026/03/10 12:19:01 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <stdlib.h>
# include <iomanip>
# include <sstream>
# include <iostream>
# include <string>

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook();

		bool eof_detected(void) const;
		void add_contact(void);
		void search_contact(void);
		void exit_phonebook(void);
		void (PhoneBook::*phonebook_option_selector(std::string buff))(void);

	private:
		int	_contacts_added;
		Contact _contact_array[8];
		bool _eof_detected;

		void add_contact_info(Contact *c, const std::string msg, void (Contact::*funct)(std::string s), bool val);
		void print_contact_basic_info(int index);
		void print_full_contact_info(int index);
		void print_all_contacts(void);
		bool valid_phone_number(std::string num);
};

#endif
