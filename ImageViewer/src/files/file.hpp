#pragma once

#include <string>
#include <fstream>
#include <exception>

class File
{
protected:
    std::fstream fileStream;

public:
    File(const std::string& url);

    std::fstream& getFileStream();
    std::ifstream& getInputStream();
    std::ofstream& getOutputStream();
};

struct FileNotFoundFormatException : public std::exception
{
    std::string message;
    FileNotFoundFormatException(std::string msg): message(msg) {}
    const char * what () const throw () {return message.c_str();}
};

struct FormatException : public std::exception
{
    std::string message;
    FormatException(std::string msg): message(msg) {}
    const char * what () const throw () {return message.c_str();}
};