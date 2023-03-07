#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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
	std::ifstream usernames("usernames.txt");
	std::vector<std::string> usernameList;

	// read all usernames from the file into a vector
	int count = 0;
	if (usernames.is_open())
	{
		std::string line;
		while (std::getline(usernames, line))
		{
			count++;
			usernameList.push_back(line);
		}
		usernames.close();
	}
	bool found = false;
	while (!found)
	{
		std::cout << "Enter your Username: " << std::endl;
		std::string usernameLogin;
		std::cin >> usernameLogin;
		for (const auto& username : usernameList)
		{
			if (username == usernameLogin)
			{
				found = true;
				break;
			}
		}
		if (!found)
		{
			std::cout << "Username not found. Please re-enter." << std::endl;
		}
		else
		{
			count = usernameList.size();
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