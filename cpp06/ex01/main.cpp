#include "Serializer.hpp"
using namespace std;
int main()
{
    Serializer s;
    Data d;
    uintptr_t ptr = s.serialize(&d);
    Data* d2 = s.deserialize(ptr);
    (void)d2;




    return 0;
}
