/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 16:59:35 by seomoon           #+#    #+#             */
/*   Updated: 2021/08/12 11:05:19 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string     replace_line(std::string line, std::string s1, std::string s2)
{
    std::string newline;
    std::size_t old_index;
    std::size_t new_index;
    std::size_t s1_length;

    old_index = 0;
    new_index = 0;
    s1_length = s1.length();
    while ((new_index = line.find(s1, old_index)) != std::string::npos)
    {
        newline += line.substr(old_index, new_index - old_index);
        old_index = new_index + s1_length;
        newline += s2;
    }
    newline += line.substr(old_index);

    return (newline);
}

int     replace
    (std::string filename, std::string s1, std::string s2)
{
    std::ifstream   inputFile;
    std::ofstream   outputFile;
    std::string     line;

    inputFile.open(filename, std::ios::in);
    if (!inputFile.is_open())
        return (1);
    outputFile.open(filename + ".replace", std::ios::out);
    if (!outputFile.is_open())
        return (1);

    while (getline(inputFile, line))
    {
        if (line.find(s1) != std::string::npos)
            outputFile << replace_line(line, s1, s2) << std::endl;
        else
            outputFile << line << std::endl;
    }

    inputFile.close();
    outputFile.close();
    return (0);
}

int     main(int argc, char **args)
{
    std::string     filename;
    std::string     s1;
    std::string     s2;

    if (argc != 4)
        return (1);

    filename = args[1];
    s1 = args[2];
    s2 = args[3];

    if (s1.empty() || s2.empty())
        return (1);

    replace(filename, s1, s2);

    return (0);
}