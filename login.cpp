#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "login.h"

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
		for (const auto& usernames : usernameList)
		{
			count++;
			if (usernames == usernameLogin)
			{
				found = true;
				break;
			}
		}
		if (!found)
		{
			std::cout << "Username not found. Please re-enter." << std::endl;
		}
	}
	return count;
}
void findPassword(int count)
{
	std::ifstream passwords; passwords.open("passwords.txt");
	std::vector<std::string>passwordList;

	if (passwords.is_open())
	{
		std::string line;
		while (std::getline(passwords, line))
		{
			passwordList.push_back(line);
		}
		passwords.close();
	}
	bool found = false;
	while (!found)
	{
		std::cout << "Enter your Password: " << std::endl;
		std::string passwordLogin;
		std::cin >> passwordLogin;
		//for (const auto& password : passwordList)
		const int COUNT = count - 1;
		std::string vector_val = passwordList[COUNT];
			if (passwordLogin == vector_val)
			{
				std::cout << "Valid Username and Password. Welcome to my software!" << std::endl;
				found = true;
				break;
			}
			else
			{
				std::cout << "Password not found. Please re-enter." << std::endl;
			}
		
	}
}