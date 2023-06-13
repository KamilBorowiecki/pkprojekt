#include "Connect.h"
std::string nameuse="nic";
int Connect::l = 0;
int Connect::count = 1;
int Connect::k = 0;
int Connect::i = 0;

void Connect::assign(std::string n, std::string o, std::string o2)
{
	link.push_back(n);
	link.push_back(o);
    link.push_back(o2);
}

void Connect::eqPrintoutBusy(std::string object1, std::string object2)
{
    std::ofstream file("equipment.txt", std::ios::app);
    count = 1;
    file<< "| " << object1 << " " << object2 << " |" << std::endl;
    if (file) 
    {
        for (i = 1; i < link.size(); i = i + 3)
        {
            if (object1 + object2 == link[i] + link[i + 1])
            {
                file << count++ << ". " << link[i - 1] << std::endl;
            }
        }
    }
    file.close();
    std::cout << "| YOU PRINTOUT EQUIPMENT TO TXT |" << std::endl;
}

void Connect::showPerson(std::vector<std::string> table, std::vector<std::string> base)
{

    int n = 0;
    int j = 0;
    k = 0;
    count = 1;
    i = 0;

    if (link.empty())
    {
        std::cout << "| ANY PERSON DON'T RENT EQUIPMENT |" << std::endl;
    }
    else {
        while (i < table.size())
        {
            if (i % 2 == 0) {
                if (table[i] == link[k])
                {
                    n = i;
                    n = (n * 3);
                    std::cout << std::endl << "| " << count++ << ". " << base[n] << " " << base[n + 1] << " " << base[n + 2] << " |" << std::endl;

                    for (j = 0; j < link.size(); j = j + 3)
                    {
                        if (table[i] == link[j])
                        {
                            std::cout << link[j + 1] << " " << link[j + 2] << std::endl;
                        }
                    }
                    i++;
                }
                else if (table[i] != link[k])
                {
                    k = k + 3;
                }
            }
            else if (i % 2 == 1)
            {
                if (table[i] == link[k])
                {
                    n = i;
                    n = (n * 3);
                    std::cout << std::endl << "| " << count++ << ". " << base[n] << " " << base[n + 1] << " " << base[n + 2] << " |" << std::endl;

                    for (j = 0; j < link.size(); j = j + 3)
                    {
                        if (table[i] == link[j])
                        {
                            std::cout << link[j + 1] << " " << link[j + 2] << std::endl;
                        }
                    }
                    i++;
                }
                else if (table[i] != link[k])
                {
                    k = k + 3;
                }
            }
        }

    }
}



void Connect::addToTXTp(std::vector<std::string> table, std::vector<std::string> base)
{
    
    int n;
    std::ofstream file("persons.txt");
    int j = 0;
    k = 0;
    count = 1;
    i = 0;

    if (table.empty())
    {
        std::cout << "| YOU DON'T ADD ANY PERSON YET |" << std::endl;
    }
    else if (link.empty())
    {
        std::cout << "| ANY PERSON DON'T RENT EQUIPMENT |" << std::endl;
    }
    else {
            while (file && i < table.size())
            {
                if (i % 2 == 0) {
                    if (table[i] == link[k])
                    {
                        n = i;
                        n = (n * 3);
                        file << "| " << count++ << ". " << base[n] << " " << base[n + 1] << " " << base[n + 2] << " |" << std::endl;

                        for (j = 0; j < link.size(); j = j + 3)
                        {
                            if (table[i] == link[j])
                            {
                                file << link[j + 1] << " " << link[j + 2] << std::endl;
                            }
                        }
                        i++;
                    }
                    else if (table[i] != link[k])
                    {
                        k = k + 3;

                    }
                }
                else if (i % 2 == 1)
                {
                    if (table[i] == link[k])
                    {
                        n = i;
                        n = (n * 3);
                        file << "| " << count++ << ". " << base[n] << " " << base[n + 1] << " " << base[n + 2] << " |" << std::endl;

                        for (j = 0; j < link.size(); j = j + 3)
                        {
                            if (table[i] == link[j])
                            {
                                file  << link[j + 1] << " " << link[j + 2] << std::endl;
                            }
                        }
                        i++;
                    }
                    else if (table[i] != link[k])
                    {
                        k = k + 3;
                    }
                }
            }
            file.close();
            std::cout << "| YOU PRINTOUT PERSONS WITH EQUIPMENT TO TXT |" << std::endl;

    }
}

void Connect::magazyn(Multimetr tab1, Oscyloskop tab2, Analizator tab3, GeneratorArbitralny tab4)
{
    std::ifstream file("plik.txt");
    std::string line;

    if (file.is_open()) {
        while (file) {
            while (std::getline(file, line)) {
                std::size_t foundMultimetr = line.find("multimetr");
                std::size_t foundOscyloskop = line.find("oscyloskop");
                std::size_t foundAnalizator = line.find("analizator");
                std::size_t foundGenerator = line.find("generator");

                if (foundMultimetr != std::string::npos) {
                    Multimetr multimetr;

                    
                    std::string restOfLine = line.substr(foundMultimetr + 9); 
                    std::istringstream iss(restOfLine);
                    iss >> multimetr.brand >> multimetr.price >> multimetr.model >> multimetr.weight;

                    tab1.add(multimetr);

                    break;

                }
                else if (foundOscyloskop != std::string::npos) {
                    Oscyloskop oscyloskop;
                    std::string restOfLine = line.substr(foundOscyloskop + 10); 
                    std::istringstream iss(restOfLine);

                    iss >> oscyloskop.brand >> oscyloskop.price >> oscyloskop.model >> oscyloskop.weight >> oscyloskop.bandWidth >> oscyloskop.numberOFchannels >> oscyloskop.samplingFrequency;

                    tab2.add(oscyloskop);

                    break;
                }
                else if (foundAnalizator != std::string::npos) {
                    Analizator analizator;
                    std::string restOfLine = line.substr(foundAnalizator + 10); 
                    std::istringstream iss(restOfLine);

                    iss >> analizator.brand >> analizator.price >> analizator.model >> analizator.weight >> analizator.frequencyRange >> analizator.impedance;

                    tab3.add(analizator);

                    break;
                }
                else if (foundGenerator != std::string::npos) {
                    GeneratorArbitralny generator;
                    std::string restOfLine = line.substr(foundGenerator + 9); 
                    std::istringstream iss(restOfLine);

                    iss >> generator.brand >> generator.price >> generator.model >> generator.weight >> generator.MaxSamplingFrequency >> generator.MaxOutputFrequency;

                    tab4.add(generator);

                    break;
                }

                file.close();
            }
        }
    }
    else
    {
        std::cout << "Nie mo¿na otworzyæ pliku." << std::endl;
    }

}

void Connect::readPersons()
{
    std::ifstream file("persons.txt");
    std::string eq1, eq2, line, date1, date2, idk;
    int i = 0;
    int number;


    while (std::getline(file, line))
    {
        std::size_t found = line.find("|");

        if (found != std::string::npos)
        {
            std::string restOfLine = line.substr(found + 1);
            std::istringstream iss(restOfLine);

            std::string number, kropka, name, date1, date2, idk;
            iss >> number >> nameuse >> date1 >> date2 >> idk;

        }
        else
        {
            std::istringstream iss(line);

            std::string eq1, eq2;
            iss >> eq1 >> eq2;
            link.push_back(nameuse);
            link.push_back(eq1);
            link.push_back(eq2);

        }
    }
   
}