#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP


#include <iostream>

struct Data
{
   int o;
};

class Serializer
{
    private:
        int oo;
    public:
        Serializer(); // constructor
        /* copy constructor */
        Serializer(const Serializer &other);
        /* assignment operator */
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);  
        Serializer &operator=(const Serializer &other);

        
        ~Serializer();
};

#endif