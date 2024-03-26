#ifndef group_
#define group_

#include <string>
#include <list>
#include <iostream>
#include <memory>
#include "Multimedia.h"
#include "Controller.h"

class Controller;

using MultimediaPtr = std::shared_ptr<Multimedia>;

class Group : public std::list<MultimediaPtr>
{
private:
    std::string group_name_{};

public:
    Group() = default;
    Group(std::string name) : group_name_{name} {}
    Group(std::istream &stream, Controller *controller);

    void print(std::ostream &stream) const;
    void print(std::ostream &stream, char line_separator) const;
    void setName(std::string new_group_name) { group_name_ = new_group_name; }
    std::string getGroupName() { return group_name_; }
    void serialize(std::ostream &stream);
};

#endif
