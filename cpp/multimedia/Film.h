#ifndef film_
#define film_

#include "Video.h"
#include <iostream>

class Controller;

/**
 * @brief Film class, represents a film object
 * 
 */
class Film : public Video
{    
protected:

    /**
     * @brief Array of chapter durations
     * 
     */
    int *chapter_durations_{};

    /**
     * @brief Number of chapters
     * 
     */
    int nb_chapters_{};

    /**
     * @brief Construct a new Film object
     * 
     * @param duration  duration of the film
     * @param name  name of the film
     * @param path  path to the film file
     * @param chatpter_duration  array of chapter durations
     * @param nb_chapters  number of chapters
     */
    Film(int duration, std::string name, std::string path, int chatpter_duration[], int nb_chapters);

    /**
     * @brief Deserialize a film object from an input stream
     * 
     * @param stream  input stream
     */
    Film(std::istream &stream);

    /**
     * @brief Create a shared pointer to a film object, only accessible by the Controller class
     * 
     * @param duration  duration of the film
     * @param name  name of the film
     * @param path  path to the film file
     * @param chatpter_duration  array of chapter durations
     * @param nb_chapters  number of chapters
     * @return std::shared_ptr<Film> 
     */
    static std::shared_ptr<Film> makeSharedFilm(int duration, std::string name, std::string path, int chatpter_duration[], int nb_chapters) { return std::shared_ptr<Film>(new Film(duration, name, path, chatpter_duration, nb_chapters)); }

    /**
     * @brief Deserialize a film object from an input stream and returns a shared pointer of it, only accessible by the Controller class
     * 
     * @param stream  input stream
     * @return std::shared_ptr<Film> 
     */
    static std::shared_ptr<Film> makeSharedFilm(std::istream &stream) { return std::shared_ptr<Film>(new Film(stream)); }

    friend class Controller;
public:

    ~Film();

    /**
     * @brief Get the chapter durations array
     * 
     * @return int* 
     */
    int *getChapterDurations() const;

    /**
     * @brief Set the chapter durations array
     * 
     * @param getChapterDurations  array of chapter durations
     * @param nb_chapters  number of chapters
     */
    void setChapters(int *getChapterDurations, int nb_chapters);

    /**
     * @brief Get the number of chapters
     * 
     * @return int 
     */
    int getNbChapters() const { return nb_chapters_; }

    /**
     * @brief Print the film object to the stream
     * 
     * @param stream  output stream
     * @param line_separator  line separator
     */
    void print(std::ostream &stream, char line_separator) const override;

    /**
     * @brief Serialize the film object to the output stream
     * 
     * @param stream  output stream
     */
    void serialize(std::ostream & stream) const override;
};

#endif