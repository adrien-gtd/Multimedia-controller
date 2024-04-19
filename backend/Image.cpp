#include "Image.h"

Image::Image(std::istream &stream) : Multimedia(stream)
{
    std::string line;
    std::getline(stream, line);
    width_ = std::stof(line);
    std::getline(stream, line);
    height_ = std::stof(line);
}

void Image::print(std::ostream &stream, char line_separator = '\n') const
{
    stream
        << "The name of the Image is: "
        << name_
        << line_separator
        << "path is: "
        << path_
        << line_separator
        << "size is: "
        << std::to_string(width_)
        << "x"
        << std::to_string(height_)
        << line_separator;
}


void Image::serialize(std::ostream &stream) const
{
    stream
        << "Image\n"
        << name_ << "\n"
        << path_ << "\n"
        << width_ << "\n"
        << height_ << std::endl;
}