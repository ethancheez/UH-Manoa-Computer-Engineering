#include "Point2D.hpp"

Point2D::Point2D(void) {
    x = 0;
    y = 0;
}
Point2D::Point2D(float x, float y) {
    this->x = x;
    this->y = y;
}

float Point2D::get_x() {return x;}
void Point2D::set_x(float f) {x = f;}

float Point2D::get_y() {return y;}
void Point2D::set_y(float f) {y = f;}

Point2D operator+(Point2D lhs, Point2D rhs) {
    Point2D point(lhs.get_x() + rhs.get_x(), lhs.get_y() + rhs.get_y()); //creating and returning a Point2D object 'point' given the lhs and rhs (x,y) values and operator
    return point;
}
Point2D operator-(Point2D lhs, Point2D rhs) {
    Point2D point(lhs.get_x() - rhs.get_x(), lhs.get_y() - rhs.get_y());
    return point;
}
Point2D operator*(Point2D lhs, Point2D rhs) {
    Point2D point(lhs.get_x() * rhs.get_x(), lhs.get_y() * rhs.get_y());
    return point;
}
Point2D operator/(Point2D lhs, Point2D rhs) {
    Point2D point(lhs.get_x() / rhs.get_x(), lhs.get_y() / rhs.get_y());
    return point;
}

