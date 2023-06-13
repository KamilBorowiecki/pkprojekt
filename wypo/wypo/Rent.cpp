#include "Rent.h"

Rent::Rent() 
{
	size = 0;
	sinceData = "no data";
	untilData = "no data";
	person = "no data";
}

Rent::Rent(const std::string& p, const std::string& s, const std::string& u)
{
	person = p;
	sinceData = s;
	untilData = u;
}

Rent::~Rent() 
{
	
}



void Rent::add()
{
	std::cout << "| Enter a name |" << std::endl;
	std::cin.ignore();
	std::getline(std::cin, person);
	base.push_back(person);

	std::cout << "| Enter date of receipt |" << std::endl;
	std::cin >> sinceData;
	base.push_back(sinceData);

	std::cout << "| Enter date of return |" << std::endl;
	std::cin >> untilData;
	base.push_back(untilData);

	std::cout << "| You added next person |" << std::endl;
}

void Rent::show()
{
	
	for (int i = 0; i < base.size(); i++)
	{
		
		if (i % 3 == 0)
		{

			std::cout << (i/3)+1 << ". " << base[i] << " ";

		}
		if (i % 3 == 1)
		{
			std::cout << base[i] << " ";
		}
		if (i % 3 == 2)
		{
			std::cout << base[i] << std::endl;
		}
	}
}
int Rent::choosenr() 
{
	int number;
	std::cout << "| Choose person you want to delete or 0 to go back |" << std::endl;
	
	while (!(std::cin >> number) || number > (base.size()/3) || number < 0)
	{
		std::cout << "| ENTER A NUMBER FROM 1 TO " << (base.size() / 3) << " |" << std::endl;
		std::cin.clear();
		std::cin.ignore();
	}
	return number;
}

void Rent::deletePerson(int size)
{
	if (size != 0) {
		size = size - 1;
		auto name = base.begin() + size;
		base.erase(name, name + 3);
		std::cout << "| You delete person number " << size + 1 << " |" << std::endl;
	}
}

std::string Rent::personAdd()
{
	std::cout << "| Choose a person |" << std::endl;
	int number;
	std::string name;
	while (!(std::cin >> number) || number > (base.size()/3) || number<1)
	{
		std::cout << "| ENTER A NUMBER FROM 1 TO " << (base.size()/3) << " |" << std::endl;
		std::cin.clear();
		std::cin.ignore();
	}
	number = (number - 1) * 3;
	name = base[number];
	
	return name;
}

std::vector<std::string> Rent::names()
{
	
	std::vector <std::string> names;
	for (int i = 0; i < base.size(); i++)
	{
		if (i % 3 == 0)
		{
			names.push_back(base[i]);
		}
	}
	return names;
}

void Rent::setbase()
{
	std::ifstream file("persons.txt");
	std::string name, eq1, eq2, line, date1, date2, idk;
	int i = 0;
	char kropka;
	int number;


	while (std::getline(file, line))
	{
		std::size_t found = line.find("|");

		if (found != std::string::npos)
		{
			std::string restOfLine = line.substr(found + 1);
			std::istringstream iss(restOfLine);

			std::string number, kropka, name, date1, date2, idk;
			iss >> number >> name >> date1 >> date2 >> idk;

			base.push_back(name);
			base.push_back(date1);
			base.push_back(date2);
		}
	}
}

std::vector<std::string> Rent::getbase()
{

	std::vector <std::string> copybase;
	for (int i = 0; i < base.size(); i++)
	{
		copybase.push_back(base[i]);
	}
	return copybase;
}

std::ostream& operator<<(std::ostream& os, const Rent& o) {
	os << "brand: " << o.sinceData << ", min: " << o.untilData << ", interval: " << o.person;
return os;
}

