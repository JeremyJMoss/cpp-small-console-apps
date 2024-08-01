#pragma once
#include <iostream>

class Song {
    friend std::ostream &operator<<(std::ostream &os, const Song &rhs);
    private:
        std::string name;
        std::string artist;
    public:
        Song(std::string name, std::string artist);
        ~Song() = default;
        void play();
};