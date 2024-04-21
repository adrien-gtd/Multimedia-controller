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

/**
 * @brief Controller class, manages the multimedia objects and the group objects
 * 
 */
class Controller
{
private:
    /**
     * @brief Map of multimedia objects storing the name of the multimedia object as the key and the multimedia object as the value
     * 
     */
    std::map<std::string, MultimediaPtr> multimedia_map_{};

    /**
     * @brief Map of group objects storing the name of the group object as the key and the group object as the value
     * 
     */
    std::map<std::string, GroupPtr> group_map_{};

public:
    Controller() = default;
    ~Controller() = default;

    /**
     * @brief Create a Film object
     * 
     * @param duration  duration of the film
     * @param name  name of the film
     * @param path  path of the film
     * @param chatpter_duration  array of chapter duration
     * @param nb_chapters  number of chapters
     * @return MultimediaPtr (shared_ptr<Multimedia>) 
     */
    MultimediaPtr createFilm(int duration, std::string name, std::string path, int chatpter_duration[], int nb_chapters);

    /**
     * @brief Create a Video object
     * 
     * @param duration  duration of the video
     * @param name   name of the video
     * @param path   path of the video
     * @return MultimediaPtr (shared_ptr<Multimedia>)
     */
    MultimediaPtr createVideo(int duration, std::string name, std::string path);

    /**
     * @brief Create a Image object
     * 
     * @param width  width of the image