/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Filemanage.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:27:13 by dshirais          #+#    #+#             */
/*   Updated: 2026/06/11 15:34:08 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Filemanage.hpp"

Filemanager::Filemanager(char *original, char *target, char *replace)
{
	originalFile = original;
	targetStr = target;
	replaceStr = replace;
	targetCount = targetStr.length();
	newFile = originalFile + ".replace";
}

const char *Filemanager::getFilename()
{
	const char	*convert = newFile.c_str();

	return (convert);
}

void Filemanager::rewrite(std::ifstream &inFile, std::ofstream &outFile)
{
	std::string line;
    int pos;

	while (getline(inFile, line))
	{
        while((pos = line.find(targetStr)) != -1)
            line.replace(pos, targetCount, replaceStr);
        outFile << line << std::endl;
	}
}