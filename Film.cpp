#include "Film.h"

int *duplicateIntArray(int *array, int array_size)
{
    int *return_array = new int[array_size];
    for (int index = 0; index < array_size; index++)
    {
        return_array[index] = array[index];
    }
    return return_array;
}

Film::Film(int duration, std::string name, std::string path, int chapter_durations[], int nb_chapters) : Video(duration, name, path), nb_chapters_{nb_chapters}
{
    chapter_durations_ = duplicateIntArray(chapter_durations, nb_chapters);
}

Film::Film(std::istream &stream) : Video(stream)
{
    std::string line;
    std::getline(stream, line);
    nb_chapters_ = std::stoi(line);
    chapter_durations_ = new int[nb_chapters_];
    for (int index = 0; index < nb_chapters_; index++)
    {
        std::string line;
        std::getline(stream, line);
        chapter_durations_[index] = std::stoi(line);
    }
}

Film::~Film()
{
    delete[] chapter_durations_;
}

int *Film::getChapterDurations() const
{
    return duplicateIntArray(chapter_durations_, nb_chapters_);
}

void Film::setChapters(int *chapter_durations, int nb_chapters)
{
    delete[] chapter_durations_;
    chapter_durations_ = duplicateIntArray(chapter_durations, nb_chapters);
}

void Film::print(std::ostream &stream, char line_separator = '\n') const
{
    stream
        << "The name of the video is: "
        << name_
        << line_separator
        << "The path is: "
        << path_
        << line_separator
        << "The duration is: "
        << std::to_string(duration_)
        << line_separator
        << "The chapter durations are: ";

    for (int index = 0; index < nb_chapters_; index++)
    {
        stream << line_separator << "\tChapter " << index + 1 << ": " << chapter_durations_[index] << " min";
    }
    stream << line_separator;
}

void Film::serialize(std::ostream &stream) const
{
    stream
        << "Film\n"
        << name_ << "\n"
        << path_ << "\n"
        << duration_ << "\n"
        << nb_chapters_;
    for (int index = 0; index < nb_chapters_; index++)
    {
        stream << "\n"
               << chapter_durations_[index];
    }
    stream << std::endl;
}