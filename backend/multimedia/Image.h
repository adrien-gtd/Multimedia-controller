#ifndef image_
#define image_

#include "Multimedia.h"

class Controller;

class Image : public Multimedia
{
protected:
    float width_{}, height_{};
    Image(float width, float height, std::string name, std::string path) : Multimedia(name, path), width_{width}, height_{height} {}
    Image() = default;
    Image(std::istream& stream);

    static std::shared_ptr<Image> makeSharedImage(float width, float height, std::string name, std::string path) { return std::shared_ptr<Image>(new Image(width, height, name, path)); }
    static std::shared_ptr<Image> makeSharedImage(std::istream& stream) { return std::shared_ptr<Image>(new Image(stream)); }

    friend class Controller;
public:
    ~Image() = default;

    float getWidth() const { return width_; }
    float getHeight() const { return height_; }
    void setWidth(float width) { width_ = width; }
    void setHeight(float height) { height_ = height; }

    void render() override { system(("open " + path_ + " &").data()); }
    void print(std::ostream &stream, char line_separator) const override;

    void serialize(std::ostream & stream) const override;
};

#endif
