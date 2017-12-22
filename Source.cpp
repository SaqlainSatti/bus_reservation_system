
#include"B_r_S.h"

char *place[3] = { "lahore", "peshawar", "murree." };
int price[3] = { 100, 220, 110 };
//THIS FUNCTION DISPLAY THE PASSENGER INFORMATION


void TRAVEL::PASS_INFO(void)
{
	system("cls");
	int bno = 0, found = 0, sno, d, m, y;
	cout << "\n Bus 1:islamabad to lahore.       <fare Rs.100>" << endl;
	cout << "\n Bus 2:islamabad to peshawar.         <fare Rs.220>" << endl;
	cout << "\n Bus 3:isamabad to murree.        <fare Rs.110>" << endl;
	do
	{
		cout << "\n\n enter the busno.(1/2/3)" << endl;
		cin >> bno;
	} while (bno<1 || bno>3);
	cout << "\n\n enter the date of the reserved ticket:" << endl;
	cin >> d;
	cout << "\n\n enter the month:" << endl;
	cin >> m;
	cout << "\n\n enter the year:" << endl;
	cin >> y;
	cout << "\nenter the seat no.:" << endl;
	cin >> sno;
	if (sno>60 || sno<1 || !RESERVED(bno, d, m, y, sno))
	{
		cout << "\n\n\nsorry!\7seat not reserved" << endl;
		_getch();
		return;
	}
	fstream file;
	file.open("BUS.DAT", ios::in);
	while (file.read((char *)this, sizeof(TRAVEL)))
	{
		if ((dd == d&&mm == m&&yy == y) && bno == busno&&sno == seatno)
		{
			found = 1;
			system("cls");


			cout << "**********************************************************************";

			cout << "BUS RESERVATION SYSTEM" << endl;

			cout << "BUS NO." << bno << "\t\t\tDATE:" << d << "/" << m << "/" << y << endl;

			cout << "SEAT NO.:" << sno << endl;

			cout << "FROM:BIKANER" << "\tTo:" << place[bno - 1] << endl;

			cout << "Passenger Name:" << name << endl;

			cout << "Passenger Age:  " << age << "\t\tsex:" << sex << endl;

			cout << "Total Fair   :" << price[bno - 1] << endl;

			cout << "************************************************************************" << endl;

			cout << "press any key to continue...";
			_getch();
			break;
		}
	}
	file.close();
	if (!found)
	{
		cout << "\n\n7passenger record not found" << endl;
		_getch();
	}
}
//This function gives the list of all the passenger
void TRAVEL::LIST_OF_PASS(void)
{
	system("cls");
	int bno = 0, found = 0, row = 8;
	char ch;
	cout << "\n Bus 1:islamabad to lahore.       <fare Rs.100>" << endl;
	cout << "\n Bus 2:islamabad to peshawar.         <fare Rs.220>" << endl;
	cout << "\n Bus 3:isamabad to murre.e        <fare Rs.110>" << endl;
	do
	{
		cout << "\n\nenter the bus no.(1/2/3)";
		cin >> bno;
	} while (bno<1 || bno>3);
	do
	{
		cout << "\n Do you want date wise report(y/n)";
		cin >> ch;
	} while (toupper(ch) != 'N'&& toupper(ch) != 'Y');
	int d = 0, m = 0, y = 0;
	if (toupper(ch) == 'Y')
	{
		cout << "\n\n Enter  date:";
		cin >> d;
		cout << "\n\n Enter month:";
		cin >> m;
		cout << "\n\n Enter year:";
		cin >> y;
	}
	system("cls");
	cout << "LIST OF THE PASSENGERS " << endl;

	cout << "\n***********************************************************************" << endl;

	cout << " BUS NO.:" << bno << "\t\t\t\t\tfrom: BIKANER  TO:" << place[bno - 1] << endl;

	cout << "SEAT NO.   PASSENGER NAME               SEX    AGE    DATE " << endl;

	cout << "**************************************************************************" << endl;
	fstream file;
	file.open("BUS.DAT", ios::in);
	while (file.read((char*)this, sizeof(TRAVEL)))
	{
		if (busno == bno)
		{
			if ((toupper(ch) == 'N') || ((toupper(ch) == 'Y') && (dd == d&&mm == m&&yy == y)))
			{
				found = 1;

				cout << seatno << endl;

				cout << name << endl;

				cout << sex << endl;

				cout << age << endl;

				cout << dd << "/" << mm << "/" << yy << endl;
				row++;
				if (row == 25)
				{
					_getch();
					for (int i = 8; i <= 24; i++)
					{

					}
					row = 8;
				}
			}
		}
	}
	file.close();
	if (!found)
	{
		cout << "\n\n\n\n\n\7No reservation for the bus no. " << bno;
		_getch();
		return;
	}
	cout << "\n\nPress any key to continue..............";
	_getch();
}

