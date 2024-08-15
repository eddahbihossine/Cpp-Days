#include "Base.hpp"



Base::~Base()
{
    std::cout << "Base destructor called" << std::endl;
}



A::~A()
{
    std::cout << "A destructor called" << std::endl;
}

B::~B()
{
    std::cout << "B destructor called" << std::endl;
}

C::~C()
{
    std::cout << "C destructor called" << std::endl;
}

Base *generate(void)
{
    int i = rand() % 3;
    if (i == 0)
    {
        std::cout << "A instance created" << std::endl;
        return new A;
    }
    else if (i == 1)
    {
        std::cout << "B instance created" << std::endl;
        return new B;
    }
    else
    {
        std::cout << "C instance created" << std::endl;
        return new C;
    }
}


void identify_from_pointer(Base *p)
{
    if (dynamic_cast<A *>(p))
    {
        std::cout << "A" << std::endl;
    }
    else if (dynamic_cast<B *>(p))
    {
        std::cout << "B" << std::endl;
    }
    else if (dynamic_cast<C *>(p))
    {
        std::cout << "C" << std::endl;
    }
}


void identify_from_reference(Base &p)
{
    try
    {
        A &a = dynamic_cast<A &>(p);
        (void)a;
        std::cout << "A" << std::endl;
    }
    catch (std::bad_cast &e)
    {
        try
        {
            B &b = dynamic_cast<B &>(p);
            (void)b;
            std::cout << "B" << std::endl;
        }
        catch (std::bad_cast &e)
        {
            try
            {
                C &c = dynamic_cast<C &>(p);
                (void)c;
                std::cout << "C" << std::endl;
            }
            catch (std::bad_cast &e)
            {
                std::cout << "Unknown type" << std::endl;
            }
        }
    }
}


