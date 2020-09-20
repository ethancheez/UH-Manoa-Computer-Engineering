#ifndef PERSON_HPP
#define PERSON_HPP

#include "Point2D.hpp"

// std::string is a class from the C++ standard
// library that can be default-constructed
// and constructed from a C-style string (string
// literal like "Hello world")
#include <string>

// Make sure to use both Point2D and std::string
// as member variables in the class below.
using namespace std;

class Person { 
    private:
        string name;
        Point2D loc;

    public:
        Person();
        Person(string n, float a, float b);

        string get_name();
        Point2D get_location();

        void set_name(string n);
        void set_location(Point2D point);

};

#endif // PERSON_HPP
