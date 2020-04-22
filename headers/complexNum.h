//
// Created by lblaga on 15.04.2020.
//

#ifndef OOP_TEMA_2_COMPLEXNUM_H
#define OOP_TEMA_2_COMPLEXNUM_H

#include "object.h"

#include <iostream>
#include "exceptions/index_out_of_range.h"

class ComplexNum : public Object
{
private:
    int real = 0;
    int imaginary = 0;

public:
    explicit ComplexNum (int re = 0, int im = 0);

    virtual ~ComplexNum () override = default;

    ComplexNum (const ComplexNum &old_num);

    ComplexNum *clone () override;

    ComplexNum &operator= (const ComplexNum &old_num);

    friend std::ostream &operator<< (std::ostream &out, const ComplexNum &my_num);

    friend std::istream &operator>> (std::istream &in, ComplexNum &my_num);

    void set_re (int new_real = 0);

    void set_im (int new_imaginary = 0);

    int get_re () const;

    int get_im () const;

    void display () override;
};

#endif //OOP_TEMA_2_COMPLEXNUM_H
