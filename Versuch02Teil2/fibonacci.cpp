//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
// Versuch 02
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>

int fibonacci(int n)
{

	int previousFib = 0; //fibonacci(0)
    int currentFib = 1; //fibonacci(1)
    if(n == 0)
    {
        return 0;
    }
    if(n == 1)
    {
        return 1;
    }
    for (int i = 2; i <= n; i++)
    {
        int newFib = previousFib + currentFib ;
        previousFib = currentFib ; //fibonacci(n-2) = fibonacci(n-1)
        currentFib = newFib ; //fibonacci(n-1) = fibonacci(n)
    }
    return currentFib ;
}

int main ()
{
    std::cout << " Fibonacci - Zahlen von 0 bis 12:" << std::endl ;
    for (int i = 1; i <= 12 ; i ++)
    {
        std::cout << "f(" << i << ") = " << fibonacci(i) << std::endl ;
    }
    return 0;

    /*2.2.2.3 Das iterative Fibonacci Programm ist deutlich schneller, weil seine Laufzeit linear ist also O(n)
     * Fuer das rekursive Programm, ist seine Laufzeit O(2^n), da jede Fibonacci muss 2 kleinere Fibonacci aufrufen*/
    /*2.2.2.4 Die Fibonacci ist als int deklariert, also 4 Byte = 32 Bit fuer Speicherung, also von -2^31 zu 2^31 - 1
     * fibonacci(47) ist grosser als die Grenze und die erste Bit(Vorzeichen) wird von 0 zu 1.
     * Deswegen ist das Ergebnis fuer 47 negativ und falsch => Max richtige Fibonacci ist n=46, also 1836311903*/
}
