#pragma once
#include <iostream>
#include <vector>
#include "Movie.h"

class Movies{
    private:
        std::vector<Movie> movies;
    public:
        bool addMovie(std::string name, Movie::Rating rating, int times_watched = 0);
        bool watchMovie(std::string name);
        void displayMovies() const;
};