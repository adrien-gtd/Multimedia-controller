#ifndef group_
#define group_

#include <string>
#include <list>
#include <iostream>
#include <memory>
#include "../multimedia/Multimedia.h"
#include "../controller/Controller.h"

class Controller;

using MultimediaPtr = std::shared_ptr<Multimedia>;

/**
 * @brief Group class, contains a list of multimedia objects
 * 
 */
class Group : public std::list<MultimediaPtr>
{
private:

    /**
     * @brief Name of the group
     * 
     */
    std::string group_name_{};

public:

    Group() = default;

    /**
     * @brief Construct a new Group object
     * 
     * @param name  name of the group
     */
    Group(std::string name) : group_name_{name} {}

    /**
     * @brief Deserialize an group object from an input stream
     * 
     * @param stream  input stream
     * @param controller  controller object
     */
    Group(std::istream &stream, Controller *controller);


    /**
     * @brief Print the multimedia elements of the group
     * 
     * @param stream  output stream
     * @param line_separator  line separator
     */
    void print(std::ostream &stream, char line_separator) const;

    /**
     * @brief Change the name of the group
     * 
     * @param multimedia  new name of the group
     */
    void setName(std::string new_group_name) { group_name_ = new_group_name; }

    /**
     * @brief Get the name of the group
     * 
     * @return std::string 
     */
    std::string getGroupName() { return group_name_; }

    /**
     * @brief Serialize the group object to an output stream
     * 
     * @param stream  output stream
     */
    void serialize(std::ostream &stream);

    /**
     * @brief Remove a multimedia object from the group
     * 
     * @param name name of the multimedia object
     */
    void removeMultimedia(std::string name);
};

#endif
