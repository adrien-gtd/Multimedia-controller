#ifndef image_
#define image_

#include "Multimedia.h"

class Controller;

/**
 * @brief Image class, represents  an image object
 * 
 */
class Image : public Multimedia
{
protected:
    /**
     * @brief Width and height of the image
     * 
     */
    float width_{}, height_{};

    /**
     * @brief Construct a new Image object
     * 
     * @param width  width of the image
     * @param height  height of the image
     * @param name  name of the image
     * @param path  path to the image file
     */
    Image(float width, float height, std::string name, std::string path) : Multimedia(name, path), width_{width}, height_{height} {}
    Image() = default;

    /**
     * @brief Deserialize an image object from an input stream
     * 
     * @param stream  inp