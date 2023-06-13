#include "Analizator.h"

int Analizator::count = 0;

Analizator::Analizator() 
{
	frequencyRange = "no data";
	impedance = NULL;

}

Analizator::Analizator(const std::string& b, double p, std::string m, double w, const std::string& f, int i)
:Multimetr(b, p, m, w)
{
	frequencyRange = f;
	impedance = i;
}

Analizator::~Analizator() {}

Analizator::Analizator(int s)
	:Multimetr(s)
{
	size = s;
	tabAnal = new Analizator[s];
}


void Analizator::add(const Analizator& o)
{

	/*tabMult.push_back(o);*/





	static int i = 0;
	tabAnal[i] = o;
	i++;


}
void Analizator::show()
{

	std::cout << std::endl << "| Analizator |" << std::endl;
	for (int i = 0; i < count; i++)
	{
		int number = i + 1;
		std::cout << number << ". " << tabAnal[i] << std::endl;
	}
}

int Analizator::getNumber()
{


	std::ifstream file("plik.txt");
	std::string word;


	while (std::getline(file, word))
	{
		std::size_t foundMultimetr = word.find("analizator");
		if (foundMultimetr != std::string::npos)
		{
			count++;
		}
	}

	return count;
}

std::string Analizator::eqAddbrand(int number) 
{

	number = number - 1;
	std::string object;
	object = tabAnal[number].brand;

	return object;
}

std::string Analizator::eqAddmodel(int number)
{
	number = number - 1;
	std::string object2;
	object2 = tabAnal[number].model;

	return object2;
}



int Analizator::chooseNr()
{
	std::cout << "| Choose yours analizator |" << std::endl;
	while (!(std::cin >> number) || number > count || number < 1)
	{
		std::cout << "| ENTER A NUMBER FROM 1 TO " << count << " |" << std::endl;
		std::cin.clear();
		std::cin.ignore();
	}
	return number;
}

std::ostream& operator<<(std::ostream& os, const Analizator& o) {
	os << "brand: " << o.brand << ", min: " << o.price << "zl , model: " << o.model << ", weight: " << o.weight << "kg , frequency range: " << o.frequencyRange << ", impedance: " << o.impedance<<" Ohm";
	return os;
}