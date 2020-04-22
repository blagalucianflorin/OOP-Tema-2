//
// Created by lblaga on 15.04.2020.
//

#ifndef OOP_TEMA_2_POINT_H
#define OOP_TEMA_2_POINT_H

#include "object.h"

#include <iostream>
#include "exceptions/index_out_of_range.h"

class Point : public Object
{
private:
    int x = 0;
    int y = 0;

public:
    explicit Point (int x = 0, int y = 0);

    virtual ~Point () override = default;

    Point (const Point &old_point);

    Point *clone () override;

    Point &operator= (const Point &old_point);

    friend std::ostream &operator<< (std::ostream &out, const Point &my_point);

    friend std::istream &operator>> (std::istream &in, Point &my_point);

    void set_x (int new_x = 0);

    void set_y (int new_y = 0);

    int get_x () const;

    int get_y () const;

    void display () override;
};

#endif //OOP_TEMA_2_POINT_H
