#include "Serializer.hpp"

Serializer::Serializer()
{
    std::cout << "serializer called"<< std::endl;
}

Serializer::~Serializer()
{
    std::cout << "Destructor called " <<std::endl;
}

Serializer::Serializer(const Serializer &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Serializer &Serializer::operator=(const Serializer &other)
{
    std::cout << "Assignment operator called" << std::endl;
    if (this != &other)
    {
        this->oo = other.oo;
    }
    return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{
    std::cout << "serialize called" << std::endl;
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    std::cout << "deserialize called" << std::endl;
    return reinterpret_cast<Data*>(raw);
}
