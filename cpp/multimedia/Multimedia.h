#ifndef multimedia_
#define multimedia_

#include <iostream>
#include <string>

class Controller;


/**
 * @brief Multimedia class, base abstract class for multimedia objects
 * 
*/
class Multimedia
{
protected:
    /**
     * @brief Name of the multimedia object
     * 
     */
    std::string name_{};

    /**
     * @brief Path to the multimedia object
     * 
     */
    std::string path_{};

    /**
     * @brief Construct a new Multimedia object
     * 
     * @param name  name of the multimedia object
     * @param path  path to the multimedia object
     */
    Multimedia(std::string name, std::string path) : name_{name}, path_{path} {};

    /**
     * @brief Deserialize a multimedia object from an input stream
     * 
     * @param stream  input stream
     */
    Multimedia(std::istream & stream);
    Multimedia() = default;

    friend class Controller;
public:
    
    /**
     * @brief Destroy the Multimedia object, print a message to the console
     * 
     */
    virtual ~Multimedia() { std::cout << "Multimedia " << name_ << " deleted" << std::endl; }


    std::string getName() const { return name_; }
    std::string getPath() const { return path_; }
    void setName(std::string name) { name_ = name; }
    void setPath(std::string path) { path_ = path; }

    /**
     * @brief Print the multimedia object, abstract method
     * 
     * @param stream  output stream
     * @param line_separator  line separator
     */
    virtual void print(std::ostream &stream, char line_separator) const = 0;

    /**
     * @brief Serialize the multimedia object to the output stream, abstract method
     * 
     * @param stream  output stream
     */
    virtual void serialize(std::ostream & stream) const = 0;

    /**
     * @brief Render the multimedia object, abstract method
     * 
     */
    virtual void render() = 0;
};

#endif