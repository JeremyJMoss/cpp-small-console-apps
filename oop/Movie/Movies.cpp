#include "Movies.h"

bool Movies::addMovie(std::string name, Movie::Rating rating, int times_watched){
    for (const Movie &mov : movies){
        if (mov.getName() == name){
            std::cout << name << " already in collection" << std::endl;
            return false;
        }
    }
    Movie movie(name, rating, times_watched);
    movies.push_back(movie);
    return true;
}

bool Movies::watchMovie(std::string name){
    for (Movie &mov : movies){
        if (mov.getName() == name){
            mov.watchMovie();
            return true;
        }
    }
    std::cout << name << " not in collection" << std::endl;
    return false;
}

void Movies::displayMovies() const {
    if (movies.size() == 0){
        std::cout << "No movies found" << std::endl;
        return;
    }
    for (const Movie &mov : movies){
        std::cout << mov.getName() << " (" << mov.getRating() << ") watched: " << mov.getTimesWatched() << " times." << std::endl;        
    }
}