//
// Created by lblaga on 15.04.2020.
//

#ifndef OOP_TEMA_2_OBJECT_H
#define OOP_TEMA_2_OBJECT_H

class Object
{
private:

public:
    Object () = default;

    virtual ~Object () = 0;

    virtual Object *clone () = 0;

    virtual void display () = 0;
};

#endif //OOP_TEMA_2_OBJECT_H
