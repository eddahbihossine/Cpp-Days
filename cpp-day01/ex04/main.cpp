#include <iostream>
#include <fstream>
#include <string>

std::string customReplace(const std::string& str, const std::string& from, const std::string& to) 
{
    std::string result;
    size_t start = 0;
    size_t found = str.find(from);

	if(!from.length())
		return (str);
    while (found != std::string::npos) {
        result += str.substr(start, found - start);
        result += to;
        start = found + from.length();
        found = str.find(from, start);
    }
    result += str.substr(start);
    return (result);
}
int main(int ac, char **av) 
{
if (ac == 4) 
{
	std::string FileName = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	std::fstream Toread_file;
	Toread_file.open(FileName, std::ios::in);

	if (Toread_file.is_open()) 
	{
		std::string originalContent;
		std::string line;
		while (getline(Toread_file, line)) 
			originalContent += line + '\n';
		Toread_file.close();
		std::string modifiedContent = customReplace(originalContent, s1, s2);
		std::string newFileName = FileName + ".replace";
		std::fstream Torewrite_file;
		Torewrite_file.open(newFileName, std::ios::trunc | std::ios::out);
		if (Torewrite_file.is_open()) 
		{
			Torewrite_file << modifiedContent;
			Torewrite_file.close();
		} 
		else 
			std::cerr << "Failed to open the new file for writing." << std::endl;
	}
	else 
		std::cerr << "file 's name does not exist "<< std::endl;
	}

	else 
	{
		std::cerr << "READ THE SUBJECT" << std::endl;
		std::cerr << "Usage: " << av[0] << " <filename> <old_string> <new_string>" << std::endl;
	}
return 0;
}


