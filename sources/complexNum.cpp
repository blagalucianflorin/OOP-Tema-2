//
// Created by lblaga on 15.04.2020.
//

#include "../headers/complexNum.h"

ComplexNum::ComplexNum (int re, int im)
{
    this -> set_re (re);
    this -> set_im (im);
}

ComplexNum::ComplexNum (const ComplexNum &old_num)
{
    this -> set_re (old_num . get_re ());
    this -> set_im (old_num . get_im ());
}

ComplexNum *ComplexNum::clone ()
{
    return new ComplexNum (*this);
}

ComplexNum &ComplexNum::operator= (const ComplexNum &old_num)
{
    if (this != &old_num)
    {
        this -> set_re (old_num . get_re ());
        this -> set_im (old_num . get_im ());
    }
    return (*this);
}

std::ostream &operator<< (std::ostream &out, const ComplexNum &complex_num)
{
    out << complex_num . get_re () << (complex_num . get_im () > 0 ? "+" : "") << complex_num . get_im () << "i";
    return out;
}

std::istream &operator>> (std::istream &in, ComplexNum &my_num)
{
    in >> my_num . real;
    in >> my_num . imaginary;
    return in;
}

void ComplexNum::set_re (int new_real)
{
    this -> real = new_real;
}

void ComplexNum::set_im (int new_imaginary)
{
    this -> imaginary = new_imaginary;
}

int ComplexNum::get_re () const
{
    return (this -> real);
}

int ComplexNum::get_im () const
{
    return (this -> imaginary);
}

void ComplexNum::display ()
{
    std::cout << *this;
}

