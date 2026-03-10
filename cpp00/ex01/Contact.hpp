/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 12:00:17 by jomanuel          #+#    #+#             */
/*   Updated: 2026/03/10 12:16:54 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
	public:
		Contact(void);
		~Contact();

		std::string get_first_name(void);
		void set_first_name(std::string first_name);
		std::string get_last_name(void);
		void set_last_name(std::string last_name);
		std::string get_nickname(void);
		void set_nickname(std::string nickname);
		std::string get_phone_number(void);
		void set_phone_number(std::string phone_number);
		std::string get_darkest_secret(void);
		void set_darkest_secret(std::string darkest_secret);

	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_number;
		std::string _darkest_secret;
};

#endif
