#include <iostream>
#include <fstream>
#include <string>
#include "register.h"

void newUserUsername()
{
	std::ofstream fout("usernames.txt", std::ofstream::out | std::ofstream::app);
	if (fout.is_open())
	{
		std::cout << "Please create a username: " << std::endl;
		std::string newuser;
		std::cin >> newuser;
		fout << newuser << std::endl;
	}
}
void newUserPassword()
{
	std::ofstream fout("passwords.txt", std::ofstream::out | std::ofstream::app);

	if (fout.is_open())
	{
		std::cout << "Please create a password: " << std::endl;
		std::string newpass;
		std::cin >> newpass;
		fout << newpass << std::endl;
	}
}


