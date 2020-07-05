#include "../files.hpp"

File::File(const std::string& url)
{
    this->fileStream.open(url, std::ios::binary);
}

std::fstream& File::getFileStream()
{
    return this->fileStream;
}
