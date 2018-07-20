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

int selectLength()
{
	int length = 0;
	do 
	{
		std::cout << "How many letters will the name contain?: ";
		std::cin >> length;
	} while (!std::cin.good());

	return length;
}

void makeCapital(std::string * _name) 
{
	int mask = 0xDF; // (mask bitwise : 11011111)
	_name->at(0) = _name->at(0) & mask;
}

int main() 
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(97, 122);

	std::string name;
	int length = selectLength();

	for (int i = 0; i < length; ++i)
	{
		char letter = dist(mt);
		name += letter;
	}

	makeCapital(&name);

	std::cout << "Your name is: " << name;

	pause();
}