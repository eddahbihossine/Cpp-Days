#include "Bureaucrat.hpp"
#include "Form.hpp"
int main(int ac , char **av)
{
    Bureaucrat b("b", 1);
    Form f("f", 1, 1);
    b.SignForm(f);
    return (0);
}