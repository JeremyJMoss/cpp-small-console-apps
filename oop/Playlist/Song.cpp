#include "Song.h"
#include <iomanip>

Song::Song(std::string name, std::string artist)
    : name{name}, artist{artist}{};

std::ostream &operator<<(std::ostream &os, const Song &rhs){
    os << std::setfill(' ') << std::setw(20) << std::left << rhs.name 
       << std::setw(20) << rhs.artist << std::endl;
    return os;
}

void Song::play(){
    std::cout << "Playing:" << std::endl;
    std::cout << *this;
}