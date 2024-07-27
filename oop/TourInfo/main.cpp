#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

struct City {
    std::string name;
    long population;
    double cost;
};

struct Country {
    std::string name;
    std::vector<City> cities;
};

struct Tours {
    std::string title;
    std::vector<Country> countries;
};

int main() {
    Tours tours { "Tour Ticket Prices from Miami", 
        {
            {
                "Colombia", {
                    {"Bogota", 8778000, 400.98},
                    {"Cali", 2401000, 424.12},
                    {"Medellin", 2464000, 350.98},
                    {"Cartagena", 972000, 345.34}
                }
            },
            {
                "Brazil", {
                    {"Rio De Janiero", 13500000, 567.45},
                    {"Sao Paulo", 11310000, 975.45},
                    {"Salvador", 18234000, 855.99}
                }
            },
            {
                "Chile", {
                    {"Valdivia", 260000, 569.12},
                    {"Santiago", 7040000, 520.00}
                }
            },
            {
                "Argentina", {
                    {"Buenos Aires", 3010000, 728.77}
                }
            }
        }
    };
    int buffer_width = 80;

    std::cout << std::setw(((buffer_width - tours.title.length()) / 2) + tours.title.length()) << std::right << tours.title << std::endl << std::endl;
    int column_width = buffer_width / 4;
    std::cout << std::setw(column_width) << std::left << "Country" 
              << std::setw(column_width) << "City"
              << std::setw(column_width) << std::right << "Population"
              << std::setw(column_width) << "Price" << std::endl;
    std::cout << std::setw(buffer_width) << std::setfill('-') << "" << std::endl;
    for (Country country: tours.countries){
        std::cout << std::left << std::setfill(' ') << std::setw(column_width) << country.name;
        bool first_time = true;
        for (City city: country.cities){
            if (!first_time){
                std::cout << std::setw(column_width) << " ";
            }
            std::cout << std::setw(column_width) << std::left << city.name
                      << std::setw(column_width) << std::right << city.population
                      << std::setw(column_width) << std::right << city.cost
                      << std::endl;
            first_time = false;
        }
    }

    std::cout << std::endl << std::endl;
    return 0;
}