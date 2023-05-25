#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>

// char c = '-';
char c = '+';

// std::string _banList = "*!*@*1,*!*@*.edu2,*!*@uni.*3,*xyz!*@*4,abc*!*@*5,";
std::set<std::string> _banList;

std::string banMask0 = "*!*@*1";
std::string banMask1 = "*!*@*.edu2";
std::string banMask2 = "*!*@uni.*3";
std::string banMask3 = "*xyz!*@*4";
std::string banMask4 = "abc*!*@*5";
// std::string banMask5 = "";

void	manageBanList(std::string banMask) {

	if (c == '+')
		_banList.insert(banMask);
	else if (c == '-' && banMask.size() > 5) {

		std::set<std::string>::iterator it = _banList.find(banMask);
		if (it != _banList.end()) {
			_banList.erase(it);
		}
	}

	std::cout << "// debug the set: " << std::endl;
	std::cout << "   ---------------- " << std::endl;
	for (std::set<std::string>::iterator it = _banList.begin(); it != _banList.end(); ++it)
	{
		std::cout << " " << *it << std::endl;
	}
	std::cout << "   ---------------- " << std::endl;
	// std::cout << "//debug: " << _banList[0] << std::endl;
	// std::cout << "//debug: " << _banList[0] << std::endl;
}

int main(int argc, char **argv) {

	// std::cout << "//start: " << _banList[0] << std::endl;
	manageBanList(banMask2);
	manageBanList(banMask4);
	manageBanList(banMask1);
	manageBanList(banMask3);
	manageBanList(banMask0);
	// std::cout << "//end:  " << _banList[0] << std::endl;
	std::cout << "     **********************************  "<< std::endl;
	c = '-';
	// std::cout << "//start: " << _banList[0] << std::endl;
	manageBanList(banMask2);
	manageBanList(banMask4);
	manageBanList(banMask1);
	manageBanList(banMask3);
	manageBanList(banMask0);
	// std::cout << "//end:  " << _banList[0] << std::endl;
	return 0;
}
