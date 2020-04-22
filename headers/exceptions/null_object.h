//
// Created by Blaga Lucian-Florin on 22-Apr-20.
//

#ifndef OOP_TEMA_2_NULL_OBJECT_H
#define OOP_TEMA_2_NULL_OBJECT_H

#include <exception>
#include "../object.h"

#include <string>

class Null_object : public std::exception
{
private:
    std::string message;

public:
    explicit Null_object (Object *my_object);

    ~Null_object () override = default;

    Null_object (const Null_object &e) noexcept (true);

    const char *what () const noexcept (true) override;
};

#endif //OOP_TEMA_2_NULL_OBJECT_H
