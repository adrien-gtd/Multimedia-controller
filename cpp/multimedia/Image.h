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
     * @param stream  input stream
     */
    Image(std::istream& stream);

    /**
     * @brief Create a shared pointer to an image object, only accessible by the Controller class
     * 
     * @param width  width of the image
     * @param height  height of the image
     * @param name  name of the image
     * @param path  path to the image file
     * @return std::shared_ptr<Image> 
     */
    static std::shared_ptr<Image> makeSharedImage(float width, float height, std::string name, std::string path) { return std::shared_ptr<Image>(new Image(width, height, name, path)); }

    /**
     * @brief Deserialize the Image object from the input stream and returns a smart pointer, only accessible by the Controller class
     * 
     * @param stream  input stream
     * @return std::shared_ptr<Image> 
     */
    static std::shared_ptr<Image> makeSharedImage(std::istream& stream) { return std::shared_ptr<Image>(new Image(stream)); }

    friend class Controller;
public:
    ~Image() = default;

    float getWidth() const { return width_; }
    float getHeight() const { return height_; }
    void setWidth(float width) { width_ = width; }
    void setHeight(float height) { height_ = height; }

    /**
     * @brief Render the image
     * 
     */
    void render() override { system(("open " + path_ + " &").data()); }

    /**
     * @brief Print the image object to the output stream
     * 
     * @param stream  output stream
     * @param line_separator  line separator
     */
    void print(std::ostream &stream, char line_separator) const override;

    /**
     * @brief Serialize the image object to the output stream
     * 
     * @param stream  output stream
     */
    void serialize(std::ostream & stream) const override;
};

#endif
