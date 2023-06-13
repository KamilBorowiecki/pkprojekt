#pragma once
#include "Rent.h"

class Connect : public Analizator, GeneratorArbitralny, Oscyloskop, Rent
{
public:
	std::vector<std::string> link;
	static int count;
	static int k;
	static int i;
	static int l;
	std::string nameuse;

	void assign(std::string name, std::string object1, std::string object2);
	void showPerson(std::vector<std::string> table, std::vector<std::string>);
	void eqPrintoutBusy(std::string object1, std::string object2);
	void magazyn(Multimetr tab1, Oscyloskop tab2, Analizator tab3, GeneratorArbitralny tab4);
	void addToTXTp(std::vector<std::string> table, std::vector<std::string>);
	void readPersons();
};

