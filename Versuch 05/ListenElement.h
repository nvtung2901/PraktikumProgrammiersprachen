//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
//////////////////////////////////////////////////////////////////////////////

#ifndef _LISTENELEMENT_H_
#define _LISTENELEMENT_H_

#include "Student.h"

class ListenElement
{
private:
    Student data;
    ListenElement* prev;
    ListenElement* next;

public:
    ListenElement(Student pData,ListenElement* pPrev, ListenElement* pNext);

    void setData(Student pData);
    void setNext(ListenElement* pNext);
    void setPrev(ListenElement* pPrev);

    Student getData() const;
    ListenElement* getNext() const;
    ListenElement* getPrev() const;
};

#endif
