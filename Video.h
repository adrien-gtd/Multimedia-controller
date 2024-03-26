#ifndef video_
#define video_

#include "Multimedia.h"
#include <iostream>
#include <string>



class Video : public Multimedia
{
protected:
    int duration_{};

public:
    Video() = default;
    Video(std::istream & stream);
    Video(int duration, std::string name, std::string path) : Multimedia(name, path), duration_{duration} {}

    ~Video() = default;

    int getDuration() const { return duration_; }
    void setDuration(int duration) { duration_ = duration; }

    void render() override { system(("mpv " + path_ + " &").data()); }

    void print(std::ostream &stream, char line_separator) const override;

    void serialize(std::ostream & stream) const override;
};

#endif