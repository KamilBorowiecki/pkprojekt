#include "GeneratorArbitralny.h"

int GeneratorArbitralny::count = 0;

GeneratorArbitralny::GeneratorArbitralny()
{
	MaxSamplingFrequency = NULL;	//Maksymalna czêstotliwoœæ próbkowania
	MaxOutputFrequency = NULL;		//Maksymalna czêstotliwoœæ wyjœciowa 
}

GeneratorArbitralny::GeneratorArbitralny(const std::string& b, double p, std::string m, double w, int s, int o )
	:Multimetr(b, p, m, w)
{
	MaxSamplingFrequency = s;
	MaxOutputFrequency = o;
}

GeneratorArbitralny::~GeneratorArbitralny() {}

GeneratorArbitralny::GeneratorArbitralny(int s)
	:Multimetr(s)
{
	size = s;
	tabGene = new GeneratorArbitralny[s];
}


void GeneratorArbitralny::add(const GeneratorArbitralny& o)
{

	/*tabMult.push_back(o);*/





	static int i = 0;
	tabGene[i] = o;
	i++;


}
void GeneratorArbitralny::show()
{

	/*for (int i = 0; i < tabMult.size(); i++)
	{
		std::cout << tabMult[i] << std::endl;
	}*/




	std::cout << std::endl << "| GeneratorArbitralny |" << std::endl;
	for (int i = 0; i < count; i++)
	{
		int number = i + 1;
		std::cout << number << ". " << tabGene[i] << std::endl;
	}
}

int GeneratorArbitralny::getNumber()
{


	std::ifstream file("plik.txt");
	std::string word;


	while (std::getline(file, word))
	{
		std::size_t foundMultimetr = word.find("generator");
		if (foundMultimetr != std::string::npos)
		{
			count++;
		}
	}

	return count;
}

std::string GeneratorArbitralny::eqAddbrand(int number)
{
	std::string object;
	number = number - 1;
	object = tabGene[number].brand;

	return object;
}

std::string GeneratorArbitralny::eqAddmodel(int number)
{
	std::string object2;
	number = number - 1;
	object2 = tabGene[number].model;

	return object2;
}

int GeneratorArbitralny::chooseNr()
{
	std::cout << "| Choose yours generator |" << std::endl;
	while (!(std::cin >> number) || number > count || number < 1)
	{
		std::cout << "| ENTER A NUMBER FROM 1 TO " << count << " |" << std::endl;
		std::cin.clear();
		std::cin.ignore();
	}
	return number;
}

std::ostream& operator<<(std::ostream& os, const GeneratorArbitralny& o) {
	os << "brand: " << o.brand << ", min: " << o.price << "zl , model: " << o.model << ", weight: " << o.weight << "kg , max sampling frequency: " << o.MaxSamplingFrequency << "MSa/s , max output frequency: " << o.MaxOutputFrequency<<" MHz";
	return os;
}
