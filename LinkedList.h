//*****************************************************************************************************
//
//		File:				LinkedList.h
//		
//		Student:			Joseph Rydel
//
//		Assignment:	 		Assignment  #5
//
//		Course Name:		Data Structures I                       
//
//		Course Number:		COSC 3050 - 01
//
//		Due:				October 06, 2021 
//
//
//		Description: This program demonstrates a 
//					 linked list class similar to the previous
//					 project that will insert students information
//					 from the file studentFiles.txt. Where the user
//					 will be able to search, delete, or count 
//					 student information.
//					
//		 	
//      Other files required: Node.h
//							  StudentListDriver.cpp                    
//							  Student.h
//			
//			
//		
//*****************************************************************************************************

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<iostream>
#include<new>

using namespace std;

#include "Node.h"

//*****************************************************************************************************

template<typename T>
class LinkedList
{
private:
	Node<T>* front;

public:
	LinkedList();
	~LinkedList();
	bool insert(const T&);
	bool del(T&);
	bool deleteFront(T&);
	bool deleteBack(T&);
	bool deleteAllBut(const T&);
	bool find(T&) const;
	bool viewFront(T&);
	bool viewBack(T&);
	bool isEmpty() const;
	bool isFull();
	bool clearList();
	bool display() const;
	const int getSize() const;
	bool counting(const T&, int&) const;

};

//*****************************************************************************************************

template<typename T>
LinkedList<T>::LinkedList()
{
	front = nullptr;
}

//*****************************************************************************************************

template<typename T>
LinkedList<T>::~LinkedList()
{
	Node<T>* pTemp = nullptr;

	while (front != nullptr)
	{
		pTemp = front;
		front = front->next;
		delete pTemp;
	}
}

//*****************************************************************************************************

template<typename T>
bool LinkedList<T>::insert(const T& dataIn)
{
	bool success = false;
	Node<T>* pPrev = nullptr;
	Node<T>* pAfter = front;
	while (pAfter != nullptr && pAfter->data < dataIn)
	{
		pPrev = pAfter;
		pAfter = pAfter->next;
	}

	Node<T>* pNew = new Node<T>(dataIn, pAfter);

	if (pNew != nullptr)
	{
		if (pPrev != nullptr)
			pPrev->next = pNew;
		else
			front = pNew;
		success = true;
	}
	return success;
}

//*****************************************************************************************************

template<typename T>
bool LinkedList<T>::del(T& dataOut)
{
	bool success = false;

	Node<T>* pPrev = nullptr;
	Node<T>* pTemp = front;

	while (pTemp != nullptr && pTemp->data < dataOut)
	{
		pPrev = pTemp;
		pTemp = pTemp->next;
	}

	if (pTemp != nullptr && pTemp->data == dataOut)
	{

		if (pPrev != nullptr)
		{
			pPrev->next = pTemp->next;
		}
		else
			front = pTemp->next;
		dataOut = pTemp->data;
		delete pTemp;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template<typename T>
bool LinkedList<T>::find(T& desiredData) const
{
	bool success = false;
	Node<T>* pTemp = front;
	while (pTemp != nullptr && pTemp->data < desiredData)
	{
		pTemp = pTemp->next;
	}

	if (pTemp != nullptr && pTemp->data == desiredData)
	{
		desiredData = pTemp->data;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template<typename T>
bool LinkedList<T>::deleteAllBut(const T& dataKeep)
{
	bool success = false;

	Node<T>* pPrev = nullptr;
	Node<T>* pTemp = front;

	while (pTemp != nullptr && pTemp->data < dataKeep)
	{
		pPrev = pTemp;
		pTemp = pTemp->next;
		front = pTemp;
		delete pPrev;

	}

	while (pTemp != nullptr && pTemp->data == dataKeep)
	{
		pPrev = pTemp;
		pTemp = pTemp->next;
		success = true;
	}

	while (pTemp != nullptr && pTemp->data > dataKeep)
	{
		pPrev->next = pTemp->next;
		delete pTemp;
		pTemp = pPrev->next;
	}
	return success;

}

//*****************************************************************************************************

template<typename T>
bool LinkedList<T>::viewBack(T& rearData)
{
	bool success = false;
	Node<T>* pTemp = front;

	while (pTemp != nullptr && pTemp->next != nullptr)
	{
		pTemp = pTemp->next;
	}

	if (pTemp != nullptr)
	{
		rearData = pTemp->data;
		success = true;
	}


	return success;

}

//*****************************************************************************************************

template<typename T>
bool LinkedList<T>::counting(const T& desiredData, int& count) const
{
	bool success = false;
	count = 0;
	Node<T>* pTemp = front;

	while (pTemp != nullptr && pTemp->data <= desiredData)
	{

		if (pTemp->data == desiredData)
			count++;

		pTemp = pTemp->next;


	}
	return success;

}

//*****************************************************************************************************

template<typename T>
bool LinkedList<T>::display() const
{
	bool success = false;
	Node<T>* pTemp;
	pTemp = front;

	while (pTemp != nullptr)
	{
		cout << pTemp->data << " ";
		pTemp = pTemp->next;
		success = true;
	}
	return success;
}

//*****************************************************************************************************

template<typename T>
bool LinkedList<T>::deleteFront(T& dataOut)
{
	bool success = false;

	Node<T>* pTemp = front;

	if (pTemp != nullptr)
	{
		dataOut = pTemp->data;
		front = pTemp->next;
		delete pTemp;
		success = true;
	}

	return success;
}

//*****************************************************************************************************

template<typename T>
bool LinkedList<T>::deleteBack(T& rearData)
{
	bool success = false;
	Node<T>* pTemp;
	Node<T>* pPrev;
	pTemp = front;
	pPrev = nullptr;


	while (pTemp != nullptr && pTemp->next != nullptr)
	{
		pPrev = pTemp;
		pTemp = pTemp->next;
	}

	if (pTemp != nullptr && pTemp->next == nullptr)
	{
		rearData = pTemp->data;
		delete pTemp;
		pPrev->next = nullptr;
		success = true;
	}
	return success;

}

//*****************************************************************************************************

template<typename T>
bool LinkedList<T>::viewFront(T& frontData)
{
	bool success = false;
	Node<T>* pTemp;
	pTemp = front;

	if (pTemp != nullptr)
	{
		frontData = pTemp->data;
		success = true;
	}
	return success;
}

//*****************************************************************************************************

template<typename T>
bool LinkedList<T>::isEmpty() const
{
	return front == nullptr;
}

//*****************************************************************************************************

template<typename T>
bool LinkedList<T>::clearList()
{
	bool success = false;

	Node<T>* pTemp = nullptr;

	while (front != nullptr)
	{
		pTemp = front;
		front = front->next;
		delete pTemp;
	}

	if (front == nullptr)
		success = true;

	return success;
}

//*****************************************************************************************************

template<typename T>
bool LinkedList<T>::isFull()
{
	bool success = false;
	Node<T>* pNew;
	pNew = new (nothrow) Node<T>;

	if (pNew == nullptr)
	{
		delete pNew;
		success = true;
	}
	return success;
}

//*****************************************************************************************************

template<typename T>
const int LinkedList<T>::getSize() const
{
	int size = 0;
	Node<T>* pTemp;
	pTemp = front;

	while (pTemp != nullptr)
	{
		size++;
		pTemp = pTemp->next;
	}
	return size;
}

#endif