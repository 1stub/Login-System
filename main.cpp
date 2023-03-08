#include <iostream>
#include "login.h"
#include "register.h"

int main()
{
	int x = 1;
	while (x != 0)
	{
		std::cout << "Please select one of the options below." << std::endl;
		std::cout << "[1] Login" << std::endl;
		std::cout << "[2] Register" << std::endl;
		std::cout << "[3] Exit" << std::endl;
		int choice{};
		std::cin >> choice;
		if (choice == 1)
		{
			int count = findUsername();
			findPassword(count);
		}
		else if (choice == 2)
		{
			newUserUsername();
			newUserPassword();
		}
		else if (choice == 3)
		{
			break;
		}
		else
		{
			std::cout << "Please select a valid option." << std::endl;
		}
	}
	return 0;
}