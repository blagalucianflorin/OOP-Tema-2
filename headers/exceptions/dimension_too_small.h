//
// Created by Blaga Lucian-Florin on 22-Apr-20.
//

#ifndef OOP_TEMA_2_DIMENSION_TOO_SMALL_H
#define OOP_TEMA_2_DIMENSION_TOO_SMALL_H

#include <exception>

#include <string>


class Dimension_too_small : public std::exception
{
private:
    std::string message;

public:
    explicit Dimension_too_small (int dimension);

    ~Dimension_too_small () override = default;

    Dimension_too_small (const Dimension_too_small &e) noexcept (true);

    const char *what () const noexcept (true) override;
};

#endif //OOP_TEMA_2_DIMENSION_TOO_SMALL_H
