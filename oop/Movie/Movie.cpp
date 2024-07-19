#include "Movie.h"

Movie::Movie(std::string name, Rating rating, int times_watched){
    this->name = name;
    this->rating = rating;
    this->watched = times_watched;
}

void Movie::watchMovie(){
    this->watched++;
};

std::string Movie::getName() const {
    return name;
}

std::string Movie::getRating() const {
    std::string value;
    switch (rating){
        case G:
            value = "G";
            break;
        case PG:
            value = "PG";
            break;
        case M:
            value = "M";
            break;
        case MA:
            value = "MA";
            break;
        case R:
            value = "R";
            break;
        default:
            value = "Not Rated";
    }
    return value;
};

int Movie::getTimesWatched() const {
    return watched;
}