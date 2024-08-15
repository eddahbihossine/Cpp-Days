#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
    this->value = "";
    this->valid_date = "";
    this->data.clear();
    this->filename = "";
    this->btc = false;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    this->filename = other.filename;
    this->tokens = other.tokens;
    this->valid_date = other.valid_date;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    this->filename = other.filename;
    return *this;
}

// Trim whitespace from the beginning and end of a string
std::string trim(const std::string &str)
{
    size_t first = str.find_first_not_of(" \t\r\n");
    if (std::string::npos == first)
        return "";

    size_t last = str.find_last_not_of(" \t\r\n");
    return str.substr(first, (last - first + 1));
}

void BitcoinExchange::check_date(const std::string &date)
{
    if (date.empty())
    {
        std::cout << "Date is empty" << std::endl;
        return;
    }

    std::stringstream ss(date);
    std::string year, month, day;
    
    std::getline(ss, year, '-');
    std::getline(ss, month, '-');
    std::getline(ss, day, '-');

    year = trim(year);
    month = trim(month);
    day = trim(day);

    if (year.empty() || month.empty() || day.empty())
    {
        throw DateError();
    }

    if (year.size() != 4 || month.size() != 2 || day.size() != 2)
    {
        throw DateError();
    }

    if (year.find_first_not_of("0123456789") != std::string::npos || month.find_first_not_of("0123456789") != std::string::npos || day.find_first_not_of("0123456789") != std::string::npos)
    {
        throw DateError();
    }

    if (std::stoi(month) < 1 || std::stoi(month) > 12 || std::stoi(day) < 1 || std::stoi(day) > 31)
    {
        throw DateError();
    }
    else
    {
        this->tokens[0] = year;
        this->tokens[1] = month;
        this->tokens[2] = day;
    
    }
    
}

void BitcoinExchange::check_file(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
        throw FileError();
    file.close();
}

BitcoinExchange::BitcoinExchange(const std::string &filename)
{
    this->filename = filename;
}

//exception classes
const char *BitcoinExchange::FileError::what() const throw()
{
    return "FileError: could not open file";
}

const char *BitcoinExchange::DateEmpty::what() const throw()
{
    return "DateError: date is empty";
}

const char *BitcoinExchange::DateError::what() const throw()
{
    return "DateError: date is not in the correct format";
}

const char *BitcoinExchange::DataError::what() const throw()
{
    return "DataError: data is empty";
}

void BitcoinExchange::check_data(const std::string &data)
{
    std::stringstream ss;
    ss << data;
    float value;
    ss >> value;
    if(data.empty())
        std::cout << "Data is empty" << std::endl;
    else if(data.find_last_not_of("0123456789.-") == std::string::npos)
        std::cout << "Data is not a number" << std::endl;
    else if(value < 0.0)
        std::cout << "Error: " << "Not a positive number ." << std::endl;
    else if(value > 1000.0)
        std::cout << "Error: " << "Too large a number" << std::endl;
    else
    {
        this->value = data;
        this->btc = true;
    }
}

void BitcoinExchange::parseData2(const std::string &line)
{
    // std::cout << "Parsing data: " << line << std::endl;
    std::stringstream ss(line); 
    std::string date;
    std::string data;
    while (std::getline(ss, date, ',') && std::getline(ss, data, ','))
    {
        this->data[date] = data;
    }
}

void BitcoinExchange::parseData(const std::string &line)
{
    this->btc = false;
    std::stringstream ss(line); 
    std::string date;
    std::string data;
    while (std::getline(ss, date, '|') && std::getline(ss, data, '|'))
    {
        check_date(date);
        check_data(data);
    }
    if(line.find_first_not_of(date) == std::string::npos || line.find_first_not_of(data) == std::string::npos || line.find_first_not_of("| ") == std::string::npos)
    {
        std::cout << "Error: " <<"bad input:" << " " << line << std::endl;
    }
}
void BitcoinExchange::readData(const std::string &filename)
{
    std::ifstream file;
    file.open(filename.c_str(), std::ios::in);
    if (!file.is_open())
    {
        file.clear();
        file.open(filename.c_str(), std::ios::out | std::ios::app);
        if (!file.is_open())
        {
            throw std::runtime_error("Failed to create or open file.");
        }
    }
    std::string line;
    while (std::getline(file, line))
    {
        parseData(line);
        std::ifstream another_file;
        another_file.open("data.csv", std::ios::in);

        std::string line2;
        valid_date = tokens[0] + "-" + tokens[1] + "-" + tokens[2];
        while (std::getline(another_file, line2))
        {
            parseData2(line2);
        }
        another_file.close();
        if (btc == true)
        {
            double closestResult = 0.0;
            std::string closestDate;

            std::map<std::string, std::string>::iterator it;
            for (it = data.begin(); it != data.end(); ++it)
            {
                const std::string &date = it->first;
                if (date < valid_date)
                {
                    double result = std::strtod(it->second.c_str(), NULL) * std::strtod(value.c_str(), NULL);
                    if (result <= 1000.0 && (closestDate.empty() || date > closestDate))
                    {
                        closestDate = date;
                        closestResult = result;
                    }
                }
            }

            if (!closestDate.empty())
            {
                std::cout << closestDate << " ===> " << value << " = " << closestResult << std::endl;
            }
            else
            {
                std::cout << "Error: No smaller date found" << std::endl;
            }
        }
    }

    file.close();
}
