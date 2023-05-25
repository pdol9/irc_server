#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>


int main(){

		std::string limit;
		std::string user;
		std::string addBanList;

		std::string flags = "lvb";
		std::vector<std::string> parameters;
		parameters.push_back("#2");
		parameters.push_back("+b");
		parameters.push_back("10");
		parameters.push_back("MyUser");
		parameters.push_back("WERWERmask");


		// std::stringstream ss;
		// ss << parameters[2] << " ";
		// ss << parameters[3] << " ";
		// ss >> limit;
		// ss >> user;
		// std::cout << " limit and user: " << limit << " " << user << std::endl;
			std::cout << " parameters.size(): " <<parameters.size() << std::endl;

		std::stringstream ss;
		if (parameters.size() > 2) {
			ss << parameters[2] << " ";
			std::cout << " parameters[2]: " <<parameters[2] << std::endl;
		}
		if (parameters.size() > 3) {
			ss << parameters[3] << " ";
			std::cout << " parameters[3]: " <<parameters[3] << std::endl;
		}
		if (parameters.size() > 4) {
			ss << parameters[4] << " ";
			std::cout << " parameters[4]: " <<parameters[4] << std::endl;
		}
		if (flags.find_first_of('l') != std::string::npos){
			ss >> limit;
			std::cout << " _______ limit: " <<limit << std::endl;
		}
		if (flags.find_first_not_of("lb") != std::string::npos){
			ss >> user;
			std::cout << " _______ user: " <<user << std::endl;
		}
		if (flags.find_first_of('b') != std::string::npos){
			ss >> addBanList;
			std::cout << " _______ banList: " <<addBanList << std::endl;
		}
	return 0;
}