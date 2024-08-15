#include "phonebook.hpp"
std::string ft_cin() ;
int check_isdigi(std::string digit)
{
	for(int i = 0; i < (int )digit.length(); i++)
	{
		if(!isdigit(digit[i]))
			return 0;
	}
	return 1;
}
int ask_index()
{
	std::cout << "Enter index: ";
	std ::string indexo ;
	indexo = ft_cin();
	if(!check_isdigi(indexo) || indexo.empty() || indexo.length() > 1)
		return -1;
	int index = atoi(indexo.c_str());
	if(std::cin.fail() || index > 7 || index < 0)
		return -1;
	return index;
}

bool is_alpha_and_space(std::string& str) {
    for (size_t i = 0; i < str.length(); i++) {
        if (!(isalpha(str[i]) || isspace(str[i]))) {
            return false;
        }
    }
    return true;
}

std::string parse_name(std::string parameter) {
    std::string name;
    while (true) {
        std::cout << "Enter " << parameter << ": ";
		name = ft_cin();
        if (is_alpha_and_space(name) && !name.empty()) 
            return name; 
		else
            std::cout << parameter << " is invalid. Please enter only alphabetic characters and spaces." << std::endl;
    }
}
 

bool check_isdigit(const std::string& str) {
    for (size_t i = 0; i < str.length(); i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

std::string parse_phone(const std::string& parameter) {
    std::string phone;
    while (true) {
        std::cout << "Enter " << parameter << ": ";
        phone = ft_cin();
        if (check_isdigit(phone) && !phone.empty() && phone.length() <= 10) {
            return phone;
        } else {
            std::cout << parameter << " is invalid. Please enter only digits, and the length should not exceed 10 characters." << std::endl;
        }
    }
}
std::string truncateString(const std::string& input, int maxChars)
{
    if ((int)input.length() > maxChars) {
        return input.substr(0, maxChars) + ".";
    }
    return input;
}
std::string ft_cin() {
    std::string str;
    std::getline(std::cin, str);
	if(std::cin.eof())
		exit(0);
    return str;
}
void PhoneBook::set_Contact_count(int Contact_count)
{
    this->_Contact_count = Contact_count;
}
int PhoneBook::get_Contact_count()
{
    return this->_Contact_count;
}