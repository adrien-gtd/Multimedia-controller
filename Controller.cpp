#include "Controller.h"

using MultimediaPtr = std::shared_ptr<Multimedia>;
using GroupPtr = std::shared_ptr<Group>;

MultimediaPtr Controller::createFilm(int duration, std::string name, std::string path, int chatpter_duration[], int nb_chapters)
{
    auto fetch_multimedia = multimedia_map_.find(name);
    if (fetch_multimedia != multimedia_map_.end())
        throw std::runtime_error("Error, the multimedia already exists.");
    MultimediaPtr new_film = std::make_shared<Film>(duration, name, path, chatpter_duration, nb_chapters);
    multimedia_map_.insert(std::make_pair(name, new_film));
    return new_film;
}

MultimediaPtr Controller::createVideo(int duration, std::string name, std::string path)
{
    auto fetch_multimedia = multimedia_map_.find(name);
    if (fetch_multimedia != multimedia_map_.end())
        throw std::runtime_error("Error, the multimedia already exists.");
    MultimediaPtr new_video = std::make_shared<Video>(duration, name, path);
    multimedia_map_.insert(std::make_pair(name, new_video));
    return new_video;
}

MultimediaPtr Controller::createImage(float width, float height, std::string name, std::string path)
{
    auto fetch_multimedia = multimedia_map_.find(name);
    if (fetch_multimedia != multimedia_map_.end())
        throw std::runtime_error("Error, the multimedia already exists.");
    MultimediaPtr new_image = std::make_shared<Image>(width, height, name, path);
    multimedia_map_.insert(std::make_pair(name, new_image));
    return new_image;
}

MultimediaPtr Controller::getMultimedia(std::string name) const
{
    auto searched_multimedia = multimedia_map_.find(name);
    if (searched_multimedia == multimedia_map_.end())
    {
        throw std::runtime_error("Error, cannot find the multimedia.");
    }
    else
        return searched_multimedia->second;
}

int Controller::playMultimedia(std::string name) const
{
    auto searched_multimedia = multimedia_map_.find(name);
    if (searched_multimedia == multimedia_map_.end())
    {
        throw std::runtime_error("Error, cannot find the multimedia.");
    }
    else
    {
        searched_multimedia->second->render();
        return 0;
    }
}

void Controller::printMultimedia(std::string name, std::ostream &stream, char line_separator = '\n') const
{
    if (!stream)
        throw std::runtime_error("Error, cannot use the input stream.");
    auto searched_multimedia = multimedia_map_.find(name);
    if (searched_multimedia == multimedia_map_.end())
    {
        std::cout << "MultimediaNotFound" << std::endl;
        stream << "MultimediaNotFound";
    }
    else
        searched_multimedia->second->print(stream, line_separator);
}

GroupPtr Controller::createGroup(std::string name)
{
    auto fetch_group = group_map_.find(name);
    if (fetch_group != group_map_.end())
        throw std::runtime_error("Error, the group already exists.");

    GroupPtr new_group = std::make_shared<Group>(name);
    group_map_.insert(std::make_pair(name, new_group));
    return new_group;
}

GroupPtr Controller::getGroup(std::string name) const
{
    auto searched_group = group_map_.find(name);
    if (searched_group == group_map_.end())
    {
        throw std::runtime_error("Error, group not found.");
    }
    else
        return searched_group->second;
}

void Controller::printGroup(std::string name, std::ostream &stream, char line_separator) const
{
    if (!stream)
        throw std::runtime_error("Error, cannot use the input stream.");
    auto searched_group = group_map_.find(name);
    if (searched_group == group_map_.end())
    {
        std::cout << "GroupNotFound" << std::endl;
        stream << "GroupNotFound";
    }
    else
        searched_group->second->print(stream, line_separator);
}

void Controller::printGroup(std::string name, std::ostream &stream) const
{
    printGroup(name, stream, '\n');
}

void Controller::printAllMultimedia(std::ostream &stream) const
{
    if (!stream)
        throw std::runtime_error("Error, cannot use the input stream.");
    stream << "The multimedia in the controller are: ";
    for (const auto &pair : multimedia_map_)
    {
        stream << "\n\t" << pair.first;
    }
    stream << std::endl;
}

void Controller::printAllGroup(std::ostream &stream) const
{
    if (!stream)
        throw std::runtime_error("Error, cannot use the input stream.");
    stream << "The group in the controller are: ";
    for (const auto &pair : group_map_)
    {
        stream << "\n\t" << pair.first;
    }
    stream << std::endl;
}

void Controller::serializeMultimedia(std::ostream &stream) const
{
    if (!stream)
        throw std::runtime_error("Cannot serialize the multimedia map, the output provided cannot be opened.");
    std::size_t number_of_multimedia = multimedia_map_.size();
    stream << number_of_multimedia << "\n";
    for (const auto &pair : multimedia_map_)
    {
        pair.second->serialize(stream);
    }
}

void Controller::deserializeMultimedia(std::istream &stream)
{
    std::string line;
    MultimediaPtr new_multimedia;
    if (!stream)
        throw std::runtime_error("Cannot deserialize the multimedia map, the input provided cannot be read.");
    std::getline(stream, line);
    int number_of_multimedia;
    try
    {
        number_of_multimedia = std::stoi(line); // error if the format is wrong here
    }
    catch (const std::exception &e)
    {
        throw std::runtime_error("Cannot deserialize the multimedia map, the input provided is in the wrong format.");
    }

    for (int i = 0; i < number_of_multimedia; i++)
    {
        std::getline(stream, line);
        if (line == "Film")
            new_multimedia = std::make_shared<Film>(stream);
        else if (line == "Image")
            new_multimedia = std::make_shared<Image>(stream);
        else if (line == "Video")
            new_multimedia = std::make_shared<Video>(stream);
        else
            throw std::runtime_error("Cannot deserialize the multimedia map, the input provided is in the wrong format.");
        multimedia_map_.insert(std::make_pair(new_multimedia->getName(), new_multimedia));
    }
}

GroupPtr Controller::addMultimediaToGroup(std::string group_name, std::string multimedia_name)
{
    auto fetch_group = group_map_.find(group_name);
    if (fetch_group != group_map_.end())
        throw std::runtime_error("Cannot add the multimedia to the group, the group provided is not existing.");
    GroupPtr group = fetch_group->second;
    if (std::find(group->begin(), group->end(), this->getMultimedia(multimedia_name)) == group->end())
        group->push_front(getMultimedia(multimedia_name));
    else
        throw std::runtime_error("Cannot add the multimedia to the group, the group provided is already in the group.");
    return nullptr;
}

void Controller::serialize(std::ostream &stream) const
{
    serializeMultimedia(stream);
    std::size_t number_of_group = group_map_.size();
    stream << number_of_group << "\n";
    for (const auto &pair : group_map_)
    {
        pair.second->serialize(stream);
    }
}

void Controller::deserialize(std::istream &stream)
{
    deserializeMultimedia(stream);
    GroupPtr new_group;
    std::string line;
    std::getline(stream, line);
    int number_of_groups;
    try
    {
        number_of_groups = std::stoi(line); // error if the format is wrong here
        for (int i = 0; i < number_of_groups; i++)
        {
            new_group = std::make_shared<Group>(stream, this); // Might raise an error is the input file is to the wrong format
            group_map_.insert(std::make_pair(new_group->getGroupName(), new_group));
        }
    }
    catch (const std::exception &e)
    {
        throw std::runtime_error("Cannot deserialize the multimedia map, the input provided is in the wrong format.");
    }
}
