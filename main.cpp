#include <iostream>

#include "headers/objectArray.h"
#include "headers/point.h"
#include "headers/complexNum.h"


void demo ()
{
    ObjectArray my_array (2);
    Point my_point (1, 2);
    ComplexNum my_num (3, -1);

    for (int i = 0; i < 10; i++)
    {
        my_array . add (&my_point);
        my_array . add (&my_num);
    }

//    while (my_array . get_size () != 1)
    my_array.remove (3);

    ObjectArray my_array2 (my_array);

    my_array2.remove_all ();

    my_point.set_x(99);
    my_point.set_y (-100);

    my_array2.add (&my_point);
    my_array2.add (&my_num);
    my_array2.add (&my_point);

    my_array . display ();

    std::cout << std::endl;

    my_array2 . display ();
}


int main ()
{
    demo ();

    return (0);
}
