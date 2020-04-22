//
// Created by lblaga on 16.04.2020.
//

#include "../../headers/exceptions/index_out_of_range.h"

Index_out_of_range::Index_out_of_range (unsigned int index, unsigned int size)
{
    message = "\nIndex_out_of_range: Tried to access position (" + std::to_string (index) + ") outside array range (0-"\
 + std::to_string (size - 1) + ").\n";
}

const char *Index_out_of_range::what () const noexcept (true)
{
    return ((this -> message) . c_str ());
}

Index_out_of_range::Index_out_of_range (const Index_out_of_range &e) noexcept (true)
{
    this -> message = e . message;
}
