#include <iostream>
#include <string>

class point
{
    private :
    int x;
    int y;

    public :
    point(int x, int y) : x(x), y(y) {}
    point() : x(0), y(0) {}
    point(const point &p) : x(p.x), y(p.y) {}
    ~point() {}
    point &operator=(const point &p)
    {
        if (this != &p)
        {
            this->x = p.x;
            this->y = p.y;
        }
        return (*this);
    }
    int getX() const {return (this->x);}
    int getY() const {return (this->y);}
};


std::ostream &operator<<(std::ostream &out, const point &p)
{
    out << "x : " << p.getX() << " y : " << p.getY();
    return (out);
}

int main()
{
    point p1(1, 2);
    point p2(p1);
    std::cout << p1 << std::endl;
    return (0);
}