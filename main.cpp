#include <iostream>

#include "headers/objectArray.h"
#include "headers/point.h"
#include "headers/complexNum.h"

#include <fstream>

void demo ()
{
    std::cout << "\u001b[31;1m\u001b[1m[Demo-Start]\u001b[0m\n\n";

    std::cout << "\t\u001b[32;1m\u001b[4mConstructors\u001b[0m:\n";
    std::cout << "ObjectArray my_array1()\n";
    ObjectArray my_array1;
    std::cout << "ObjectArray my_array2(grows)\n";
    ObjectArray my_array2 (3);
    std::cout << "ObjectArray my_array3(grows, dimension)\n";
    auto my_array3 = new ObjectArray (3, 1);

    std::cout << "\n\t\u001b[32;1m\u001b[4mCopy constructor:\u001b[0m\n";
    std::cout << "my_array4 (my_array1)\n";
    ObjectArray my_array4 (my_array1);

    std::cout << "\n\t\u001b[32;1m\u001b[4mDestructors:\u001b[0m\n";
    std::cout << "~ObjectArray()\n";
    delete (my_array3);

    std::cout << "\n\t\u001b[32;1m\u001b[4mExceptions:\u001b[0m\n";
    std::cout << "ObjectArray (grows, -1) (Throws 'Dimension_too_small')\n\u001b[31m";
    try
    {
        ObjectArray my_array5(3, -1);
    }
    catch (Dimension_too_small &e)
    {
        std::cout << e . what ();
    }
    std::cout << "\u001b[0m";
    std::cout << "my_array1[100] (Throws 'Index_out_of_range')\n\u001b[31m";
    try
    {
        my_array1[100];
    }
    catch (Index_out_of_range &e)
    {
        std::cout << e . what ();
    }
    std::cout << "\u001b[0m";
    std::cout << "my_array1 . add (NULL) (Throws 'Null_object')\n\u001b[31m";
    try
    {
        my_array1 . add (nullptr);
    }
    catch (Null_object &e)
    {
        std::cout << e . what ();
    }
    std::cout << "\u001b[0m";

    std::cout << "\n\t\u001b[32;1m\u001b[4mDerived Classes (from Object):\u001b[0m\n";
    std::cout << "Point my_point1 (x: 1, y: 2)\n";
    Point my_point1 (1, 2);
    std::cout << "ComplexNum my_num1 (real: 3, imaginary: -2)\n";
    ComplexNum my_num1 (3, -2);

    std::cout << "\n\t\u001b[32;1m\u001b[4mOperators:\u001b[0m\n";
    std::cout << "my_array1 >> my_point1\n";
    my_array1 >> my_point1;
    std::cout << "my_array1 >> my_num1\n";
    my_array1 >> my_num1;
    std::cout << "std::cout << my_array1\t(similar to my_array1 . display ())\n";
    std::cout << my_array1;
    std::cout << "\n";
    std::cout << "my_array2 = my_array1\n";
    my_array2 = my_array1;
    std::cout << "std::cout << my_array2\n";
    std::cout << my_array2;
    std::cout << "\n";

    std::ofstream out_buffer;
    out_buffer . open ("buffer.txt", std::fstream::trunc);
    out_buffer << "99 100";
    out_buffer . close ();
    std::ifstream in_buffer;
    in_buffer . open ("buffer.txt");

    std::cout << "std::cin >> my_point1\t('99 100' already sent to input)\n";
    in_buffer >> my_point1;
    std::cout << "std::cout << my_point1\t(similar to my_point1 . display ())\n";
    std::cout << my_point1;
    std::cout << "\n";

    ObjectArray my_array;
    std::cout << "\n\t\u001b[32;1m\u001b[4mObjectArray Functions:\u001b[0m\n";
    std::cout << "my_array . add (my_point1) x 3\n";
    for (int i = 0; i < 3; i++, my_array . add (&my_point1));
    std::cout << "my_array . add (my_num1) x 3\n";
    for (int i = 0; i < 3; i++, my_array . add (&my_num1));
    std::cout << "my_array . get_size () = " << my_array . get_size () << "\n\n";

    std::cout << "my_array . remove (3)\n";
    my_array . remove (3);
    std::cout << "my_array . get_size () = " << my_array . get_size () << "\n";
    std::cout << "my_array . display ()\n";
    my_array . display ();

    std::cout << "\n";
    std::cout << "my_array . remove_all ()\n";
    my_array . remove_all ();
    std::cout << "my_array . get_size () = " << my_array . get_size () << "\n";
    std::cout << "my_array . add (my_num1) x 3\n";
    for (int i = 0; i < 3; i++, my_array . add (&my_num1));
    std::cout << "my_array . get_size () = " << my_array . get_size () << "\n";
    std::cout << "my_array . display ()\n";
    my_array . display ();

    in_buffer . close ();
#ifdef __linux__
    int a = system ("rm buffer.txt");
    (void)a;
#elif defined _WIN32
    int a = system ("del buffer.txt");
    (void)a;
#endif

    std::cout << "\n\u001b[31;1m\u001b[1m[Demo-End]\u001b[0m\n";
}

int main ()
{
    demo ();

    return (0);
}
