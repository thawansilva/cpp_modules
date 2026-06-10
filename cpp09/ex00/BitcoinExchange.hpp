#pragma once
#include <iostream>
#include <map>

class BitcoinExchange
{
private:
	std::map<std::string, double>	_data;

public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& src);
	BitcoinExchange& operator=(const BitcoinExchange& src);

	//Member Functions
	void	setData(const std::string &key, double value);
	void	readInput(const std::string &input);
};
