#include <iostream>
#include <string>
#include <random>

//name generator, DEC:(A - 65, Z - 90, a - 97, z - 122)

void pause()
{
	std::cout << "\n. . . press ENTER to continue . . .\n";
	std::cin.get();
	std::cin.get();
}

int select_length()
{
	int length = 0;
	do
	{
		std::cout << "How many letters will the name contain?: ";
		std::cin >> length;
	} while (!std::cin.good());

	return length;
}

void make_capital(std::string * _name)
{
	int mask = 0xDF; // (mask bitwise : 11011111)
	_name->at(0) = _name->at(0) & mask;
}

bool f_repeat()
{
	char character;
	std::cout << "\nDo you want to reroll name? (y/n):";
	std::cin >> character;

	if (character == 'y') {
		return true;
	}
	else
		return false;
}

int main()
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(97, 122);

	bool repeat = 1;

	while (repeat)
	{
		std::string name;
		int length = select_length();

		for (int i = 0; i < length; ++i)
		{
			char character = dist(mt);
			name += character;
		}
		make_capital(&name);

		std::cout << "Your name is: " << name;
		repeat = f_repeat();
	}
	pause();
}
