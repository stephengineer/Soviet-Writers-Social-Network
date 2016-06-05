#pragma once
#include "main.h"

// Forward Declaration
class Writer;


/* Points class
@brief Stores Writer pointer objects in std::vector<Writer*> to properly manage allocated memory using Resource Aquisition in Initialization.
*/
class Points {
public:
    // Virtual Destructor
    virtual ~Points();


    // Accessors
    int get_size() const;        // Returns total number of Writers objects in Points vector
    int number_of_connections(int id);        // Returns the number of connections that corresponds to a specific Writer
    int find_name(std::string s);        // Function to find name and return corresponding ID
    std::string get_first_name(int id);
    std::string get_last_name(int id);
    std::string get_name(int id) const;
    int get_institution_number(int id) const;
    std::string get_years_of_life(int id) const;
    std::string get_position_in_institution(int id) const;
    std::string get_geographic_location(int id) const;
    std::string get_circle_of_friends(int id) const;
    std::string get_alive_or_dead(int id) const;
    std::vector<int> get_strengths(int id) const;
    std::vector<std::string> get_multiplicity(int id) const;



    // Mutators
    void push_back(Writer* pt);
    std::string institution_number_to_string(int number);            // Converting Institution Number to Value


    // Print Functions
    void print_names() const;
    void print_institution_numbers() const;

private:
    std::vector<Writer*> points;
};
