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
    Multimedia(std::