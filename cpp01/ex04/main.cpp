#include <iostream>
#include <fstream>
#include <cstring>

void	createOutputReplace(const char *filename, std::ifstream &file,
		std::string target, std::string replace)
{
	std::string		outputName = filename;
	std::ofstream	outputFile((outputName + ".replace").c_str());
	std::string		line;
	std::size_t		found;

	while (std::getline(file, line))
	{
		found = line.find(target);
		while (found != std::string::npos)
		{
			line.erase(found, target.length());
			line.insert(found, replace);
			found = line.find(target);
		}
		outputFile << line << std::endl;
	}
	outputFile.close();
}

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "Invalid number of arguments\n";
		std::cerr << "Usage: ./sed <filename> <target> <replacement>" << std::endl;
		return 0;
	}
	const char			*filename = argv[1];
	std::string const	target = argv[2];
	std::string const	replacement = argv[3];
	if (target.empty())
	{
		std::cerr << "Empty target is not allowed" << std::endl;
		return (0);
	}

	std::ifstream		file(filename);
	if (!file.is_open())
	{
		std::cerr << "File doesn't exist." << std::endl;
		file.close();
		return (0);
	}
	createOutputReplace(filename, file, target, replacement);
	file.close();
	return (0);
}
