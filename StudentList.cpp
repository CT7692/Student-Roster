//*****************************************************************************************************
//
//		File:				StudentList.cpp
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
//      Other files required: LinkedList.h 
//							  Student.h
//							  Node.h
//			
//		
//*****************************************************************************************************

#include<fstream>

#include "Student.h"
#include "LinkedList.h"

//*****************************************************************************************************

char getChoice();
void process(LinkedList<Student>&);
void buildList(LinkedList<Student>&);
void displayStudents(const LinkedList<Student>&);
void countStudents(const LinkedList<Student>&);
void deleteStudent(LinkedList<Student>&);
void findStudent(const LinkedList<Student>&);

//*****************************************************************************************************

int main()
{
	LinkedList<Student> studentList;
	buildList(studentList);
	process(studentList);

	return 0;
}

//*****************************************************************************************************

char getChoice()
{
	const string LINE = string(50, '*');
	LinkedList<Student> data;

	char opt;

	cout << LINE << endl;
	cout << "Welcome" << endl;
	cout << "A: Search for a student." << endl;
	cout << "B: Delete student from roster." << endl;
	cout << "C: Count students on roster." << endl;
	cout << "D: Display roster." << endl;
	cout << "E: Quit." << endl;
	cout << "\nEnter choice: ";
	cin >> opt;
	opt = toupper(opt);

	while (opt < 'A' || opt > 'E')
	{
		cout << "Incorrect. Try again." << endl;
		cout << "Enter choice: ";
		cin >> opt;
		opt = toupper(opt);
	}

	return opt;
}

//*****************************************************************************************************

void buildList(LinkedList<Student>& stu)
{
	ifstream fin;
	fin.open("studentFile.txt");
	Student obj;
	if (fin.fail())
	{
		cout << "SYSTEMWIDE FAILURE!" << endl;
		exit(0);
	}
	else
	{
		while (fin >> obj)
		{
			bool success = stu.insert(obj);

			if (success == false)
				cout << "Failed to insert file." << endl;
		}
		fin.close();
	}
}

//*****************************************************************************************************

void process(LinkedList<Student>& stu)
{
	char opt = getChoice();

	while (opt != 'e' && opt != 'E')
	{
		if (opt == 'a' || opt == 'A')
		{
			findStudent(stu);
		}

		else if (opt == 'b' || opt == 'B')
		{
			deleteStudent(stu);
		}

		else if (opt == 'c' || opt == 'C')
		{
			countStudents(stu);
		}

		else if (opt == 'd' || opt == 'D')
		{
			displayStudents(stu);
			cout << '\n';
		}

		opt = getChoice();
	}

	cout << "Good-bye." << endl;
}

//***************************************************************************************************** 

void displayStudents(const LinkedList<Student>& stu)
{
	cout << "D: Display roster." << endl;
	cout << '\n';
	bool success = stu.display();

	if (success == false)
		cout << "There is no list." << endl;
}

//***************************************************************************************************** 

void countStudents(const LinkedList<Student>& stu)
{
	cout << "C: Count number of students on roster." << endl;
	cout << "We have " << stu.getSize() << " students on record.\n" << endl;
}

//***************************************************************************************************** 

void deleteStudent(LinkedList<Student>& stu)
{
	Student data;

	cout << "B: Delete student from roster." << endl;
	cout << "Enter ID number: ";
	cin >> data.id;

	bool success = stu.del(data);

	if (success == false)
		cout << "This ID does not match our records." << endl;
	else
		cout << data.id <<
		": " << data.name << " " << data.major <<
		" " << data.gpa << 
		" removed from roster." << endl;
	
}

//***************************************************************************************************** 

void findStudent(const LinkedList<Student>& stu)
{
	Student data;
	cout << "A: Search for a student." << endl;
	cout << "Enter ID number: ";
	cin >> data.id;

	if (!stu.find(data))
		cout << "This ID does not match our records." << endl;
	else
		cout << "Found: " << data.id <<
		": " << data.name << " " << data.major <<
		" " << data.gpa << endl;

}

//*****************************************************************************************************

