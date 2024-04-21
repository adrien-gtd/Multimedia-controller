#include "Video.h"

void Video::print(std::ostream &stream, char line_separator = '\n') const
{
        stream
            << "The name of the video is: "
            << name_
            << line_separator
            << "The path is: "
            << path_
            << line_separator
            << "The duration is: "
            << std::to_string(duration_)
            << "minutes"
            << line_separator;
}

Video::Video(std::istream &stream) : Multimedia(stream)
{
        std::string line;
        std::getline(stream, line);
        duration_ = std::stoi(line);
}

void Video::serialize(std::ostream &stream) const
{
        stream
            << "Video\n"
            << name_ << "\n"
            << path_ << "\n"
            << duration_ << std::endl;
}