#include <iostream>

#include "headers/objectArray.h"
#include "headers/point.h"
#include "headers/complexNum.h"


int main ()
{
    auto my_point = new Point (1, 2);
    auto my_num = new ComplexNum (3, -1);
    auto my_array = new ObjectArray ();

    *my_array >> *my_point >> *my_num >> *my_point;

    my_point -> set_x (0);

    std::cout << *my_array;

    std::cin >> *my_point;

    try
    {
        (*my_array)[2] . display ();
        (*my_array)[8] . display ();
    }
    catch (Index_out_of_range &e)
    {
        std::cout << e . what ();
    }

    delete my_array;
    delete my_num;
    delete my_point;

    return (0);
}
