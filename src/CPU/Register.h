//
// Created by Lasse Bloch Lauritsen on 20/01/2018.
//

#ifndef OLDBOY_REGISTER_H
#define OLDBOY_REGISTER_H
#include <cstdint>

template <class T>
class Register {
public:
    void operator=(T val)
    {
        this->val_ = val;
    }

    T operator()() const
    {
        return val_;
    }
private:
    T val_ = 0;
};

#endif //OLDBOY_REGISTER_H
