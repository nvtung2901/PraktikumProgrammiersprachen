//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
//////////////////////////////////////////////////////////////////////////////

#include "Liste.h"

/**
 * @brief Standardkonstruktor, der eine leere Liste erstellt
 */
Liste::Liste(): front(nullptr), back(nullptr)
{
}

/**
 * @brief Hinzufuegen eines neuen Listenelements am Ende der Liste.
 *
 * @param pData Zeiger auf ein Objekt der Klasse Student
 * @return void
 */
void Liste::pushBack(Student pData)
{
    ListenElement* neuesElement = new ListenElement(pData, back, nullptr );

    if (front == nullptr)                                       // Liste leer?
    {
        front = neuesElement;
        back = neuesElement;
    }
    else
    {
        back->setNext(neuesElement);
        back = neuesElement;
    }
}

/**
 * @brief Entfernen eines Listenelements am Anfang der Liste.
 *
 * @return void
 */
void Liste::popFront()
{
    ListenElement* cursor = front;

    if (front == back)                                       // Liste enth�lt nur ein Listenelement
    {
        delete front;                                        // Listenelement l�schen
        front = nullptr;
        back = nullptr;
    }
    else
    {
        front = front->getNext();
        front->setPrev(nullptr);
        delete cursor;
    }
}

/**
 * @brief Pruefen, ob die Liste leer ist
 *
 * @return wenn leer true, sonst false
 */
bool Liste::empty()
{
    if(front == nullptr)
    {
        return true;
    }
    return false;
}

/**
 * @brief Gibt die Daten des ersten Listenelements in der Liste zurueck
 *
 * @return Zeiger auf ein Objekt der Klasse Student
 */
Student Liste::dataFront()
{
    return front->getData();
}

/**
 * @brief Ausgabe der Liste vom ersten bis zum letzten Element.
 *
 * @return void
 */
void Liste::ausgabeVorwaerts() const
{
    ListenElement* cursor = front;

    while (cursor != nullptr)
    {
    	cursor->getData().ausgabe();
        cursor = cursor->getNext();
    }
}

void Liste::ausgabeRueckwaerts() const
{
	ListenElement* cursor = back;

	while (cursor != nullptr)
	{
		cursor->getData().ausgabe();
		cursor = cursor->getPrev();
	}
}

void Liste::loeschen(ListenElement* cursor)
{
	if (cursor == front) // Fuer das erste Element
	{
		popFront();
	}
	else if (cursor == back) // Fuer das letzte Element
	{
		back = cursor->getPrev();
		back->setNext(nullptr);
		delete cursor;
	}
	else // Fuer Elemente, die mittendrin sind
	{
		cursor->getPrev()->setNext(cursor->getNext());
		cursor->getNext()->setPrev(cursor->getPrev());
		delete cursor;
	}
}

void Liste::loeschenMatNr(unsigned int matNr)
{
	ListenElement* cursor = front;
	while(cursor != nullptr)
	{
		if (cursor->getData().getMatNr() == matNr)
		{
			cursor->getData().ausgabe();
			std::cout << "wird geloescht" << std::endl;
			loeschen(cursor);
			return;
		}
		cursor = cursor->getNext();
	}
	std::cout << "Die Liste ist leer oder es gibt keinen Student mit dieser Matrikelnummer" << std::endl;
}
