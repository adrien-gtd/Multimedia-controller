#ifndef image_
#define image_

#include "Multimedia.h"



class Image : public Multimedia
{
protected:
    float width_{}, height_{};

public:
    Image(float width, float height, std::string name, std::string path) : Multimedia(name, path), width_{width}, height_{height} {}
    Image() = default;
    Image(std::istream& stream);
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
