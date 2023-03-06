#include <iostream>
#include <fstream>
#include <string>
#include "register.h"

void newUser()
{
	std::cout << "Please create a username: " << std::endl;
	std::string newuser;
	std::cin >> newuser;
	std::ofstream usernames;
	usernames.open("usernames.txt");
	usernames << newuser;
	usernames.close();
	std::cout << "Please create a password: " << std::endl;
	std::string newpass;
	std::cin >> newpass;
	std::ofstream passwords;
	passwords.open("passwords.txt");
	passwords << newpass;
	passwords.close();
}