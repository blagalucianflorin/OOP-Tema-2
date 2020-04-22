//
// Created by lblaga on 15.04.2020.
//

#include "../headers/point.h"


Point::Point (int x, int y)
{
    this -> set_x (x);
    this -> set_y (y);
}

Point::Point (const Point &old_point)
{
    this -> set_x (old_point . get_x ());
    this -> set_y (old_point . get_y ());
}

Point *Point::clone ()
{
    return new Point (*this);
}

Point &Point::operator= (const Point &old_point)
{
    if (this != &old_point)
    {
        this -> set_x (old_point . get_x ());
        this -> set_y (old_point . get_y ());
    }
    return (*this);
}

std::ostream &operator<< (std::ostream &out, const Point &my_point)
{
    out << "(" << my_point . get_x () << ", " << my_point . get_y () << ")";
    return out;
}

std::istream &operator>> (std::istream &in, Point &my_point)
{
    in >> my_point . x;
    in >> my_point . y;
    return in;
}

void Point::set_x (int new_x)
{
    this -> x = new_x;
}

void Point::set_y (int new_y)
{
    this -> y = new_y;
}

int Point::get_x () const
{
    return (this -> x);
}

int Point::get_y () const
{
    return (this -> y);
}

void Point::display ()
{
    std::cout << *this;
}

