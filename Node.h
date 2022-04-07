//*****************************************************************************************************
//
//		File:				Node.h
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
//		Description: This program builds a node.
//					
//		 	
//      Other files required: LinkedList.h 
//							  StudentListDriver.cpp                    
//							  Student.h
//							  
//			
//		
//*****************************************************************************************************

#ifndef NODE_H
#define NODE_H

//*****************************************************************************************************

template<typename T>
struct Node
{
	T data;
	Node<T>* next;

	Node();
	Node(const T& d, Node<T>* n = nullptr);
};

//*****************************************************************************************************

template<typename T>
Node<T>::Node()
{
	data = 0;
	next = nullptr;
}

//*****************************************************************************************************

template<typename T>
Node<T>::Node(const T& d, Node<T>* n)
{
	data = d;
	next = n;
}

#endif