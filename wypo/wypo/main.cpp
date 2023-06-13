
#include <iostream>
#include "Connect.h"

int main()
{
    Warehouse* wsk;

    //multimetr
    Multimetr m;
    wsk = &m;
    wsk->getNumber();
    Multimetr tabela1(Multimetr::count);

    //oscyloskop
    Oscyloskop o;
    wsk = &o;
    wsk->getNumber();
    Oscyloskop tabela2(Oscyloskop::count);

    //analizator
    Analizator a;
    wsk = &a;
    wsk->getNumber();
    Analizator tabela3(Analizator::count);

    //generator
    GeneratorArbitralny g;
    wsk = &g;
    wsk->getNumber();
    GeneratorArbitralny tabela4(GeneratorArbitralny::count);



    Connect rent;
    rent.magazyn(tabela1, tabela2, tabela3, tabela4);
    rent.readPersons();

    Rent osoba;
    osoba.setbase();
    int number;

    while (true)
    {
        std::string eq="nic";

        std::cout << "---------------MENU---------------" << std::endl;
        std::cout << "0.Quit" << std::endl;
        std::cout << "1.Add person" << std::endl;
        std::cout << "2.Delete person" << std::endl;
        std::cout << "3.Available measuring equipment" << std::endl;
        std::cout << "4.Customers list" << std::endl;
        std::cout << "5.Rent equipment" << std::endl;
        std::cout << "6.Quick preview" << std::endl;
        std::cout << "7.Person printout" << std::endl;
        std::cout << "8.Equipment printout" << std::endl;
        std::cout << "----------------------------------" << std::endl;

        while (!(std::cin >> number) || number>8) 
        {
            std::cout << "| ENTER A NUMBER FROM 0 TO 8 |"<<std::endl;
            std::cin.clear();
            std::cin.ignore();
            std::cout << "---------------MENU---------------" << std::endl;
            std::cout << "0.Quit" << std::endl;
            std::cout << "1.Add person" << std::endl;
            std::cout << "2.Delete person" << std::endl;
            std::cout << "3.Available measuring equipment" << std::endl;
            std::cout << "4.Customers list" << std::endl;
            std::cout << "5.Rent equipment" << std::endl;
            std::cout << "6.Quick preview" << std::endl;
            std::cout << "7.Persons printout" << std::endl;
            std::cout << "8.Equipment printout" << std::endl;
            std::cout << "----------------------------------" << std::endl;
        }
        switch (number)
        {
        case 0:
            exit(0);
        case 1:
            osoba.add();
            break;

        case 2:
            osoba.show();
            osoba.deletePerson(osoba.choosenr());
            break;

        case 3:
            std::cout << "-------------EQUIPMENT-------------" << std::endl;
            std::cout << "multimetr" << std::endl;
            std::cout << "oscyloskop" << std::endl;
            std::cout << "analizator" << std::endl;
            std::cout << "generator arbitralny" << std::endl;
            std::cout << "return" << std::endl;

            while (eq != "return")
            {
                std::cin >> eq;
                if (eq == "multimetr") {
                    wsk = &tabela1;
                    wsk->show();

                }
                else if (eq == "oscyloskop") {
                    wsk = &tabela2;
                    wsk->show();

                }
                else if (eq == "analizator") {
                    wsk = &tabela3;
                    wsk->show();

                }
                else if (eq == "generator") {
                    wsk = &tabela4;
                    wsk->show();

                }
            }
            break;

        case 4:
            std::cout << "-------------CUSTOMERS-------------" << std::endl;
            osoba.show();
            break;

        case 5:
            
            std::cout << "-------------EQUIPMENT-------------" << std::endl;
            std::cout << "multimetr" << std::endl;
            std::cout << "oscyloskop" << std::endl;
            std::cout << "analizator" << std::endl;
            std::cout << "generator arbitralny" << std::endl;
            std::cout << "return" << std::endl;

            while (eq != "return")
            {
                std::cin >> eq;
                if (eq == "multimetr") {
                    std::string p, q, e;
                    int nr;

                    osoba.show();
                    p=osoba.personAdd();
                    wsk = &tabela1;
                    wsk->show();
                    nr = wsk->chooseNr();
                    q = wsk->eqAddbrand(nr);
                    e = wsk->eqAddmodel(nr);
                    rent.assign(p,q,e);
                }
                else if (eq == "oscyloskop") {
                    std::string p, q, e;
                    int nr;

                    osoba.show();
                    p=osoba.personAdd();
                    wsk = &tabela2;
                    wsk->show();
                    nr = wsk->chooseNr();
                    q = wsk->eqAddbrand(nr);
                    e = wsk->eqAddmodel(nr);
                    rent.assign(p, q, e);
                }
                else if (eq == "analizator") {
                    std::string p, q, e;
                    int nr;

                    osoba.show();
                    p=osoba.personAdd();
                    wsk = &tabela3;
                    wsk->show();
                    nr = wsk->chooseNr();
                    q = wsk->eqAddbrand(nr);
                    e = wsk->eqAddmodel(nr);
                    rent.assign(p, q, e);
                }
                else if (eq == "generator") {
                    std::string p, q, e;
                    int nr;

                    osoba.show();
                    p=osoba.personAdd();
                    wsk = &tabela4;
                    wsk->show();
                    nr = wsk->chooseNr();
                    q = wsk->eqAddbrand(nr);
                    e = wsk->eqAddmodel(nr);
                    rent.assign(p, q, e);
                }
            }
            break;

        case 6:

            rent.showPerson(osoba.names(), osoba.getbase());
            break;

        case 7:
            rent.addToTXTp(osoba.names(), osoba.getbase());
            break;

        case 8:
            std::cout << "-------------EQUIPMENT-------------" << std::endl;
            std::cout << "multimetr" << std::endl;
            std::cout << "oscyloskop" << std::endl;
            std::cout << "analizator" << std::endl;
            std::cout << "generator arbitralny" << std::endl;
            std::cout << "return" << std::endl;

            while (eq != "return")
            {
                std::cin >> eq;
                if (eq == "multimetr") {
                    std::string q, e;
                    int nr;

                    wsk = &tabela1;
                    wsk->show();
                    nr = wsk->chooseNr();
                    q = wsk->eqAddbrand(nr);
                    e = wsk->eqAddmodel(nr);
                    rent.eqPrintoutBusy(q, e);
                }
                else if (eq == "oscyloskop") {
                    std::string q, e;
                    int nr;

                    wsk = &tabela2;
                    wsk->show();
                    nr = wsk->chooseNr();
                    q = wsk->eqAddbrand(nr);
                    e = wsk->eqAddmodel(nr);
                    rent.eqPrintoutBusy(q, e);
                }
                else if (eq == "analizator") {
                    std::string q, e;
                    int nr;

                    wsk = &tabela3;
                    wsk->show();
                    nr = wsk->chooseNr();
                    q = wsk->eqAddbrand(nr);
                    e = wsk->eqAddmodel(nr);
                    rent.eqPrintoutBusy(q, e);
                }
                else if (eq == "generator") {
                    std::string q, e;
                    int nr;

                    wsk = &tabela4;
                    wsk->show();
                    nr = wsk->chooseNr();
                    q = wsk->eqAddbrand(nr);
                    e = wsk->eqAddmodel(nr);
                    rent.eqPrintoutBusy(q, e);
                }
            }
            break;
        }
   
        
    }

}


