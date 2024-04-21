#ifndef video_
#define video_

#include "Multimedia.h"
#include <iostream>
#include <string>

class Controller;

class Video : public Multimedia
{
protected:
    int duration_{};
    Video() = default;
    Video(std::istream & stream);
    Video(int duration, std::string name, std::string path) : Multimedia(name, path), duration_{duration} {}

    static std::shared_ptr<Video> makeSharedVideo(int duration, std::string name, std::string path) { return std::shared_ptr<Video>(new Video(duration, name, path)); }
    static std::shared_ptr<Video> makeSharedVideo(std::istream & stream) { return std::shared_ptr<Video>(new Video(stream)); }

    friend class Controller;
public:
    ~Video() = default;

    int getDuration() const { return duration_; }
    void setDuration(int duration) { duration_ = duration; }

    void render() override { system(("mpv " + path_ + " &").data()); }

    void print(std::ostream &stream, char line_separator) const override;

    void serialize(std::ostream & stream) const override;
};

#endif