int TRAVEL::AVAIL(int bno, int d, int m, int y)
{
	fstream file;
	file.open("BUS.DAT", ios::in);
	int avail = 0, count = 0;
	while (file.read((char*)this, sizeof(TRAVEL)))
	{
		if (dd == d&&mm == m&&yy == y&&bno == busno)
			count++;
	}
	if (count<60)
		avail = 1;
	file.close();
	return avail;
}

int TRAVEL::RESERVED(int bno, int d, int m, int y, int sno)
{
	fstream file;
	file.open("BUS.DAT", ios::in);
	int reserved = 0;
	while (file.read((char*)this, sizeof(TRAVEL)))
	{
		if (dd == d&&mm == m&&yy == y&&bno == busno&&sno == seatno)
		{
			reserved = 1;
			break;
		}
	}
	file.close();
	return reserved;
}


/* FUNCTION TO RESERVE TICKET */

void TRAVEL::RESERVATION(void)
{

	system("cls");
	int bno, sno, pfair = 0, page;
	char ch, pname[26], psex;
	cout << "\n Bus 1:islamabad to lahore.       <fare Rs.100>" << endl;
	cout << "\n Bus 2:islamabad to peshawar.         <fare Rs.220>" << endl;
	cout << "\n Bus 3:isamabad to murree.        <fare Rs.110>" << endl;
	do
	{
		cout << "\n\nenter the bus no.(1/2/3)";
		cin >> bno;
	} while (bno<1 || bno>3);
	int d, m, y;
	cout << "\n\n Enter the date for reservation :";
	cin >> d;
	cout << "\n\n Enter month:";
	cin >> m;
	cout << "\n\n Enter year:";
	cin >> y;
	if (!AVAIL(bno, d, m, y))
	{
		cout << "\n\n\nsorry!\7seat not available";
		_getch();
		return;
	}
	cout << "\nEnter the seat no.:";
	cin >> sno;
	if (sno>60 || sno<1 || RESERVED(bno, d, m, y, sno))
	{
		cout << "\n\n\nsorry!\7seat already reserved";
		_getch();
		return;
	}
	cout << "\n Enter name of passenger:";
	cin >> pname;
	do
	{
		cout << "Enter sex of passenger(M/F):";
		cin >> psex;
	} while (toupper(psex) != 'M'&&toupper(psex) != 'F');
	cout << "enter age:";
	cin >> page;
	if (page <= 5)
	{
		cout << "\n No ticket is required upto the age of 5";
		_getch();
		return;
	}
	system("cls");

	cout << "**********************************************************************" << endl;

	cout << "BUS RESERVATION SYSTEM" << endl;

	cout << "BUS NO." << bno << "\t\t\tDATE:" << d << "/" << m << "/" << y << endl;

	cout << "SEAT NO.:" << sno << endl;

	cout << "FROM:" << "\tTo:" << place[bno - 1] << endl;

	cout << "Passenger Name:" << pname << endl;

	cout << "Passenger Age:  " << page << "\t\tsex:" << psex << endl;

	cout << "Total Fair   :" << price[bno - 1] << endl;

	cout << "**********************************************************************" << endl;
	cout << "\n\n\n";
	do
	{
		cout << "Do you want to save ticket(y/n)" << endl;
		cin >> ch;
	} while (toupper(ch) != 'N'&& toupper(ch) != 'Y');
	if (toupper(ch) == 'N')
		return;
	fstream file;
	file.open("BUS.DAT", ios::app);
	busno = bno;
	seatno = sno;
	strcpy_s(name, pname);
	sex = psex;
	age = page;
	fair = pfair;
	dd = d;
	mm = m;
	yy = y;
	file.write((char*)this, sizeof(TRAVEL));
	file.close();
}


/*FUNCTION TO DELETE RECORD OF THE PASSENGER */

