#include "Multimedia.h"

Multimedia::Multimedia(std::istream &stream)
{
    std::string line;
    std::getline(stream, line);
    name_ = line;
    std::getline(stream, line);
    path_ = line;
}