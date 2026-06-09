#pragma once
#include <iostream>
#include <map>
#include <fstream>

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
	void	setData(std::string &key, double value);
	void	readInput(std::string &input);
};
