/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouqas <aabouqas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 09:48:51 by aabouqas          #+#    #+#             */
/*   Updated: 2024/08/27 08:55:33 by aabouqas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

std::string	getFileContent(std::string fileName) {
	std::string		buffer;
	std::string		line;
	std::ifstream	file;
	
	file.open(fileName);
	if (file.is_open() == false)
		return buffer;
	while (std::getline(file, line)) {
		if (file.eof() == false)
			buffer.append(line).append("\n");
		else
			buffer.append(line);
	}
	file.close();
	return buffer;
}

int main(int ac, char *args[]) {
	std::string		fileContent;
	std::ofstream	newFile;
	size_t			strLength;
	std::string		str1;
	std::string		str2;
	
	if (ac != 4)
	{
		std::cerr << "Error\n";
		return 1;
	}
	str1 = args[2];
	str2 = args[3];
	fileContent = getFileContent(args[1]);
	if (fileContent.empty())
		return 1;
	newFile.open(std::string(args[1]).append(".replace"));
	if (newFile.is_open() == false)
		return 1;
	strLength = fileContent.length();
	for (size_t n = 0; n < strLength; n++) {
		if (fileContent[n] == str1[0])
		{
			if (fileContent.substr(n, str1.length()) == str1)
			{
				newFile << str2;
				n += str1.length() - 1;
				continue;
			}
		}
		newFile << fileContent[n];
	}
	newFile << std::flush;
	newFile.close();
}
