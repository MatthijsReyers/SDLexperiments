
#include "bmp.hpp"

#include <iostream>

BmpFile::BmpFile(const std::string& url): File(url)
{
    // Read file header.
    fileStream.read(this->signature, 2);
    
    width = 1080;
    height = 720;
}

void BmpFile::printInfo()
{
    std::cout << "File header:  " << this->signature << std::endl;
}
