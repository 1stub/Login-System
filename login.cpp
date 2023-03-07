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
		for (const auto& password : passwordList)
		{
			std::string vector_val = passwordList[count-1];
			if (passwordLogin == vector_val)
			{
				std::cout << "Those passwords match!" << std::endl;
				break;
			}
			else
			{
				std::cout << "Password not found. Please re-enter." << std::endl;
			}
		}
	}
}