//**************************************************
//Welcome
//A : Search for a student.
//B : Delete student from roster.
//C : Count students on roster.
//D : Display roster.
//E : Quit.
//
//Enter choice : c
//C : Count number of students on roster.
//We have 61 students on record.
//
//* *************************************************
//Welcome
//A : Search for a student.
//B : Delete student from roster.
//C : Count students on roster.
//D : Display roster.
//E : Quit.
//
//Enter choice : k
//Incorrect.Try again.
//Enter choice : j
//Incorrect.Try again.
//Enter choice : d
//D : Display roster.
//
//3930 : Leibniz, Gottfried W MATH 1.95
//4454 : Atanasoff, Eniac C CPSC 1.88
//4559 : Shyster, Samuel D SOCI 1.95
//4777 : Gauss, Carl F MATH 4
//5316 : GotoDijkstra, Edgar G CPSC 4
//5430 : Nightingale, Florence K NURS 3.15
//5710 : Busch, Arch E ENGR 2.75
//5873 : Psycho, II, Prunella E PSYC 2.99
//7107 : Shoemaker, Imelda M POLS 3.15
//7448 : Roosevelt, Rose Y POLS 2.95
//7844 : Aardvark, Anthony A ENGR 2.79
//7885 : Fibonacci, Leonard O MATH 3.25
//9463 : Hochschule, Hortense C EDUC 2.7
//9743 : Johnson, James L ENGR 3.15
//10236 : Andrews, Peter J CPSC 2.78
//10304 : Deutsch, Sprechen Z GERM 3.05
//11688 : Kronecker, Leo P MATH 2.75
//11749 : Issacson, Jacob A RELI 2.99
//11951 : Mouse, Michael E EDUC 1.99
//13511 : Pitt, Stew GNED 0.21
//14674 : Rockne, Newton K PE 1.98
//14815 : Tchaikovsky, Wolfgang A MUSC 2.75
//15052 : Einstein, Alfred M ENGR 2.78
//15671 : Rembrandt, Roberta E ART 2.2
//15755 : VandenVander, Vanessa V HIST 3.74
//15802 : Pascal, Blaze R CPSC 1.98
//15889 : Gazelle, Gwendolyn D PE 2.78
//16183 : Kuts, Cole FOOD 3.98
//16540 : Weerd, Dewey L PHIL 2.99
//16622 : Issacson, Esau B RELI 2.98
//17376 : Scrooge, Ebenezer T SOCI 3.25
//17424 : Nakamura, Toky O SOCI 1.95
//18213 : Marx, Karl Z ECON 2.75
//18264 : Lucky, Lucy L HIST 2.29
//19077 : Medes, Archie L ENGR 3.1
//19918 : Virus, Vera W CPSC 3.25
//20454 : Chicita, Juanita A BIOL 2.66
//20991 : Augusta, Ada B CPSC 3.83
//21144 : Pasteur, Louise A BIOL 3.1
//22277 : Principal, Pamela P EDUC 1.75
//22447 : Zylstra, Zelda A ENGL 1.95
//23314 : Macdonald, Ronald B CPSC 2.99
//23497 : Fault, Paige D CPSC 2.95
//23544 : Gestalt, Gloria G PSYC 2.48
//23750 : Vespucci, Vera D GEOG 2.29
//24237 : Euler, Lennie L MATH 3.83
//25377 : Porgy, Bess N MUSI 2.78
//25831 : Santamaria, Nina P HIST 1.77
//26316 : Custer, General G HIST 1.95
//27503 : Fahrenheit, Felicia O CHEM 3.85
//28658 : Cicero, Marsha LATI 2.87
//29583 : Yewliss, Cal C MATH 2.99
//30268 : Newmann, Alfred E EDUC 0.99
//30280 : Dewey, Johanna A EDUC 3.83
//30381 : Elba, Able M SPEE 3.4
//30655 : Angelo, Mike L ART 3.74
//30749 : Mendelssohn, Mozart W MUSC 2.87
//30878 : Lewis, Clark N GEOG 3.37
//31631 : Aristotle, Alice A PHIL 3.1
//32598 : Xerxes, Art I GREE 3.25
//32631 : Freud, JR, Fred E PSYC 1.85
//
//* *************************************************
//Welcome
//A : Search for a student.
//B : Delete student from roster.
//C : Count students on roster.
//D : Display roster.
//E : Quit.
//
//Enter choice : a
//A : Search for a student.
//Enter ID number : 5430
//Found : 5430 : Nightingale, Florence K NURS 3.15
//* *************************************************
//Welcome
//A : Search for a student.
//B : Delete student from roster.
//C : Count students on roster.
//D : Display roster.
//E : Quit.
//
//Enter choice : b
//B : Delete student from roster.
//Enter ID number : 4777
//4777 : Gauss, Carl F MATH 4 removed from roster.
//* *************************************************
//Welcome
//A : Search for a student.
//B : Delete student from roster.
//C : Count students on roster.
//D : Display roster.
//E : Quit.
//
//Enter choice : c
//C : Count number of students on roster.
//We have 60 students on record.
//
//* *************************************************
//Welcome
//A : Search for a student.
//B : Delete student from roster.
//C : Count students on roster.
//D : Display roster.
//E : Quit.
//
//Enter choice : e
//Good - bye.
//
//C : \Users\josep\source\repos\COSC_3050_Assi5\Debug\COSC_3050_Assi5.exe(process 21772) exited with code 0.
//Press any key to close this window . . .
