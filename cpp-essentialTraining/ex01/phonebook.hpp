#if !defined( PhoneBook_HPP )
#define PhoneBook_HPP
#include "contact.hpp"
class PhoneBook
{
	private:
	Contact _Contact[8];
	int _Contact_count;
	int oldest_Contact;
public:
	void set_Contact_count(int Contact_count);
	int get_Contact_count();
	void prompt_the_user();
	void prompt_the_user2();
	void print_name();
	void add_Contacta();
};
int check_isdigi(std::string digit);
int ask_index();
std::string parse_name(std::string parameter);
bool is_alpha_and_space(std::string& str);
std::string parse_phone(const std::string& parameter);
std::string truncateString(const std::string& input, int maxChars);
std::string ft_cin() ;
#endif // 