void TRAVEL::DELETION(void)
{
	system("cls");
	int bno = 0, found = 0, sno, d, m, y;
	char ch;
	cout << "\n Bus 1:islamabad to lahore.       <fare Rs.100>" << endl;
	cout << "\n Bus 2:islamabad to peshawar.         <fare Rs.220>" << endl;
	cout << "\n Bus 3:isamabad to murree.        <fare Rs.110>" << endl;
	do
	{
		cout << "\n\n enter the busno.(1/2/3)";
		cin >> bno;
	} while (bno<1 || bno>3);
	cout << "\n\n enter the date of the reserved ticket:";
	cin >> d;
	cout << "\n\n enter the month:";
	cin >> m;
	cout << "\n\n enter the year:";
	cin >> y;
	cout << "\nenter the seat no.:";
	cin >> sno;
	if (sno>60 || sno<1 || !RESERVED(bno, d, m, y, sno))
	{
		cout << "\n\n\nsorry!\7seat not reserved";
		_getch();
		return;
	}
	fstream file, temp;
	file.open("BUS.DAT", ios::in);
	temp.open("TEMP.DAT", ios::out);
	while (file.read((char*)this, sizeof(TRAVEL)))
	{
		if (dd == d&&mm == m&&yy == y&&bno == busno&&sno == seatno)
		{
			found = 1;
			system("cls");

			cout << "************************************************************************" << endl;

			cout << "\n\n\nBUS RESERVATION SYSTEM" << endl;

			cout << "BUS NO." << bno << "\t\t\tDATE:" << d << "/" << m << "/" << y << endl;

			cout << "SEAT NO.:" << sno << endl;

			cout << "FROM:" << "\tTo:" << place[bno - 1] << endl;

			cout << "Passenger Name:" << name << endl;

			cout << "Passenger Age:  " << age << "\t\tsex:" << sex << endl;


			cout << "*********************************************************************" << endl;
			do
			{

				cout << "Do you want to delete(y/n)";
				cin >> ch;
			} while (toupper(ch) != 'N'&& toupper(ch) != 'Y');
			if (toupper(ch) == 'N')
				temp.write((char *)this, sizeof(TRAVEL));
		}
		else
			temp.write((char *)this, sizeof(TRAVEL));
	}
	file.close();
	temp.close();
	if (!found)
	{
		cout << "\n\n\7Passenger record not found" << endl;
		_getch();
		return;
	}
	if (toupper(ch) == 'N')
		return;
	file.open("BUS.DAT", ios::out);
	temp.open("TEMP.DAT", ios::in);
	while (temp.write((char*)this, sizeof(TRAVEL)));
	file.write((char*)this, sizeof(TRAVEL));
	file.close();
	temp.close();
}


void TRAVEL::INFORMATION(void)
{
	system("cls");

	cout << "\n\nInformation about bus routes" << endl;

	cout << "\n\n\n\t\t\t\t\t\t\tBuses Routes\n\n\n\n:" << endl;

	cout << "\n Bus 1:islamabad to lahore.       <fare Rs.100>" << endl;
	cout << "\n Bus 2:islamabad to peshawar.         <fare Rs.220>" << endl;
	cout << "\n Bus 3:isamabad to murree.        <fare Rs.110>" << endl;

	cout << "press any key to continue.......";
	_getch();
}
/*   MAIN FUNCTION WHICH DISPLAY MAIN MENU & CALL ALL OTHER FUNCTIONS */

void MAINMENU(void)
{
	TRAVEL travel;
	char ch;
	while (1)
	{


		system("COLOR 4F");



		system("cls");

		cout << "\t\t\t\t\n\n******************************************************" << endl;

		cout << "\t\t\n\n *  Nabeel Ahmed  *\t\t01-132162-044" << endl;
		cout << "\t\t\n\n*  M.Saqlain Sajid  *\t\t01-132162-053" << endl;

		cout << "\t\t\t\n\n\n******************************************************" << endl;



		cout << "BUS RESERVATION SYSTEM" << endl;

		cout << "1::INTRODUCTION" << endl;

		cout << "2::RESERVATION" << endl;

		cout << "3::DELETE RECORD" << endl;

		cout << "4::PASSENGER LIST" << endl;

		cout << "5::PASSENGER INFORMATION" << endl;

		cout << "6::QUIT" << endl;

		cout << "Enter your choice::" << endl;
		ch = _getch();
		if (ch == 27 || ch == '6')
		{
			system("cls");

		}
		else
		if (ch == '1')
			travel.INFORMATION();
		else
		if (ch == '2')
			travel.RESERVATION();
		else
		if (ch == '3')
			travel.DELETION();
		else
		if (ch == '4')
			travel.LIST_OF_PASS();
		else
		if (ch == '5')
			travel.PASS_INFO();
	}
}

//MAIN function to call all the functions
void main()
{
	MAINMENU();
	_getch();
}