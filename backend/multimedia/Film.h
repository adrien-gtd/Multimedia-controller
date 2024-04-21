#ifndef film_
#define film_

#include "Video.h"
#include <iostream>

class Controller;

class Film : public Video
{    
protected:
    int *chapter_durations_{};
    int nb_chapters_{};
    Film(int duration, std::string name, std::string path, int chatpter_duration[], int nb_chapters);
    Film(std::istream &stream);

    static std::shared_ptr<Film> makeSharedFilm(int duration, std::string name, std::string path, int chatpter_duration[], int nb_chapters) { return std::shared_ptr<Film>(new Film(duration, name, path, chatpter_duration, nb_chapters)); }
    static std::shared_ptr<Film> makeSharedFilm(std::istream &stream) { return std::shared_ptr<Film>(new Film(stream)); }

    friend class Controller;
public:

    ~Film();

    int *getChapterDurations() const;
    void setChapters(int *getChapterDurations, int nb_chapters);
    int getNbChapters() const { return nb_chapters_; }

    void print(std::ostream &stream, char line_separator) const override;

    void serialize(std::ostream & stream) const override;
};

#endif