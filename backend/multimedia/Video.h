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
    st