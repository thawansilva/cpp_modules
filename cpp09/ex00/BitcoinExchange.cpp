#include "BitcoinExchange.hpp"
#include <sstream>

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
			value = std::stod(line.substr(pos + 1));
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << ": could not parse value." << std::endl;
			continue ;
		}
		setData(date, value);
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

void	BitcoinExchange::setData(std::string &key, double value)
{
	_data[key] = value;
}

//bool is_leap_year(int year) {
//    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
//}
//
//// Main validation function
//bool validate_date_string(const std::string& date_str) {
//    // 1. Strict Syntax Check: "YYYY-MM-DD" must be exactly 10 characters long
//    if (date_str.length() != 10) {
//        return false;
//    }
//    if (date_str[4] != '-' || date_str[7] != '-') {
//        return false;
//    }
//
//    // 2. Parse values using a stringstream
//    std::istringstream ss(date_str);
//    int year, month, day;
//    char dash1, dash2;
//
//    if (!(ss >> year >> dash1 >> month >> dash2 >> day)) {
//        return false; // Failed to parse numbers
//    }
//
//    // 3. Logical Range Checks
//    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31) {
//        return false;
//    }
//
//    // 4. Month-Specific Day Counts
//    int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//
//    // Adjust for leap years
//    if (month == 2 && is_leap_year(year)) {
//        days_in_month[1] = 29;
//    }
//
//    if (day > days_in_month[month - 1]) {
//        return false; // Day exceeds max days for this month
//    }
//
//    return true;
//}

static bool	isValidLine(std::string &line)
{
	std::istringstream ss(line);
	int		year, month, day;
	char	delimiter1, delimiter2;

	if (ss >> year >> delimiter1 >> month >> delimiter2 >> day)
	{
		if (delimiter1 != '-' || delimiter1 != '-')
		{
			std::cerr << "Error: bad input" << std::endl;
			return (0);
		}
	}
	// Finish validation
	return (1);
}

void	BitcoinExchange::readInput(std::string &input)
{
	std::ifstream	file(input);
	if (!file.is_open())
		throw std::runtime_error("Error: Could not open input file");

	std::string	line;
	bool	isFirstLine = 1;
	while (std::getline(file, line))
	{
		if (isFirstLine)
		{
			isFirstLine = 0;
			continue ;
		}
		if (!isValidLine(line))
			continue ;
	}
}
