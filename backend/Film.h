#ifndef film_
#define film_

#include "Video.h"
#include <iostream>


class Film : public Video
{
protected:
    int *chapter_durations_{};
    int nb_chapters_{};

public:
    Film(int duration, std::string name, std::string path, int chatpter_duration[], int nb_chapters);
    Film(std::istream &stream);
    ~Film();

    int *getChapterDurations() const;
    void setChapters(int *getChapterDurations, int nb_chapters);
    int getNbChapters() const { return nb_chapters_; }

    void print(std::ostream &stream, char line_separator) const override;

    void serialize(std::ostream & stream) const override;
};

#endif