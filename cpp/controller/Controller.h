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
     * @param height  height of the image
     * @param name  name of the image
     * @param path  path of the image
     * @return MultimediaPtr (shared_ptr<Multimedia>)
     */
    MultimediaPtr createImage(float width, float height, std::string name, std::string path);

    /**
     * @brief Get the Multimedia object with the name "name" from the multimedia map
     * 
     * @param name  name of the multimedia
     * @return MultimediaPtr (shared_ptr<Multimedia>)
     */
    MultimediaPtr getMultimedia(std::string name) const;

    /**
     * @brief Print the multimedia object with the name "name"
     * 
     * @param name  name of the multimedia
     * @return int  0 if the multimedia is found, -1 otherwise
     */
    int playMultimedia(std::string name) const;

    /**
     * @brief Print the multimedia object with the name "name" to the stream
     * 
     * @param name  name of the multimedia
     * @param stream  stream to print the multimedia
     * @param line_separator  line separator
     */
    void printMultimedia(std::string name, std::ostream& stream, char line_separator = '\n') const;
    
    /**
     * @brief Create a Group object
     * 
     * @param name  name of the group
     * @return GroupPtr (shared_ptr<Group>)
     */
    GroupPtr createGroup(std::string name);

    /**
     * @brief Add a multimedia object to a group
     * 
     * @param group_name  name of the group
     * @param multimedia_name  name of the multimedia
     * @return int  0 if the multimedia is added to the group, -1 otherwise
     */
    int addMultimediaToGroup(std::string group_name, std::string multimedia_name);

    /**
     * @brief Remove a multimedia object from a group
     * 
     * @param group_name  name of the group
     * @param multimedia_name  name of the multimedia
     * @return int  1: Group not found - 2: Multimedia not found - 3: Multimedia already in the group - 0: Success
     */
    int removeMultimediaFromGroup(std::string group_name, std::string multimedia_name);

    /**
     * @brief Get the Group object with the name "name" from the group map
     * 
     * @param name  name of the group
     * @return GroupPtr (shared_ptr<Group>)
     */
    GroupPtr getGroup(std::string name) const;

    /**
     * @brief Print the content of the group object with the name "name" to the stream
     * 
     * @param name  name of the group
     * @param stream  stream to print the group
     * @param line_separator  line separator
     */
    void printGroup(std::string name, std::ostream& stream, char line_separator) const;

    /**
     * @brief Print all multimedia objects in the map to the stream
     * 
     * @param stream  stream to print the multimedia
     * @param line_separator  line separator
     */
    void printAllMultimedia(std::ostream& stream, char line_separator = '\n') const;

    /**
     * @brief Print all group objects in the map to the stream
     * 
     * @param stream  stream to print the group
     * @param line_separator  line separator
     */
    void printAllGroup(std::ostream& stream, char line_separator = '\n') const;


    /**
     * @brief Serialize the multimedia map to the output stream
     * 
     * @param stream  stream to serialize the multimedia map
     */
    void serializeMultimedia(std::ostream& stream) const;

    /**
     * @brief Deserialize the multimedia map from the input stream
     * 
     * @param stream  stream from which it is deserializing the multimedia map
     */
    void deserializeMultimedia(std::istream & stream);

    /**
     * @brief Serialize the controller to the output stream
     * 
     * @param stream  stream to serialize the controller
     */
    void serialize(std::ostream& stream) const;

    /**
     * @brief Deserialize the controller from the input stream
     * 
     * @param stream  stream from which it is deserializing the controller
     */
    void deserialize(std::istream & stream);

    /**
     * @brief Delete the multimedia object with name "name" from the multimedia map
     * 
     * @param name  name of the multimedia
     * @return int  1: Multimedia not found - 0: Success
     */
    int deleteMultimedia(std::string name);

    /**
     * @brief Delete the group object with name "name" from the group map
     * 
     * @param name  name of the group
     * @return int  1: Group not found - 0: Success
     */
    int deleteGroup(std::string name);
};

#endif
