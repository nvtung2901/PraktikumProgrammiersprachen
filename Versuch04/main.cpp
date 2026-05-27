//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
// Versuch 04: Einf�hrung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"
#define ERDRADIUS 6371.0
#define KORPER 1.70
#define HOHE 555.7

int main()
{
    
    Vektor vector1(1, 0, 0);
    Vektor vector2(0, 1, 0);

    vector1.ausgabe();
    vector2.ausgabe();

    //Test
    std::cout << "Vector 1 - Vector 2 ergibt: " << std::endl;
    vector1.sub(vector2).ausgabe();

    std::cout << "Die Laenge von Vector 1: ";
    std::cout << vector1.laenge() << std::endl;

    std::cout << "Die Skalarprodukt von Vector 1 und 2: ";
    std::cout << vector1.skalarProd(vector2) << std::endl;

    std::cout << "Die Winkel zwischen Vector 1 und 2: ";
    std::cout << vector1.winkel(vector2) << std::endl;

    std::cout << "Vector 1 wird um 90 Grad rotiert." << std::endl;
    vector1.rotiereUmZ(M_PI/2);
    vector1.ausgabe();

    Vektor erdRadius(0, ERDRADIUS, 0);      // bitte sinnvoll initialisieren
    Vektor aussichtsPunkt(0, ERDRADIUS + KORPER/1000 + HOHE/1000, 0); // bitte sinnvoll initialisieren
    Vektor sicht(0, 0, 0);

    double schritt = 0.000001;
    double fehler = 0.000001;
    int zaehler = 0;

    while(true)
    {
    	sicht = erdRadius.sub(aussichtsPunkt);
    	double winkel = sicht.winkel(erdRadius);
    	if(sqrt((winkel - 90)*(winkel - 90)) <= fehler) //Absolut-Fehlerrechnung
    	{
    		break;
    	}

    	erdRadius.rotiereUmZ(-schritt); //rotiereUmZ dreht gegen Uhrzeigersinn, deswegen negativ
    	zaehler++;
    }

    double distanz = sicht.laenge();
    double winkel = erdRadius.winkel(aussichtsPunkt);

    /*std::cout << std::fixed;
    std::cout << "\nSie können " << std::setprecision(4) << distanz  << " Km weit sehen." << std::endl;
    std::cout << "Sie sind " << std::setprecision(4) << KORPER + HOHE << " Meter hoch." << std::endl;
    std::cout << "Die Winkel beträgt " << std::setprecision(4) << winkel << " Grad" << std::endl;
    std::cout << "Anzahl Schritte: " << zaehler << std::endl;*/

    std::cout << std::fixed;
    std::cout << "\nSie können " << std::setprecision(10) << distanz  << " Km weit sehen." << std::endl;
    std::cout << "Sie sind " << std::setprecision(10) << KORPER + HOHE << " Meter hoch." << std::endl;
    std::cout << "Die Winkel beträgt " << std::setprecision(10) << winkel << " Grad" << std::endl;
    std::cout << "Anzahl Schritte: " << zaehler << std::endl;

    return 0;

}
