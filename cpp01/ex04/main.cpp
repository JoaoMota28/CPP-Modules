/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 16:07:18 by jomanuel          #+#    #+#             */
/*   Updated: 2026/02/10 14:01:41 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Error: invalid number of arguments" << std::endl;
		std::cerr << "Usage: ./sed <filename> <value to replace> <value to be replaced with>" << std::endl;
		return 1;
	}
	
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty())
	{
		std::cerr << "Error: s1 cannot be empty" << std::endl;
    	return 1;
	}
	
	std::ifstream in (filename.c_str());
	std::ofstream out ((filename + ".replace").c_str());
	if (!in.is_open())
	{
		std::cerr << "Error: could not open file '" << filename << "'" << std::endl;
		return 1;
	}
	if (!out.is_open())
	{
		std::cerr << "Error: could not create file '" << filename << ".replace'" << std::endl;
		in.close();
		return 1;
	}

	std::string line;
	while (std::getline(in, line))
	{
		size_t old_found = 0;
		size_t found = line.find(s1);
		while (found != std::string::npos)
		{
			out << line.substr(old_found, found - old_found) << s2;
			old_found = found + s1.length();
			found = line.find(s1, old_found);
		}
		out << line.substr(old_found, found - old_found) << std::endl;
	}
	in.close();
	out.close();
	return 0;
}
