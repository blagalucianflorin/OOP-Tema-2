//
// Created by lblaga on 15.04.2020.
//

#include "../headers/objectArray.h"


ObjectArray::ObjectArray ()
{
    this -> size = 0;
    this -> grows = 2;
    this -> dimension = 1;
    this -> objects = (Object **) malloc (sizeof (void *));
}

ObjectArray::ObjectArray (unsigned int grows, unsigned int dimension)
{
    if ((int) dimension < 1)
    {
        throw (Dimension_too_small ((int) dimension));
    }
    if ((int) grows >= 2)
        this -> grows = grows;
    else
        this -> grows = 2;
    this -> size = 0;
    this -> grows = grows;
    this -> dimension = dimension;
    this -> objects = (Object **) malloc (dimension * sizeof (void *));
}

ObjectArray::~ObjectArray ()
{
    this -> remove_all ();
}

ObjectArray::ObjectArray (const ObjectArray &old_array)
{
    this -> size = 0;
    this -> grows = old_array . get_grows ();
    this -> dimension = old_array . get_dimension ();
    this -> objects = (Object **) malloc ((this -> dimension) * sizeof (void *));
    for (int i = 0; i < old_array . get_size (); i++)
        this -> add (old_array . get (i));
}

ObjectArray *ObjectArray::clone ()
{
    return new ObjectArray (*this);
}

ObjectArray &ObjectArray::operator= (const ObjectArray &old_array)
{
    if (this != &old_array)
    {
        this -> remove_all ();
        this -> size = 0;
        this -> grows = old_array . get_grows ();
        this -> dimension = old_array . get_dimension ();
        this -> objects = (Object **) malloc ((this -> dimension) * sizeof (void *));
        for (int i = 0; i < old_array . get_size (); i++)
            this -> add (old_array . get (i));
    }
    return (*this);
}

ObjectArray &operator>> (ObjectArray &my_array, Object &my_object)
{
    my_array . add (&my_object);
    return (my_array);
}

std::ostream &operator<< (std::ostream &out, ObjectArray &my_array)
{
    my_array . display ();
    return out;
}

void ObjectArray::remove_all ()
{
    for (int i = 0; i < this -> size; i++)
        delete (objects[i]);
    free (objects);
    objects = nullptr;
    while (dimension % grows == 0)
        dimension /= grows;
    this -> size = 0;
}

unsigned int ObjectArray::get_size () const
{
    return (this -> size);
}

unsigned int ObjectArray::get_grows () const
{
    return (this -> grows);
}

unsigned int ObjectArray::get_dimension () const
{
    return (this -> dimension);
}

unsigned int ObjectArray::add (Object *new_object)
{
    return (this -> insert (this -> size, new_object));
}

unsigned int ObjectArray::insert (unsigned int index, Object *new_object)
{
    if (new_object != nullptr)
    {
        if (dimension < 1)
            dimension = 1;
        if (index >= dimension - 1)
        {
            dimension *= grows;
            objects = (Object **) realloc (objects, dimension * sizeof (void *));
        }
        memmove (&objects[index + 1], &objects[index], (size - index) * sizeof (void *));
        objects[index] = new_object -> clone ();
        size++;
        return index;
    }
    else
    {
        throw (Null_object (new_object));
    }
}

unsigned int ObjectArray::remove (unsigned int index) noexcept (false)
{
    if (index < 0 || index > this -> size)
    {
        throw Index_out_of_range (index, this -> size);
    }
    else
    {
        delete (objects[index]);
        memmove (&objects[index], &objects[index + 1], (size - index) * sizeof (void *));
//        delete ((Object*)objects[size - 1]);
        size--;
        if (size < dimension / grows)
            dimension /= grows;
    }
    return (index);
}

Object *ObjectArray::get (unsigned int index) const noexcept (false)
{
    if (index < 0 || index >= this -> size)
    {
        throw Index_out_of_range (index, this -> size);
    }
    else
        return (Object *) objects[index];
}

void ObjectArray::display ()
{
    for (int i = 0; i < size; i++, std::cout << " ")
        objects[i] -> display ();
    std::cout << std::endl;
}

Object &ObjectArray::operator[] (unsigned int index)
{
    return (*(this -> get (index)));
}
