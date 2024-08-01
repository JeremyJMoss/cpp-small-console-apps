#include "Song.h"
#include <iostream>
#include <iomanip>
#include <list>
#include <limits>

void print_menu();

int main(){
    std::list<Song> song_list {};
    song_list.emplace_back("God's Plan", "Drake");
    song_list.emplace_back("Remember Me", "Justin Bieber");
    auto ptr = song_list.begin();
    std::string song_name;
    std::string song_artist;
    char input;
    while(input != 'q' && input != 'Q'){
        print_menu();
        std::cin >> input;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch (input){
            case 'Q':
            case 'q':
                break;
            case 'F':
            case 'f':
                std::cout << "Playing First Song:" << std::endl;
                ptr = song_list.begin();
                ptr->play();
                break;
            case 'N':
            case 'n':
                std::cout << "Playing Next Song:" << std::endl;
                if (++ptr == song_list.end()){
                    ptr = song_list.begin();
                }
                ptr->play();
                break;
            case 'P':
            case 'p':
                std::cout << "Playing Previous Song:" << std::endl;
                if (ptr == song_list.begin()){
                    ptr = song_list.end();
                }
                ptr--;
                ptr->play();
                break;
            case 'A':
            case 'a':
                std::cout << "What is the name of the new song? ";
                std::getline(std::cin, song_name);
                std::cout << "What is the name of the artist? ";
                std::getline(std::cin, song_artist);
                ptr = song_list.emplace(ptr, song_name, song_artist);
                ptr->play();
                break;
            case 'L':
            case 'l':
                std::cout << std::endl;
                for (const auto &song : song_list) {
                    std::cout << song;
                }
                break;
            default:
                std::cout << "Please select a valid selection" << std::endl;
        }

    }
    return 0;
}

void print_menu(){
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next Song" << std::endl;
    std::cout << "P - Play Previous Song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << std::setw(47) << std::setfill('=') << "" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}