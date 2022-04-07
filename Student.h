//*****************************************************************************************************
//
//		File:				Student.h
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
//							  StudentList.cpp                    
//							  Student.h
//							  Student.cpp
//			
//		
//*****************************************************************************************************

#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
#include<cstring>

using namespace std;

//*****************************************************************************************************

struct Student
{

	int id;
	char name[50];
	char cityState[50];
	char phone[12];
	char gender;
	int year;
	int credits;
	float gpa;
	char major[6];


	Student();
	Student(const Student&);
	Student& operator = (const Student&);
	bool operator == (const Student&) const;
	bool operator != (const Student&) const;
	bool operator < (const Student&) const;
	bool operator <= (const Student&) const;
	bool operator > (const Student&) const;
	bool operator >= (const Student&) const;

	friend istream& operator >> (istream&, Student&);
	friend ostream& operator << (ostream&, const Student&);

};

//*****************************************************************************************************

Student::Student()
{

}

//*****************************************************************************************************

istream& operator >> (istream& strm, Student& stu)
{
	strm >> stu.id;
	strm.ignore();
	strm.getline(stu.name, 50, '\n');
	strm.getline(stu.cityState, 50, '\n');
	strm >> stu.phone;
	strm >> stu.gender;
	strm >> stu.year;
	strm >> stu.credits;
	strm >> stu.gpa;
	strm >> stu.major;
	return strm;
}

//*****************************************************************************************************

ostream& operator << (ostream& strm, const Student& stu)
{
	strm << stu.id << ": " << stu.name << " "
		<< stu.major << " " << stu.gpa << endl;
	return strm;
}

//*****************************************************************************************************

Student::Student(const Student& stu)
{
	this->id = stu.id;
	strcpy_s(this->name, stu.name);
	strcpy_s(this->cityState, stu.cityState);
	strcpy_s(this->phone, stu.phone);
	this->gender = stu.gender;
	this->year = stu.year;
	this->credits = stu.credits;
	this->gpa = stu.gpa;
	strcpy_s(this->major, stu.major);
}

//*****************************************************************************************************

Student& Student::operator = (const Student& stu)
{
	if (this != &stu)
	{
		this->id = stu.id;
		strcpy_s(this->name, stu.name);
		strcpy_s(this->cityState, stu.cityState);
		strcpy_s(this->phone, stu.phone);
		this->gender = stu.gender;
		this->year = stu.year;
		this->credits = stu.credits;
		this->gpa = stu.gpa;
		strcpy_s(this->major, stu.major);
	}

	return *this;
}

//*****************************************************************************************************

bool Student::operator < (const Student& stu) const
{
	return this->id < stu.id;
}

//*****************************************************************************************************

bool Student::operator <= (const Student& stu) const
{
	return this->id <= stu.id;
}

//*****************************************************************************************************

bool Student::operator > (const Student& stu) const
{
	return this->id > stu.id;
}

//*****************************************************************************************************

bool Student::operator >= (const Student& stu) const
{
	return this->id >= stu.id;

}

//*****************************************************************************************************

bool Student::operator != (const Student& stu) const
{
	return this->id != stu.id;

}

//*****************************************************************************************************

bool Student::operator == (const Student& stu) const
{
	return this->id == stu.id;

}
#endif