#pragma once
#include <iostream>
#include <fstream>

class BitcoinExchange
{
private:
	std::ifstream _input;
	std::ifstream _dbDefault;
public:
	BitcoinExchange();
	explicit BitcoinExchange(const char *db);
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& src);
	BitcoinExchange& operator=(const BitcoinExchange& src);

	//Member Functions
};

std::ostream&	operator<<(std::ostream& out, const BitcoinExchange& src);
