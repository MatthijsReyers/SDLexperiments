#pragma once

#include "file.hpp"

class BmpFile : public File
{
    private:
        char* signature;
        int width, height;

    public:
        BmpFile(const std::string& url);

        const int getWidth() noexcept {return this->width;}
        const int getHeight() noexcept {return this->height;}

        void printInfo();
};