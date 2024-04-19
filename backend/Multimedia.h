#ifndef multimedia_
#define multimedia_

#include <iostream>
#include <string>


class Multimedia
{
protected:
    std::string name_{};
    std::string path_{};

public:
    Multimedia() = default;
    virtual ~Multimedia() { std::cout << "Multimedia " << name_ << " deleted" << std::endl; }
    Multimedia(std::string name, std::string path) : name_{name}, path_{path} {};
    Multimedia(std::istream & stream);

    std::string getName() const { return name_; }
    std::string getPath() const { return path_; }
    void setName(std::string name) { name_ = name; }
    void setPath(std::string path) { path_ = path; }

    virtual void print(std::ostream &stream, char line_separator) const = 0;

    virtual void serialize(std::ostream & stream) const = 0;
    virtual void render() = 0;
};

#endif