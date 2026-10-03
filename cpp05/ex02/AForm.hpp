/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 20:47:40 by jomanuel          #+#    #+#             */
/*   Updated: 2026/06/22 15:34:40 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm {
	
	public:
	
		class GradeTooHighException : public std::exception {
				
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
				
			public:
				const char* what() const throw();
		};

		class FormNotSignedException : public std::exception {
			
			public:
				const char* what() const throw();
		};
		
		AForm();
		AForm(const std::string name, int grade_to_sign, int grade_to_execute) throw(GradeTooHighException, GradeTooLowException);
		virtual ~AForm();
		AForm(const AForm&);

		const std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(const Bureaucrat&) throw(GradeTooLowException);

		virtual void execute(Bureaucrat const& executor) const = 0;
	
	private:
		const std::string _name;
		bool _is_signed;
		const int _grade_to_sign;
		const int _grade_to_execute;

		AForm& operator=(const AForm&);
};

std::ostream& operator<< (std::ostream&, const AForm&);

#endif
