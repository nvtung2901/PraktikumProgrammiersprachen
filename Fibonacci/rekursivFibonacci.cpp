/////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
// Versuch 2.1: Rekursiv-Fibonacci
//
// Datei:  rekursivFibonacci.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>

//Formel erstellen
int f(int n)
{
	//Anfangswerte
	if(n == 0) return 0;
	if(n == 1) return 1;
	//Fuer alle n >= 2
	return f(n-1) + f(n-2);

}

int main()
{
	std::cout << "Fibonacci-Reihe fuer n = 0 bis 25:" << std::endl;
	for(int i = 0; i <= 25; i++)
	{
		std::cout << "f(" << i << ") = " << f(i) << std::endl;
	}
}
