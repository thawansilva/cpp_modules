#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cmath>

BitcoinExchange::BitcoinExchange()
{
	std::ifstream	db("data.csv");
	if (!db.is_open())
		throw std::runtime_error("Error: Could not open default file");
	
	bool isFirstLine = 1;
	std::string	line;
	while (std::getline(db, line))
	{
		if (isFirstLine)
		{
			isFirstLine = 0;
			continue ;
		}

		std::size_t pos = line.find(',');
		if (pos == std::string::npos)
		{
			std::cerr << "Error: Invalid Parameter" << std::endl;
			continue ;
		}

		std::string date = line.substr(0, pos);
		double	value;
		try
		{
			value = std::atof(line.substr(pos + 1).c_str());
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << ": could not parse value." << std::endl;
			continue ;
		}
		_data[date] = value;
	}
	db.close();
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) { *this = src; }

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& src)
{
	(void)src;
	return *this;
}

static bool	is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

static bool	isValidDate(const std::string& date_str) {
    if (date_str.length() != 10 || date_str[4] != '-' || date_str[7] != '-')
        return false;

    std::istringstream ss(date_str);
    int year, month, day;
    char dash1, dash2;
    if (!(ss >> year >> dash1 >> month >> dash2 >> day))
        return false;

    if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (month == 2 && is_leap_year(year))
        days_in_month[1] = 29;

    if (day > days_in_month[month - 1])
        return false;

    return true;
}

static bool	isValidLine(std::string &line)
{
	std::size_t	p_pos = line.find('|');
	if (p_pos == std::string::npos || line.at(p_pos - 1) != ' ' || line.at(p_pos + 1) != ' ')
	{
		std::cerr << "Error: Bad Input => " << line << std::endl;
		return false;
	}
	return (1);
}

void	BitcoinExchange::readInput(const std::string &input)
{
	std::ifstream	file(input.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: Could not open input file");

	std::string	line;
	bool		isFirstLine = 1;
	while (std::getline(file, line))
	{
		if (isFirstLine)
		{
			isFirstLine = 0;
			continue ;
		}
		if (!isValidLine(line))
			continue ;
		std::string	date = line.substr(0, 10);
		if (!isValidDate(date))
		{
			std::cerr << "Error: Invalid Date => " << date << std::endl;
			continue ;
		}
		std::size_t	p_pos = line.find('|');
		char *end = NULL;
		double		value = std::strtod(line.substr(p_pos + 1).c_str(), &end);
		if (*end != '\0')
		{
			std::cerr << "Error: Invalid value => " << end << std::endl;
			continue ;
		}
		if (value < 0 || value > 1000)
		{
			std::cerr << "Error: Number should be between 0 and 1000" << std::endl;
			continue ;
		}
		std::map<std::string, double>::iterator it = _data.lower_bound(date);
		if (it != _data.begin() && (it == _data.end() || it->first != date))
			--it;
		std::cout << date << " => " << value << " = " << (value * it->second) << std::endl;
	}
	file.close();
}
