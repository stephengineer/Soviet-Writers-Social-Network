#pragma once
#include "main.h"

//Get Name Function
std::string Writer::name() const {
    return person_name;
}


//Get Institution Number Function
int Writer::institution_number() const {
    return person_institution_number;
}



// Get Years of Life Function
std::string Writer::years_of_life() const {
    return person_years_of_life;
}


//Get Position in Institution Function
std::string Writer::position_in_institution() const {
    return person_position_in_institution;
}



//Get Geographic Location Function
std::string Writer::geographic_location() const {
    return person_geographic_location;
}



//Get Circle of Friends Function
std::string Writer::circle_of_friends() const {
    return person_circle_of_friends;
}



//Get Alive or Dead Function
std::string Writer::alive_or_dead() const {
    return person_alive_or_dead;
}


//Get Strengths Function
std::vector<int> Writer::strengths() const {
    return individual_strength;
}


//Get Multiplicity Function
std::vector<std::string> Writer::multiplicity() const {
    return person_multiplicity;
}
