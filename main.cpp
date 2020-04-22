#include <iostream>

#include "headers/objectArray.h"
#include "headers/point.h"
#include "headers/complexNum.h"


void demo ()
{
    ObjectArray my_array;
    Point my_point (1, 2);
    ComplexNum my_num (3, -1);

    my_array . add (&my_point);
    my_array . add (&my_num);

    my_array . display ();
}

int main ()
{
    demo ();

    return (0);
}
