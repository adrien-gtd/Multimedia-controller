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
     * @par