#include <iostream>
#include <fstream>
#include <string>
#include "login.h"

/*void loginUser()
{
	std::ifstream usernames; usernames.open("usernames.txt");
	if (usernames.is_open())
	{
		std::cout << "Enter your Username: " << std::endl;
		std::string usernameLogin;
		std::cin >> usernameLogin;
		std::string line;
		bool found = false;
		int count = 0;
		int lineNum = 0;
		while( std::getline( usernames , line) && !found)
		{ 
			count++;
			if (line.find(usernameLogin) != std::string::npos)
			{
				found = true;
			}
		}
		if (!found)
		{
			std::cout << "Username not found. Please re-enter." << std::endl;
		}
	}
	std::ifstream passwords; passwords.open("passwords.txt");
	if (passwords.is_open())
	{
			std::cout << "Enter your Password: " << std::endl;
			std::string passwordLogin;
			std::cin >> passwordLogin;
			std::string line;
			bool found = false;
			while (std::getline(usernames, line) && !found)
			{
				if (line.find(passwordLogin) != std::string::npos)
				{
					found = true;
				}
			}
			if (!found)
			{
				std::cout << "Password not found. Please re-enter." << std::endl;
			}
			if (found == true)
			{
				std::cout << "Password Found! " << std::endl;
				exit;
			}
		}
}*/

int findUsername()
{
	std::ifstream usernames; usernames.open("usernames.txt");
	int count = 0;
	int lineNum = 0;	
	int x{ 0 };
	if (usernames.is_open())
	{
		while (x != 1)
		{
			std::cout << "Enter your Username: " << std::endl;
			std::string usernameLogin;
			std::cin >> usernameLogin;
			std::string line;
			bool found = false;
			while (std::getline(usernames, line) && !found)
			{
				count++;
				if (line.find(usernameLogin) != std::string::npos)
				{
					found = true;
					x = 1;
					usernames.close();
				}
				if (!found)
				{
					std::cout << "Username not found. Please re-enter." << std::endl;
				}
			}
		}
	}
	return count;
}

void findPassword(int count)
{
	std::ifstream passwords; passwords.open("passwords.txt");
	if (passwords.is_open())
	{
		std::cout << "Enter your Password: " << std::endl;
		std::string passwordLogin;
		std::cin >> passwordLogin;
		std::string line;
		int current_line = 0;

		while (!passwords.eof())
		{
			current_line++;
			std::getline(passwords, line);
			if (current_line == count)
			{
				std::cout << "Password Found!" << std::endl;
				break;
			}
		}
	}
}