#include <string>
#include "Person.hpp"
#include "Point2D.hpp"
using namespace std;

Person::Person(void) {
    name = "";
    Point2D point(0, 0);
    loc = point;
}

Person::Person(string n, float a, float b) {
    name = n;
    Point2D point(a, b);
    loc = point;
}

string Person::get_name() {return name;}
void Person::set_name(string n) {name = n;}

Point2D Person::get_location() {return loc;}
void Person::set_location(Point2D point) {
    loc.set_x( point.get_x() );
    loc.set_y( point.get_y() );
}