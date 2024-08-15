#include "contact.hpp"


void Contact::set_name(std::string name)
{
   this->_name = name;
}
void Contact::set_surname(std::string surname)
{
   this->_surname = surname;
}
void Contact::set_nickname(std::string nickname)
{
   this->_nickname = nickname;
}
void Contact::set_phone(std::string phone)
{
   this->_phone = phone;
}
void Contact::set_darkest_secret(std::string darkest_secret)
{
   this->_darkest_secret = darkest_secret;
}

std::string Contact::get_name() 
{
   return this->_name;
}
std::string Contact::get_surname() 
{
   return this->_surname;
}
std::string Contact::get_nickname() 
{
   return this->_nickname;
}
std::string Contact::get_phone() 
{
   return this->_phone;
}
std::string Contact::get_darkest_secret() 
{
   return this->_darkest_secret;
}

