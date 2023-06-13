#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
class Warehouse 
{
public:
	
	virtual void show()=0;
	virtual int getNumber()=0;
	virtual std::string eqAddmodel(int m)=0;
	virtual std::string eqAddbrand(int b) = 0;
	virtual int chooseNr()=0;
};