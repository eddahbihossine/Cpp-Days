#include "Base.hpp"

int main()
{
    std::srand(time(0));
    Base *b = generate();
    identify_from_pointer(b);
    identify_from_reference(*b);
    delete b;
    return 0;
}