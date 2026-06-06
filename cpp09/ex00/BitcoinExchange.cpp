#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const char *db)
{
	_input.open(db);
	if (!_input.is_open())
	{
		std::cerr << "Error: Could not open input file;" << std::endl;
		return ;
	}
	_dbDefault.open("data.csv");
	if (!_dbDefault.is_open())
	{
		std::cerr << "Error: Could not open default file;" << std::endl;
		return ;
	}
}

BitcoinExchange::~BitcoinExchange()
{
	_input.close();
	_dbDefault.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
{
	*this = src;
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& src)
{
	(void)src;
	return *this;
}

std::ostream&	operator<<(std::ostream& out, const BitcoinExchange& src)
{
	(void)out;
	(void)src;
	return (out);
}
