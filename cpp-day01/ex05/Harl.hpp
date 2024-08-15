#ifndef HARL_HPP
#define HARL_HPP
#include <iostream>
#include <string>
class Harl
{
	private:
		void debug();
		void info();
		void warning();
		void error();
	public:
		void complain( std::string level );
 
};
int before_main(std:: string str, std::string p[4]);
#endif