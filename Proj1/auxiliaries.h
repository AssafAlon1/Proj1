#ifndef _LOGIN_AUX_H
#define _LOGIN_AUX_H

#include <fstream>

bool isFileExist(const std::string fileName)
{
    std::ifstream infile(fileName);
    return infile.good();
}

#endif