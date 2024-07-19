#include "Movies.h"

int main(){
    Movies movies;
    movies.displayMovies();
    movies.addMovie("About Time", Movie::PG);
    movies.displayMovies();
    movies.addMovie("Big", Movie::PG);
    movies.addMovie("Star Wars", Movie::PG);
    movies.watchMovie("Big");
    movies.watchMovie("About Time");
    movies.displayMovies();
    movies.watchMovie("About Time");
    movies.displayMovies();
}