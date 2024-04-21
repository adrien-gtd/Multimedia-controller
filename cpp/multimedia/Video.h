#ifndef video_
#define video_

#include "Multimedia.h"
#include <iostream>
#include <string>

class Controller;

/**
 * @brief Video class, represents a video object
 * 
 * 
 */
class Video : public Multimedia
{
protected:
    /**
     * @brief Duration of the video
     * 
     */
    int duration_{};
    Video() = default;

    /**
     * @brief Deserialize a video object from an input stream
     * 
     * @param stream  input stream
     */
    Video(std::istream & stream);

    /**
     * @brief Construct a new Video object
     * 
     * @param duration  duration of the video
     * @param name  name of the video
     * @param path  path to the video file
     */
    Video(int duration, std::string name, std::string path) : Multimedia(name, path), duration_{duration} {}

    /**
     * @brief Create a shared pointer to a video object, only accessible by the Controller class
     * 
     * @param duration  duration of the video
     * @param name  name of the video
     * @param path  path to the video file
     * @return std::shared_ptr<Video> 
     */
    static std::shared_ptr<Video> makeSharedVideo(int duration, std::string name, std::string path) { return std::shared_ptr<Video>(new Video(duration, name, path)); }

    /**
     * @brief Deserialize the Video object from the input stream and returns a smart pointer, only accessible by the Controller class
     * 
     * @param stream  input stream
     * @return std::shared_ptr<Video> 
     */
    static std::shared_ptr<Video> makeSharedVideo(std::istream & stream) { return std::shared_ptr<Video>(new Video(stream)); }

    friend class Controller;
public:
    ~Video() = default;

    int getDuration() const { return duration_; }
    void setDuration(int duration) { duration_ = duration; }

    /**
     * @brief Print the video object
     * 
     */
    void render() override { system(("mpv " + path_ + " &").data()); }

    /**
     * @brief Print the video object
     * 
     * @param stream  output stream
     * @param line_separator  line separator
     */
    void print(std::ostream &stream, char line_separator) const override;

    /**
     * @brief Serialize the video object to the output stream
     * 
     * @param stream  output stream
     */
    void serialize(std::ostream & stream) const override;
};

#endif