///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 2.3: Felder
//
// Datei:  Verschuesselung.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

using namespace std;

#include <iostream>
#include <string>

string verschluesseln(char schluessel[2][26], string wort)
{
	// Hier folgt Ihr Code
	int len = wort.length();
	for(int i = 0; i < len; i++)
	{
		for(int j = 0; j < 26; j++)
		{
			if(wort[i] == schluessel[0][j])
			{
				wort[i] = schluessel[1][j];
				break;
			}
		}
	}

	return wort;
}

string entschluesseln(char schluessel[2][26], string wort)
{
	// Hier folgt Ihr Code
	int len = wort.length();
	for(int i = 0; i < len; i++)
	{
		for(int j = 0; j < 26; j++)
		{
			if(wort[i] == schluessel[1][j])
			{
				wort[i] = schluessel[0][j];
				break;
			}
		}
	}

	return wort;
}

int main()
{
	// Hier folgt Ihr Code
	char schluessel[2][26] = {{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'},
							  {'H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','A','B','C','D','E','F','G'}};
	//Verschluesselung
	string wort;
	cout << "Geben Sie zur Verschuluesselung ein Wort ein (nur Grossbuchstaben): ";
	cin >> wort;
	string vwort = verschluesseln(schluessel, wort);
	cout << "\nDas ursprungliche Wort: " << wort << endl;
	cout << "Das verschluesselte Wort: " << vwort << endl;

	//Entschluesselung
	string vwort2;
	cout << "\nGeben Sie zur Verschuluesselung ein Wort ein (nur Grossbuchstaben): ";
	cin >> vwort2;
	string wort2 = entschluesseln(schluessel, vwort2);
	cout << "\nDas verschluesselte Wort: " << vwort2 << endl;
	cout << "Das entschluesselte Wort: " << wort2 << endl;

	return 0;
}
