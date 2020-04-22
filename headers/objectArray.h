//
// Created by lblaga on 15.04.2020.
//

#ifndef OOP_TEMA_2_OBJECTARRAY_H
#define OOP_TEMA_2_OBJECTARRAY_H

#include "object.h"

#include <string>
#include <iostream>
#include <cstring>
#include "exceptions/index_out_of_range.h"
#include "exceptions/null_object.h"
#include "exceptions/dimension_too_small.h"

class ObjectArray : public Object
{
private:
    unsigned int size;
    unsigned int grows;
    unsigned int dimension;
    Object **objects = nullptr;

    ObjectArray *clone () override;

public:
    explicit ObjectArray (unsigned int grows, unsigned int dimension = 1);

    explicit ObjectArray ();

    ~ObjectArray () override;

    ObjectArray (const ObjectArray &old_array);

    ObjectArray &operator= (const ObjectArray &old_array);

    friend ObjectArray &operator>> (ObjectArray &my_array, Object &my_object);

    friend std::ostream &operator<< (std::ostream &out, ObjectArray &my_array);

    Object &operator[] (unsigned int index);

    void remove_all ();

    unsigned int get_size () const;

    unsigned int get_grows () const;

    unsigned int get_dimension () const;

    unsigned int add (Object *new_object);

    unsigned int insert (unsigned int index, Object *new_object);

    unsigned int remove (unsigned int index) noexcept (false);

    Object *get (unsigned int index) const noexcept (false);

    void display () override;
};

#endif //OOP_TEMA_2_OBJECTARRAY_H
