#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
/*  why i m always misunderstood :) */
class Base
{
    public:
        virtual ~Base() ;
};

class A : public Base
{
    public:
        virtual ~A() ;
};

class B : public Base
{
    public:
        virtual ~B() ;
};

class C : public Base
{
    public:
        virtual ~C() ;
};

Base *generate(void);
void identify_from_pointer(Base *p);
void identify_from_reference(Base &p);

#endif