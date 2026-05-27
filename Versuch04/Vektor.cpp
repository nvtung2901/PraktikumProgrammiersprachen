//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 04: Einf�hrung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"

Vektor::Vektor(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ)
{

}

Vektor::~Vektor()
{

}

Vektor Vektor::sub(const Vektor& input) const
{
	Vektor vektor(this->x - input.x, this->y - input.y, this->z - input.z);
	return vektor;
}

double Vektor::laenge() const
{
	return sqrt(x*x + y*y + z*z);
}

double Vektor::skalarProd(const Vektor& input) const
{
	return (this->x * input.x) + (this->y * input.y) + (this->z * input.z);
}

double Vektor::winkel(const Vektor& input) const
{
	double l1 = this->laenge();
	double l2 = input.laenge();
	double skalar = this->skalarProd(input);

	if(l1 == 0 || l2 == 0) //Fall es Nullvektorgibt
	{
		return 0.0;
	}

	double cos_alph = skalar/(l1*l2);

	//Ungenauigkeit kontrollieren
	if (cos_alph > 1.0) cos_alph = 1.0;
	if (cos_alph < -1.0) cos_alph = -1.0;

	double rad = acos(cos_alph);
	return rad * (180/M_PI);
}

void Vektor::rotiereUmZ(const double rad)
{
	double s = std::sin(rad);
	double c = sqrt(1 - s*s); //Bei mir funktioniert cos() fuer pi/2 nicht
	double x_rot = c*x - s*y;
	double y_rot = s*x + c*y;
	x = x_rot;
	y = y_rot;
}

/**
 * @brief Function printing the components of the vector 
 */
void Vektor::ausgabe() const
{
    std::cout << "X-Komponente: " << x << std::endl;
    std::cout << "Y-Komponente: " << y << std::endl;
    std::cout << "Z-Komponente: " << z << std::endl << std::endl;
}
