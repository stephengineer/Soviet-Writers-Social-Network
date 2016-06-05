#pragma once
#include "main.h"


/* Writer class
@brief Creates Writer objects with corresponding information
*/

class Writer {
public:
    Writer() {}
    Writer(std::string a, int b, std::string c, std::string d, std::string e, std::string f, std::string g, std::vector<int> i, std::vector<std::string> j) : person_name(a), person_institution_number(b), person_years_of_life(c), person_position_in_institution(d), person_geographic_location(e), person_circle_of_friends(f), person_alive_or_dead(g), individual_strength(i), person_multiplicity(j) {}


    // Get Functions
    std::string name() const;
    int institution_number() const;
    std::string years_of_life() const;
    std::string position_in_institution() const;
    std::string geographic_location() const;
    std::string circle_of_friends() const;
    std::string alive_or_dead() const;
    std::vector<int> strengths() const;
    std::vector<std::string> multiplicity() const;



private:
    std::string person_name; int person_institution_number; std::string person_years_of_life; std::string person_position_in_institution; std::string person_geographic_location; std::string person_circle_of_friends; std::string person_alive_or_dead; std::string person_strength_string; std::vector<int> individual_strength; std::string person_multiplicity_string; std::vector<std::string> person_multiplicity;
};


