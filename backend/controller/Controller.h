#ifndef controller_
#define controller_

#include "../multimedia/Multimedia.h"
#include "../group/Group.h"
#include "../multimedia/Film.h"
#include "../multimedia/Video.h"
#include "../multimedia/Image.h"
#include <memory>
#include <iostream>
#include <map>
#include <string>

class Group;

using MultimediaPtr = std::shared_ptr<Multimedia>;
using GroupPtr = std::shared_ptr<Group>;

class Controller
{
private:
    std::map<std::string, MultimediaPtr> multimedia_map_{};
    std::map<std::string, GroupPtr> group_map_{};

public:
    Controller() = default;
    ~Controller() = default;

    MultimediaPtr createFilm(int duration, std::string name, std::string path, int chatpter_duration[], int nb_chapters);
    MultimediaPtr createVideo(int duration, std::string name, std::string path);
    MultimediaPtr createImage(float width, float height, std::string name, std::string path);

    MultimediaPtr getMultimedia(std::string name) const;

    int playMultimedia(std::string name) const;
    void printMultimedia(std::string name, std::ostream& stream, char line_separator = '\n') const;
    
    GroupPtr createGroup(std::string name);
    int addMultimediaToGroup(std::string group_name, std::string multimedia_name);
    int removeMultimediaFromGroup(std::string group_name, std::string multimedia_name);
    GroupPtr getGroup(std::string name) const;
    void printGroup(std::string name, std::ostream& stream, char line_separator) const;

    void printAllMultimedia(std::ostream& stream, char line_separator = '\n') const;
    void printAllGroup(std::ostream& stream, char line_separator = '\n') const;

    void serializeMultimedia(std::ostream& stream) const;
    void deserializeMultimedia(std::istream & stream);

    void serialize(std::ostream& stream) const;
    void deserialize(std::istream & stream);

    int deleteMultimedia(std::string name);
    int deleteGroup(std::string name);
};

#endif
