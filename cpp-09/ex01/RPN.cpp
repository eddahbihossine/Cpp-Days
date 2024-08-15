#include "RPN.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cctype>

RPN::RPN() {
    std::cout << "RPN constructor" << std::endl;
}

RPN::~RPN() {
    std::cout << "RPN destructor" << std::endl;
}

RPN::RPN(const RPN &other) {
    std::cout << "RPN copy constructor" << std::endl;
    this->data = other.data;
}

const char *RPN::FileError::what() const throw() 
{
    return "FileError";
}

const char *RPN::ExpressionError::what() const throw() {
    return "ExpressionError";
}

RPN &RPN::operator=(const RPN &other) 
{
    std::cout << "RPN operator=" << std::endl;
    this->data = other.data;
    return *this;
}

void RPN::pushOperand(double num) 
{
    stack.push(num);
}

void RPN::pushOperator(const std::string& op) 
{
    if (stack.size() < 2)
        throw std::runtime_error("Invalid expression");
    double operand2 = stack.top();
    stack.pop();
    double operand1 = stack.top();
    stack.pop();
    double result;
    if (op == "+")
        result = operand1 + operand2;
    else if (op == "-")
        result = operand1 - operand2;
    else if (op == "*")
        result = operand1 * operand2;
    else if (op == "/") {
        if (operand2 == 0)
            throw std::runtime_error("Division by zero");
        result = operand1 / operand2;
    }
    stack.push(result);
}

std::list<std::string> splitString(const std::string& str) {
    std::list<std::string> tokens;
    std::stringstream ss(str);
    std::string token;
    while (ss >> token) 
    {
        tokens.push_back(token);
    }
    return tokens;
}

RPN::RPN(const std::string &numbers) {
    this->data = splitString(numbers);
}

int RPN::is_op(const std::string& op) 
{
    if ((op == "+" || op == "-" || op == "*" || op == "/") && (op.size() == 1))
        return 1;
    return 0;
}

void RPN::check_expression() 
{
    int number_counter = 0;
    int operator_counter = 0;

    std::list<std::string>::iterator it = this->data.begin();
    while (it != this->data.end()) 
    {
        if (is_op(*it))
            operator_counter++;
        else if (std::isdigit((*it)[0]) || ((*it)[0] == '-' && std::isdigit((*it)[1])))
            number_counter++;
        else
            throw ExpressionError();
        it++;
    }
    if (number_counter - operator_counter != 1)
        throw ExpressionError();
}

void RPN::calculate() 
{
    std::list<std::string>::iterator it = data.begin();
    while (it != data.end()) 
    {
        const std::string& token = *it;
        if (std::isdigit(token[0]) || (token[0] == '-' && std::isdigit(token[1]))) 
        {
            double num = atof(token.c_str());
            stack.push(num);
        } 
        else 
        {
            try 
            {
                pushOperator(token);
            } 
            catch(const std::runtime_error& e) 
            {
                std::cerr << "Error: " << e.what() << std::endl;
                return;
            }
        }
        ++it;
    }
    if (!stack.empty())
    {
        double result = stack.top();
        std::cout << "Result: " << result << std::endl;
    } 
    else
        std::cerr << "Error: Empty expression" << std::endl;
}
