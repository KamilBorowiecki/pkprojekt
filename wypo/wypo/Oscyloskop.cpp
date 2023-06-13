#include "Oscyloskop.h"

int Oscyloskop::count = 0;

Oscyloskop::Oscyloskop()
{

	bandWidth = "no data";
	numberOFchannels = NULL;
	samplingFrequency = NULL;
}

Oscyloskop::Oscyloskop(int s) 
	:Multimetr(s)
{
	size = s;
	tabOscy = new Oscyloskop[s];
}

Oscyloskop::Oscyloskop(const std::string& b, double p, const std::string& m, double w, std::string& ba, int n, int s)
	:Multimetr(b,p,m,w)
{
	bandWidth = ba;
	numberOFchannels = n;
	samplingFrequency = s;
}

Oscyloskop::~Oscyloskop() {}

void Oscyloskop::add(const Oscyloskop& o)
{

	/*tabMult.push_back(o);*/





	static int i = 0;
	tabOscy[i] = o;
	i++;


}
void Oscyloskop::show()
{

	/*for (int i = 0; i < tabMult.size(); i++)
	{
		std::cout << tabMult[i] << std::endl;
	}*/




	std::cout << std::endl << "| Oscyloskopy |" << std::endl;
	for (int i = 0; i < count; i++)
	{
		int number = i + 1;
		std::cout << number << ". " << tabOscy[i] << std::endl;
	}
}

int Oscyloskop::getNumber()
{


	std::ifstream file("plik.txt");
	std::string word;


	while (std::getline(file, word))
	{
		std::size_t foundMultimetr = word.find("oscyloskop");
		if (foundMultimetr != std::string::npos)
		{
			count++;
		}
	}

	return count;
}

std::string Oscyloskop::eqAddbrand(int number)
{
	number = number - 1;
	std::string object;
	object = tabOscy[number].brand;
	return object;
}

std::string Oscyloskop::eqAddmodel(int number)
{
	number = number - 1;
	std::string object2;
	object2 = tabOscy[number].model;
	return object2;
}

int Oscyloskop::chooseNr()
{
	std::cout << "| Choose yours oscyloskop |" << std::endl;
	while (!(std::cin >> number) || number > count || number < 1)
	{
		std::cout << "| ENTER A NUMBER FROM 1 TO " << count << " |" << std::endl;
		std::cin.clear();
		std::cin.ignore();
	}
	return number;
}

std::ostream& operator<<(std::ostream& os, const Oscyloskop& o) {
	os << "brand: " << o.brand << ", price: " << o.price << "zl , model: " << o.model << ", weight: " << o.weight << "kg , band width: " << o.bandWidth << "MHz , number of channels: " << o.numberOFchannels << ", sampling frequency: " << o.samplingFrequency<< "GS/s";
	return os;
}