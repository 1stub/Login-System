#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "register.h"

void newUserUsername()
{
	std::ofstream fout("usernames.txt", std::ofstream::out | std::ofstream::app);
	if (fout.is_open())
	{
		int x{ 0 };
		while (x != 1)
		{
			std::ifstream fin("usernames.txt");
			std::cout << "Please create a username: " << std::endl;
			std::string newuser;
			std::cin >> newuser;
			std::vector <std::string> userCheck;
			std::string vectorCheck;
			while (fin >> vectorCheck)
			{
				userCheck.push_back(vectorCheck);
			}
			if (newuser.size() > 20)
			{
				std::cout << "Maximum size is 20 characters. Please choose a new username" << std::endl;
			}
			if (std::find(userCheck.begin(), userCheck.end(), newuser) != userCheck.end())
			{
				std::cout << "Username already exists. Please create a different username." << '\n';
			}
			else
			{
				fout << newuser << std::endl;
				x = 1;
			}
		}
	}
}
void newUserPassword()
{
	std::ofstream fout("passwords.txt", std::ofstream::out | std::ofstream::app);

	if (fout.is_open())
	{
		int x{ 0 };
		while (x != 1)
		{
			std::cout << "Please create a password: " << std::endl;
			std::string newpass;
			std::cin >> newpass;
			std::ifstream fin("passwords.txt");
			std::vector <std::string> passCheck;
			std::string vectorCheck;
			while (fin >> vectorCheck)
			{
				passCheck.push_back(vectorCheck);
			}
			if (newpass.size() > 16)
			{
				std::cout << "Password is too long. Maximum size is 16 characters. Please re-enter" << std::endl;
			}
			else
			{
				fout << newpass << std::endl;
				x = 1;
			}
		}
	}
}


