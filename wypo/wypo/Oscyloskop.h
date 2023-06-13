#pragma once
#include "multimetr.h"



class Oscyloskop : public Multimetr 
{
public:
	std::string bandWidth;
	int numberOFchannels;
	int samplingFrequency;
	Oscyloskop* tabOscy;
	static int count;


	Oscyloskop();
	Oscyloskop(int size);
	Oscyloskop(const std::string& brand, double price, const std::string& model, double weight, std::string& bandWidth, int numberOFchannels, int samplingFrequency);
	~Oscyloskop();

	void add(const Oscyloskop& obj);
	void show() override;
	std::string eqAddmodel(int number);
	std::string eqAddbrand(int number);
	int getNumber();
	int chooseNr();

	friend std::ostream& operator <<(std::ostream& s, const Oscyloskop&);
};

