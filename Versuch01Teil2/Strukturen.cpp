/////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
// Versuch 1.2: Strukturen
//
// Datei:  Strukturen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

//Strukt deklarieren
struct Person {
	std::string sNachname, sVorname;
	int iGeburtsjahr, iAlter;
};

int main()
{
    Person nBenutzer;

    //Informationen eingeben
    std::cout << "Ihr Vorname? ";
    std::cin >> nBenutzer.sVorname;
    std::cout << "Ihr Nachname? ";
    std::cin >> nBenutzer.sNachname;
    std::cout << "Ihr Geburtsjahr? ";
    std::cin >> nBenutzer.iGeburtsjahr;
    std::cout << "Ihr Alter? ";
    std::cin >> nBenutzer.iAlter;

    //Informationen ausgeben
    std::cout << "\nInformationen des Benutzers:" << std::endl;
    std::cout << "Vorname: " << nBenutzer.sVorname << std::endl;
    std::cout << "Nachname: " << nBenutzer.sNachname << std::endl;
    std::cout << "Geburtsjahr: " << nBenutzer.iGeburtsjahr << std::endl;
    std::cout << "Alter: " << nBenutzer.iAlter << std::endl;

    //Einzeln kopieren
    Person nKopieEinzeln;
    nKopieEinzeln.sVorname = nBenutzer.sVorname;
    nKopieEinzeln.sNachname = nBenutzer.sNachname;
    nKopieEinzeln.iGeburtsjahr = nBenutzer.iGeburtsjahr;
    nKopieEinzeln.iAlter = nBenutzer.iAlter;

    //Gesamt kopieren
    Person nKopieGesamt = nBenutzer;

    //Ausgabe Einzeln-Kopie
    std::cout << "\nInformationen der Einzeln-Kopie:" << std::endl;
    std::cout << "Vorname: " << nKopieEinzeln.sVorname << std::endl;
    std::cout << "Nachname: " << nKopieEinzeln.sNachname << std::endl;
    std::cout << "Geburtsjahr: " << nKopieEinzeln.iGeburtsjahr << std::endl;
    std::cout << "Alter: " << nKopieEinzeln.iAlter << std::endl;
    
    //Ausgabe Gesamt-Kopie
    std::cout << "\nInformationen der Gesamt-Kopie:" << std::endl;
    std::cout << "Vorname: " << nKopieGesamt.sVorname << std::endl;
    std::cout << "Nachname: " << nKopieGesamt.sNachname << std::endl;
    std::cout << "Geburtsjahr: " << nKopieGesamt.iGeburtsjahr << std::endl;
    std::cout << "Alter: " << nKopieGesamt.iAlter << std::endl;
	return 0;
}
