#pragma once
#include "Analizator.h"

class GeneratorArbitralny : public Multimetr
{
public:
	int MaxSamplingFrequency;
	int MaxOutputFrequency;
	GeneratorArbitralny* tabGene;
	static int count;


	GeneratorArbitralny();
	GeneratorArbitralny(int size);
	GeneratorArbitralny(const std::string& brand, double price, std::string model, double weight, int MaxSamplingFrequency, int MaxOutputFrequency);
	~GeneratorArbitralny();

	void add(const GeneratorArbitralny& obj);
	void show() override;
	std::string eqAddmodel(int number);
	std::string eqAddbrand(int number);
	int getNumber();
	int chooseNr();

	friend std::ostream& operator<<(std::ostream& os, const GeneratorArbitralny& o);
};

