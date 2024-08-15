#ifndef RPN_S
#define RPN_S

#include <iostream>
#include <stack>
#include <set>
#include <list>
#include <string>
#include <sstream>
#include <cctype>
#include <stdexcept>
// main container list  , secondary container stack
class RPN
{
public:
    RPN();
    ~RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    void check_expression();
    int is_op(const std::string &op);
    void pushOperand(double num);
    void pushOperator(const std::string& op);
    RPN(const std::string &numbers);
    void calculate();
    class FileError : public std::exception
    {
        public:
            virtual const char *what() const throw();
    };
    class ExpressionError : public std::exception
    {
        public:
            virtual const char *what() const throw();
    };

private:
    std::list<std::string> data;
    std::stack<double> stack;
};

#endif // RPN_S


