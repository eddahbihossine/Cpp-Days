#include "Zombie.hpp"

int main()
{
    Zombie *zombie =NULL;
    int  N = 5;
    if(N < 0)
        return(121);
    zombie = zombie->zombieHorde(N,"Zombie");
    for (int i = 0; i < N; i++)
    {
        zombie[i].announce();
    }
    delete [] zombie;
    
    return (0);
}