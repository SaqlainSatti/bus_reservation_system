// header file and class use for BUS reservation system.
//group members
//.......................................................
//Nabeel Ahmed (01-132162-044)
//saqlain sajid(01-132162-053)
//THIS CLASS CONTAIN ALL THE FUNCTIONS RELATED TO PROGRAM
#include<iostream>
#include<conio.h>
#include<iomanip>
#include<fstream>
#include<string>
#include<stdio.h>
#include<ctype.h>
#include<dos.h>
#include<stdlib.h>
#include <windows.h>
using namespace std;

class TRAVEL
{
	int busno, seatno;
	char name[26], sex;
	int age, fair;
	int dd, mm, yy;
public:
	void INFORMATION(void);
	void RESERVATION(void);
	int RESERVED(int, int, int, int, int);
	int AVAIL(int, int, int, int);
	void DELETION(void);
	void LIST_OF_PASS(void);
	void PASS_INFO(void);
	void MAINMENU(void);

};
