#include "Controller.h"

using MultimediaPtr = std::shared_ptr<Multimedia>;
using GroupPtr = std::shared_ptr<Group>;

MultimediaPtr Controller::createFilm(int duration, std::string name, std::string path, int chatpter_duration[], int nb_chapters)
{
    auto fetch_multimedia = multimedia_map_.find(name);
    if (fetch_multimedia != multimedia_map_.end())
        throw std::runtime_error("Error, the multimedia already exists.");
    MultimediaPtr new_film = Film::makeSharedFilm(duration, name, path, chatpter_duration, nb_chapters);
    multimedia_map_.insert(std::make_pair(name, new_film));
    return new_film;
}

MultimediaPtr Controller::createVideo(int duration, std::string name, std::string path)
{
    auto fetch_multimedia = multimedia_map_.find(name);
    if (fetch_multimedia != multimedia_map_.end())
        throw std::runtime_error("Error, the multimedia already exists.");
    MultimediaPtr new_video = Video::makeSharedVideo(duration, name, path);
    multimedia_map_.insert(std::make_pair(name, new_video));
    return new_video;
}

MultimediaPtr Controller::createImage(float width, float height, std::string name, std::string path)
{
    auto fetch_multimedia = multimedia_map_.find(name);
    if (fetch_multimedia != multimedia_map_.end())
        throw std::runtime_error("Error, the multimedia already exists.");
    MultimediaPtr new_image = Image::makeSharedImage(width, height, name, path);
    multimedia_map_.insert(std::make_pair(name, new_image));
    return new_image;
}

MultimediaPtr Controller::getMultimedia(std::string name) const
{
    auto searched_multimedia = multimedia_map_.find(name);
    if (searched_multimedia == multimedia_map_.end())
        return nullptr;
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

void Controller::printMultimedia(std::string name, std::ostream &stream, char line_separator) const
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

void Controller::printGroup(std::string name, std::ostream &stream, char line_separator = '\n') const
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

void Controller::printAllMultimedia(std::ostream &stream, char line_separator) const
{
    if (!stream)
        throw std::runtime_error("Error, cannot use the input stream.");
    stream << "The multimedia in the controller are: ";
    for (const auto &pair : multimedia_map_)
    {
        stream << line_separator <<"\t" << pair.first;
    }
}

void Controller::printAllGroup(std::ostream &stream, char line_separator) const
{
    if (!stream)
        throw std::runtime_error("Error, cannot use the input stream.");
    stream << "The group in the controller are: ";
    for (const auto &pair : group_map_)
    {
        stream << line_separator << "\t" << pair.first;
    }
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
            new_multimedia = Film::makeSharedFilm(stream);
        else if (line == "Image")
            new_multimedia = Image::makeSharedImage(stream);
        else if (line == "Video")
            new_multimedia = Video::makeSharedVideo(stream);
        else
            throw std::runtime_error("Cannot deserialize the multimedia map, the input provided is in the wrong format.");
        multimedia_map_.insert(std::make_pair(new_multimedia->getName(), new_multimedia));
    }
}

// 1: Group not found
// 2: Multimedia not found
// 3: Multimedia already in the group
// 0: Success
int Controller::addMultimediaToGroup(std::string group_name, std::string multimedia_name)
{
    auto fetch_group = group_map_.find(group_name);
    if (fetch_group == group_map_.end())
        return 1;
    GroupPtr group = fetch_group->second;
    auto multimedia = this->getMultimedia(multimedia_name);
    if (multimedia == nullptr)
        return 2;
    if (std::find(group->begin(), group->end(), multimedia) == group->end()) 
        {
            group->push_front(getMultimedia(multimedia_name));
            return 0;
        }
    return 3;
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

// 1: Multimedia not found
// 0: Success
int Controller::deleteMultimedia(std::string name)
{
    auto searched_multimedia = multimedia_map_.find(name);
    if (searched_multimedia == multimedia_map_.end())
    {
        return 1;
    }
    else
    {
        multimedia_map_.erase(searched_multimedia);
        for (auto &pair : group_map_)
            pair.second->removeMultimedia(name);
        return 0;
    }
}


// 1: Group not found
// 0: Success
int Controller::deleteGroup(std::string name)
{
    auto searched_group = group_map_.find(name);
    if (searched_group == group_map_.end())
    {
        return 1;
    }
    else
    {
        group_map_.erase(searched_group);
        return 0;
    }
}


// 1: Group not found
// 2: Multimedia not found
// 3: Multimedia not in the group
// 0: Success
int Controller::removeMultimediaFromGroup(std::string group_name, std::string multimedia_name)
{
    auto fetch_group = group_map_.find(group_name);
    if (fetch_group == group_map_.end())
        return 1;
    GroupPtr group = fetch_group->second;
    auto multimedia = this->getMultimedia(multimedia_name);
    if (multimedia == nullptr)
        return 2;
    auto it = std::find(group->begin(), group->end(), multimedia);
    if (it != group->end())
    {
        group->erase(it);
        return 0;
    }
    return 3;
}
