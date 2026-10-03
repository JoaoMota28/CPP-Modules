/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 20:47:40 by jomanuel          #+#    #+#             */
/*   Updated: 2026/06/22 12:26:03 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form {
	
	public:
	
		class GradeTooHighException : public std::exception {
				
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
				
			public:
				const char* what() const throw();
		};
		
		Form();
		Form(std::string name, int grade_to_sign, int grade_to_execute) throw(GradeTooHighException, GradeTooLowException);
		~Form();
		Form(const Form&);

		const std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(const Bureaucrat&) throw(GradeTooLowException);
	
	private:
		const std::string _name;
		bool _is_signed;
		const int _grade_to_sign;
		const int _grade_to_execute;

		Form& operator=(const Form&);
};

std::ostream& operator<< (std::ostream&, const Form&);

#endif
