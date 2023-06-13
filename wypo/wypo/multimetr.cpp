#include "multimetr.h"



Multimetr::Multimetr() {
	brand = "no data";
	price = 0;
	model = "no data";
	weight = 0;
	number = 0;
}

Multimetr::Multimetr(int s) {
	size = s;
	tabMult = new Multimetr[s];
}

Multimetr::Multimetr(const std::string& b, double p, std::string m, double w) {
	brand = b;
	price = p;
	model = m;
	weight = w;
	
}



void Multimetr::add(const Multimetr& o)
{

	/*tabMult.push_back(o);*/




	
	static int i = 0;
	tabMult[i] = o;
	i++;
	
	
}
void Multimetr::show()
{

	/*for (int i = 0; i < tabMult.size(); i++)
	{
		std::cout << tabMult[i] << std::endl;
	}*/


						

	std::cout << std::endl << "| Multimetry |" << std::endl;
	for (int i = 0; i < count; i++)
	{
		int number = i+1;
		std::cout << number << ". " << tabMult[i] << std::endl;
	}
}

int Multimetr::getNumber()
{
	

	std::ifstream file("plik.txt");
	std::string word;
	

	while (std::getline(file, word))
	{
		std::size_t foundMultimetr = word.find("multimetr");
		if (foundMultimetr != std::string::npos)
		{
			count++;
		}
	}

	return count;
}

int Multimetr::chooseNr()
{
	std::cout << "| Choose yours multimetr |" << std::endl;
	while (!(std::cin >> number) || number > count || number < 1)
	{
		std::cout << "| ENTER A NUMBER FROM 1 TO " << count << " |" << std::endl;
		std::cin.clear();
		std::cin.ignore();
	}
	return number;
}

std::string Multimetr::eqAddbrand(int number)
{
	number = number - 1;
	std::string object;
	object = tabMult[number].brand;
	return object;
}

std::string Multimetr::eqAddmodel(int number)
{
	number = number - 1;
	std::string object2;
	object2 = tabMult[number].model;
	return object2;
}

std::ostream& operator<<(std::ostream& os, const Multimetr &o) {
	os << "brand: " << o.brand << ", cena: " << o.price << "zl" << ", model: " << o.model << ", waga: " << o.weight << "kg";
	return os;
}

Multimetr::~Multimetr()
{

}

int Multimetr::count = 0;