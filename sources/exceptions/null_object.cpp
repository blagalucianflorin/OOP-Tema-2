//
// Created by Blaga Lucian-Florin on 22-Apr-20.
//

#include "../../headers/exceptions/null_object.h"


Null_object::Null_object (Object *my_object)
{
    message = "Null_object: Tried to a access NULL object (" + std::to_string ((unsigned long) my_object) + ").\n";
}

Null_object::Null_object (const Null_object &e) noexcept (true)
{
    this -> message = e . message;
}

const char *Null_object::what () const noexcept (true)
{
    return ((this -> message) . c_str ());
}
