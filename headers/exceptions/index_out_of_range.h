//
// Created by lblaga on 16.04.2020.
//

#ifndef OOP_TEMA_2_INDEX_OUT_OF_RANGE_H
#define OOP_TEMA_2_INDEX_OUT_OF_RANGE_H

#include <string>
#include <exception>


class Index_out_of_range : public std::exception
{
private:
    std::string message;

public:
    explicit Index_out_of_range (unsigned int index, unsigned int size);

    ~Index_out_of_range () override = default;

    Index_out_of_range (const Index_out_of_range &e) noexcept (true);

    const char *what () const noexcept (true) override;
};

#endif //OOP_TEMA_2_INDEX_OUT_OF_RANGE_H
