/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Filemanage.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 13:28:02 by dshirais          #+#    #+#             */
/*   Updated: 2026/06/11 16:13:52 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEMANAGE_HPP
# define FILEMANAGE_HPP

#include <iostream>
#include <fstream>
#include <string>

class Filemanager
{
    public:
        Filemanager(char *original, char *target, char *replace);
        ~Filemanager(){};
        void rewrite(std::ifstream &inFile, std::ofstream &outFile);
        const char* getFilename();

    private:
        std::string originalFile;
        std::string targetStr;
        std::string replaceStr;
        std::string newFile;
        int targetCount;
        std::ofstream outFile;      
};

#endif