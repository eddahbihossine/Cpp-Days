#ifndef BTC_EXCHANGE_HPP
#define BTC_EXCHANGE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <queue>
#include <map>
#include <sstream>


#include <fstream>
class BitcoinExchange
{
    private:
        std::string filename;
        std::string date;
        std::array<std::string, 3> tokens;
        std::map<std::string, std::string> data;
        std::string value;
        std::string valid_date;
        bool btc;
    public:
        BitcoinExchange();
        BitcoinExchange(const std::string &filename);
        BitcoinExchange(const std::string &filename, const std::string &date);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        void readData(const std::string &filename);
        void parseData(const std::string &line);
        void parseData2(const std::string &line);
        void check_date(const std::string &date);
        void check_file(const std::string &filename);
        void check_data(const std::string &data);

        class FileError : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class DateEmpty : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        class DateError : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class DataError : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        
};

#endif