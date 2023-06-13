#pragma once
#include "Oscyloskop.h"

class Analizator : public Multimetr
{
public:
	std::string frequencyRange;
	int impedance;
	Analizator* tabAnal;
	static int count;

	Analizator();
	Analizator(int size);
	Analizator(const std::string& brand, double price, std::string model, double weight, const std::string& frequencyRange,int impedance);
	~Analizator();

	void add(const Analizator& obj);
	void show() override;
	std::string eqAddmodel(int number);
	std::string eqAddbrand(int number);
	int getNumber();
	int chooseNr();

	friend std::ostream& operator<<(std::ostream& os, const Analizator& o);
};

