#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>

// char c = '-';
char c = '+';

// std::string _banList = "*!*@*1,*!*@*.edu2,*!*@uni.*3,*xyz!*@*4,abc*!*@*5,";
std::string _banList;

std::string banMask0 = "*!*@*1";
std::string banMask1 = "*!*@*.edu2";
std::string banMask2 = "*!*@uni.*3";
std::string banMask3 = "*xyz!*@*4";
std::string banMask4 = "abc*!*@*5";
// std::string banMask5 = "";

void	manageBanList(std::string banMask) {

	if (c == '+')
	{
		_banList = _banList + banMask + ",";
		return;
	}
	else if (c == '-' && banMask.size() > 5)
	{
		size_t pos = _banList.find(banMask + ",");
		if (pos != std::string::npos)
			_banList.erase(pos, banMask.length() + 1);
	}
	std::cout << "//debug: " << _banList << std::endl;
}

void test(std::string& str)
{
////////
	if (str == "")
		std::cout << "str == ""\n";
	if (!str.length())
		std::cout << "!str.length()\n";
	if (str.length())
		std::cout << "size is 0\n";

	if (str.length() < 2)
		std::cout << "size is less than 2\n";
////////
}

int main(int argc, char **argv) {

	std::string name = "";
	test(name);
	// std::cout << "//start: " << _banList << std::endl;
	// manageBanList(banMask2);
	// manageBanList(banMask4);
	// manageBanList(banMask1);
	// manageBanList(banMask3);
	// manageBanList(banMask0);
	// std::cout << "//end:  " << _banList << std::endl;
	// std::cout << "     **********************************  "<< std::endl;
	// c = '-';
	// std::cout << "//start: " << _banList << std::endl;
	// manageBanList(banMask2);
	// manageBanList(banMask4);
	// manageBanList(banMask1);
	// manageBanList(banMask3);
	// manageBanList(banMask0);
	// std::cout << "//end:  " << _banList << std::endl;
	return 0;
}
