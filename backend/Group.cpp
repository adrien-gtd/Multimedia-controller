#include "Group.h"

Group::Group(std::istream &stream, Controller *controller)
{
    std::string line;
    std::getline(stream, line);
    group_name_ = line;
    std::getline(stream, line);
    int number_of_multimedia;
    try
    {
        number_of_multimedia = std::stoi(line); // error if the format is wrong here
    }
    catch (const std::exception &e)
    {
        throw std::runtime_error("Cannot deserialize the group map, the input provided is in the wrong format.");
    }
    for (int i = 0; i < number_of_multimedia; i++)
    {   
        std::getline(stream, line);
        this->push_back(controller->getMultimedia(line));        // if the multimedia doesn't exist, an exception is raised and caught higher
    }
}

void Group::print(std::ostream &stream, char line_separator = '\n') const
{
    stream << "Content of the list - " << group_name_ << ":" << line_separator;
    for (const auto &element : *this)
    {
        stream << element->getName();
        stream << line_separator;
    }
}

void Group::serialize(std::ostream &stream)
{
    stream << group_name_ << "\n";
    int number_of_elements = static_cast<int>(this->size());
    stream << number_of_elements << "\n";
    for (auto &element : *this)
    {
        stream << element->getName() << "\n";
    }
}

void Group::removeMultimedia(std::string name)
{
    auto it = this->begin();
    while (it != this->end())
    {
        if ((*it)->getName() == name)
        {
            it = this->erase(it);
        }
        else
        {
            ++it;
        }
    }
}