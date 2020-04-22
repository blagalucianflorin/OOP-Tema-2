//
// Created by Blaga Lucian-Florin on 22-Apr-20.
//

#include "../../headers/exceptions/dimension_too_small.h"


Dimension_too_small::Dimension_too_small (int dimension)
{
    this -> message = "Dimension_too_small: Tried to set the array dimension to a value lower than 1. (" + \
                        std::to_string (dimension) + ")\n";
}

Dimension_too_small::Dimension_too_small (const Dimension_too_small &e) noexcept (true)
{
    this -> message = e . message;
}

const char *Dimension_too_small::what () const noexcept (true)
{
    return (this -> message . c_str ());
}
