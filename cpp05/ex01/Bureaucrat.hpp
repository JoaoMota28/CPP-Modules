/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 18:55:34 by jomanuel          #+#    #+#             */
/*   Updated: 2026/06/22 12:19:21 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Form;

class Bureaucrat {
	
	public:
	
		class GradeTooHighException : public std::exception {
			
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			
			public:
				const char* what() const throw();
		};
		
		Bureaucrat();
		Bureaucrat(std::string name, int grade) throw(GradeTooHighException, GradeTooLowException);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat&);

		const std::string getName() const;
		int getGrade() const;
		void incrementGrade() throw(GradeTooHighException);
		void decrementGrade() throw(GradeTooLowException);
		void signForm(Form&);

	private:
		const std::string _name;
		int _grade;

		Bureaucrat& operator=(const Bureaucrat&);
};

std::ostream& operator<< (std::ostream&, const Bureaucrat&);

#endif
