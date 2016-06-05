#pragma once
#include "main.h"

//Virtual Destructor
Points::~Points() {
    for (auto& x : points)
        delete x;
}


//Push_Back Function
void Points::push_back(Writer* pt) {
    points.push_back(pt);
}

//Get Size of std::vector<Writer*> Function
int Points::get_size() const {
    return points.size();
}

//Get Number of Connections Function
int Points::number_of_connections(int id) {
    int count = 0;

    for (size_t i = 0, n = points[id]->strengths().size(); i < n; ++i) {
        if ((points[id]->strengths()[i]) != 0) {
            ++count;
        }
    }
    return count;
}


//Find ID For Corresponding Name Function
int Points::find_name(std::string s) {
    int count = 0;
    for (size_t i = 0, n = points.size(); i < n; ++i) {
        if (s == points[i]->name()) {
            return count;
        }
        else {
            ++count;
        }
    }
    return count;
}



//Converts Institution Number to String Function
std::string Points::institution_number_to_string(int number) {
    std::string value;
    switch (number) {
    case 1: value = "Leningrad Branch of Detgiz Publishing House";
        break;
    case 2: value = "Moscow Children's Section";
        break;
    case 3: value = "Gorky Literary Institute";
        break;
    case 4: value = "Leningrad Branch of Detgiz Publishing House \nMoscow Children's Section";
        break;
    case 5: value = "Leningrad Branch of Detgiz Publishing House \nMoscow Children's Section \n\"Youth\" Journal";
        break;
    case 6: value = "Moscow Children's Section \n\"Youth\" Journal";
        break;
    case 7: value = "Gorky Literary Institute \nMoscow Children's Section \n\"Youth\" Journal";
        break;
    case 8: value = "Gorky Literary Institute \nMoscow Children's Section";
        break;
    case 0: value = "None";
        break;
    default:
        break;
    }
    return value;
}


//Print Names Function
void Points::print_names() const {
    for (size_t i = 0, n = points.size(); i < n; ++i) {
        std::cout << points[i]->name() << " ";
    }
}

//Print Institution Numbers Function
void Points::print_institution_numbers() const {
    for (size_t i = 0, n = points.size(); i < n; ++i) {
        std::cout << points[i]->institution_number() << " ";
    }
}


//Get First Name Function
std::string Points::get_first_name(int id) {
    std::string temp = points[id]->name();
    int location = temp.find(' ');
    temp = temp.substr(0, location);

    return temp;
}

//Get Last Name Function
std::string Points::get_last_name(int id) {
    std::string temp = points[id]->name();
    int location = temp.find(' ');
    temp = temp.substr(location + 1, temp.size());

    return temp;
}



//Get Name Function
std::string Points::get_name(int id) const {
    return points[id]->name();
}



//Get Institution Number Function
int Points::get_institution_number(int id) const {
    return points[id]->institution_number();
}



//Get Years of Life Function
std::string Points::get_years_of_life(int id) const {
    return points[id]->years_of_life();
}



//Get Position in Institution Function
std::string Points::get_position_in_institution(int id) const {
    return points[id]->position_in_institution();
}


//Get Geographic Location Function
std::string Points::get_geographic_location(int id) const {
    return points[id]->geographic_location();
}



//Get Circle of Friends Function
std::string Points::get_circle_of_friends(int id) const {
    return points[id]->circle_of_friends();
}




//Get Alive or Dead Function
std::string Points::get_alive_or_dead(int id) const {
    return points[id]->alive_or_dead();
}



//Get Strength Function
std::vector<int> Points::get_strengths(int id) const {
    return points[id]->strengths();
}



/*@brief Get Multiplicity Function
@param id Index of corresponding Writer
@return std::vector<std::string> that corresponds to multiplicity for a specific Writer object
*/
std::vector<std::string> Points::get_multiplicity(int id) const {
    return points[id]->multiplicity();
}


