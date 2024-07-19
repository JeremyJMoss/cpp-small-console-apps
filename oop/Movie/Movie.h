#pragma once
#include <iostream>

class Movie{
    public:
        enum Rating {G, PG, M, MA, R};
    private:
        std::string name;
        Rating rating;
        int watched;
    public:
        Movie(std::string name, Rating rating, int times_watched = 0);

        void watchMovie();

        std::string getName() const;

        std::string getRating() const;

        int getTimesWatched() const;
};