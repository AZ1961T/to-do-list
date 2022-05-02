#include <iostream>
#include "doc.h"
#include <string.h>
#include <stdio.h>
using namespace std;


struct to_do_list
{
	int number=0;
	string title;
	int pri;
	string desc;
	char date[18];
};

//при выводе списка на неделю выводит баг. Не пойму в чем ошибка.

void _list(to_do_list* cases, int col)
{
	
	for (int i = 0; i < col; i++)
	{
		
		((cases + i)->number)=i+1;
		cout << "enter the title " << (cases + i)->number << endl;
		cin >> (cases + i)->title;
		cout << "specify the priority" << endl;
		cout << "1 - low priority" << endl;
		cout << "2 - medium priority" << endl;
		cout << "3 - high priority" << endl;
		cin >> (cases + i)->pri;
		cout << "describe the task" << (cases + i)->number << endl;
		cin >> (cases + i)->desc;
		cout << "enter the date and time in the format dd.mm.yyyy.hh.mm" << endl;
		cin >> (cases + i)->date;
		//puts((cases + i)->date);
	}
}

void _redact(to_do_list* cases, int col)
{
	int b;
	int a;
	do
	{
		cout << "fix the note number - " << endl;
		cout << "exit -  0" << endl;
		cin >> b;
		if (b == 0)
		{
			exit;
		}
		cout << "1 - fix title" << endl;
		cout << "2 - fix priority" << endl;
		cout << "3 - fix task" << endl;
		cout << "4 - fix date" << endl;
		cout << "0 - exit" << endl;
		cin >> a;


		switch (a)
		{
		case 1:
			
				cout << "enter the title " << b << endl;
				cin >> (cases + b-1)->title;
			
			break;
		case 2:
			cout << "specify the priority" << endl;
			cout << "1 - low priority" << endl;
			cout << "2 - medium priority" << endl;
			cout << "3 - high priority" << endl;
			cin >> (cases + b-1)->pri;
			break;
		case 3:

			cout << "describe the task" << b << endl;
			cin >> (cases + b-1)->desc;
			break;
		case 4:

			cout << "enter the date and time in the format dd mm yyyy hh mm" << endl;
			cin >> (cases + b-1)->date;
			break;
		case 0:
			exit;
			break;
		default:
			break;
		}


	} while (a != 0);
	



}

void _dell(to_do_list *&cases, int &col)
{
	col--;
	to_do_list* cases1 = new to_do_list[col];
	int b;
	cout << "fix the note number - " << endl;
	cout << "exit -  0" << endl;
	cout << endl;
	cin >> b;
	if (b == 0)
	{
		exit;
	}
	for (int i = 0; i < col; i++)
	{
		if (i >= b-1)
		{
			
				(cases + i)->title = (cases + i+1)->title;
				
				 (cases + i)->pri= (cases + i+1)->pri;
				
				 (cases + i)->desc= (cases + i+1)->desc;
				
				 strcpy_s((cases + i)->date, (cases + i+1)->date);
			
		}	
	}
	for (int i = 0; i < col; i++)
	{
		(cases1 + i)->title=(cases + i)->title;

		(cases1 + i)->pri=(cases + i)->pri;

		(cases1 + i)->desc=(cases + i)->desc;

		strcpy_s((cases1 + i)->date, (cases + i)->date);
	}
	delete[]cases;
	cases =cases1;

}

void _add(to_do_list* &cases, int& col)
{
	col++;
	to_do_list* cases1 = new to_do_list[col];
	int b=0;
	cout << "add the note - 1"<<endl;
	cout << "exit -  0" << endl;
	cin >> b;
	if (b == 0)
	{
		exit;
	}
	for (int i = 0; i < col; i++)
	{
		if (i < col - 1)
		{
			((cases1 + i)->number) = i + 1;
			(cases1 + i)->title = (cases + i)->title;

			(cases1 + i)->pri = (cases + i)->pri;

			(cases1 + i)->desc = (cases + i)->desc;

			strcpy_s((cases1 + i)->date, (cases + i)->date);
		}
		else {
			((cases1 + i)->number) = i + 1;
			cout << "enter the title " << (cases1 + i)->number << endl;
			cin >> (cases1 + i)->title;
			cout << "specify the priority" << endl;
			cout << "1 - low priority" << endl;
			cout << "2 - medium priority" << endl;
			cout << "3 - high priority" << endl;
			cin >> (cases1 + i)->pri;
			cout << "describe the task" << (cases1 + i)->number << endl;
			cin >> (cases1 + i)->desc;
			cout << "enter the date and time in the format dd.mm.yyyy.hh.mm" << endl;
			cin >> (cases1 + i)->date;
		}
			
	}
	delete[]cases;
	cases = cases1;
}

void _sort(to_do_list* &cases, int& col)
{
	int srt;
	cout << "1 - sort by date" << endl;
	cout << "2 - sort by priority" << endl;
	cin >> srt;
	int temp;
	string tp;
	char tm[18];

	int** msdate = new int* [col];
	for (int i = 0; i < col; i++)
	{
		msdate[i] = new int[18];
	}

	switch (srt)
	{
	case 1:


		for (int i = 0; i < col; i++)
		{
			for (int j = 0, r = 0; j < 18; j++)
			{
				if ((cases + i)->date[j] != '.' && (cases + i)->date[j] != ' ' && (cases + i)->date[j] != '/' && (cases + i)->date[j] != '\0')
				{
					msdate[i][r] = (cases + i)->date[j] - '0';
					r++;
				}
			}
		}
		for (int i = 0; i < col; i++)
		{
			for (int j = 0; j < 18; j++)
			{

				msdate[i][13] = ((msdate[i][1] * 10) + msdate[i][2]);
				msdate[i][14] = ((msdate[i][3] * 10) + msdate[i][4]);
				msdate[i][15] = (msdate[i][5] * 1000) + (msdate[i][6] * 100) + (msdate[i][7] * 10) + msdate[i][8];

				msdate[i][16] = ((msdate[i][9] * 10) + msdate[i][10]);
				msdate[i][17] = ((msdate[i][11] * 10) + msdate[i][12]);

			}
		}

		for (int i = 0; i < col; i++)
		{
			for (int j = 0; j < col - 1; j++)
			{
				if (msdate[j][15] > msdate[j + 1][15])
				{
					for (int g = 0; g < 18; g++)
					{
						temp = msdate[j][g];
						msdate[j][g] = msdate[j + 1][g];
						msdate[j + 1][g] = temp;
					}
					tp = (cases + j)->title;
					(cases + j)->title = (cases + j + 1)->title;
					(cases + j + 1)->title = tp;

					temp = (cases + j)->pri;
					(cases + j)->pri = (cases + j + 1)->pri;
					(cases + j + 1)->pri = temp;

					tp = (cases + j)->desc;
					(cases + j)->desc = (cases + j + 1)->desc;
					(cases + j + 1)->desc = tp;

					strcpy_s(tm, (cases + j)->date);
					strcpy_s((cases + j)->date, (cases + j + 1)->date);
					strcpy_s((cases + j + 1)->date, tm);
				}
			}
		}


		for (int i = 0; i < col; i++)
		{
			for (int j = 0; j < col - 1; j++)
			{
				if (msdate[j][15] == msdate[j + 1][15] && msdate[j][14] > msdate[j + 1][14])
				{
					for (int g = 0; g < 18; g++)
					{
						temp = msdate[j][g];
						msdate[j][g] = msdate[j + 1][g];
						msdate[j + 1][g] = temp;
					}
					tp = (cases + j)->title;
					(cases + j)->title = (cases + j + 1)->title;
					(cases + j + 1)->title = tp;

					temp = (cases + j)->pri;
					(cases + j)->pri = (cases + j + 1)->pri;
					(cases + j + 1)->pri = temp;

					tp = (cases + j)->desc;
					(cases + j)->desc = (cases + j + 1)->desc;
					(cases + j + 1)->desc = tp;

					strcpy_s(tm, (cases + j)->date);
					strcpy_s((cases + j)->date, (cases + j + 1)->date);
					strcpy_s((cases + j + 1)->date, tm);
				}
			}
		}

		for (int i = 0; i < col; i++)
		{
			for (int j = 0; j < col - 1; j++)
			{
				if (msdate[j][15] == msdate[j + 1][15] && msdate[j][14] == msdate[j + 1][14] && msdate[j][13] > msdate[j + 1][13])
				{

					for (int g = 0; g < 18; g++)
					{
						temp = msdate[j][g];
						msdate[j][g] = msdate[j + 1][g];
						msdate[j + 1][g] = temp;
					}
					tp = (cases + j)->title;
					(cases + j)->title = (cases + j + 1)->title;
					(cases + j + 1)->title = tp;

					temp = (cases + j)->pri;
					(cases + j)->pri = (cases + j + 1)->pri;
					(cases + j + 1)->pri = temp;

					tp = (cases + j)->desc;
					(cases + j)->desc = (cases + j + 1)->desc;
					(cases + j + 1)->desc = tp;

					strcpy_s(tm, (cases + j)->date);
					strcpy_s((cases + j)->date, (cases + j + 1)->date);
					strcpy_s((cases + j + 1)->date, tm);
				}
			}
		}

		for (int i = 0; i < col; i++)
		{
			for (int j = 0; j < col - 1; j++)
			{
				if (msdate[j][15] == msdate[j + 1][15] && msdate[j][14] == msdate[j + 1][14] && msdate[j][13] == msdate[j + 1][13] && msdate[j][16] > msdate[j + 1][16])
				{
					for (int g = 0; g < 18; g++)
					{
						temp = msdate[j][g];
						msdate[j][g] = msdate[j + 1][g];
						msdate[j + 1][g] = temp;
					}
					tp = (cases + j)->title;
					(cases + j)->title = (cases + j + 1)->title;
					(cases + j + 1)->title = tp;

					temp = (cases + j)->pri;
					(cases + j)->pri = (cases + j + 1)->pri;
					(cases + j + 1)->pri = temp;

					tp = (cases + j)->desc;
					(cases + j)->desc = (cases + j + 1)->desc;
					(cases + j + 1)->desc = tp;

					strcpy_s(tm, (cases + j)->date);
					strcpy_s((cases + j)->date, (cases + j + 1)->date);
					strcpy_s((cases + j + 1)->date, tm);
				}
			}
		}

		for (int i = 0; i < col; i++)
		{
			for (int j = 0; j < col - 1; j++)
			{
				if (msdate[j][15] == msdate[j + 1][15] && msdate[j][14] == msdate[j + 1][14] && msdate[j][13] == msdate[j + 1][13] && msdate[j][16] == msdate[j + 1][16] && msdate[j][17] > msdate[j + 1][17])
				{
					for (int g = 0; g < 18; g++)
					{
						temp = msdate[j][g];
						msdate[j][g] = msdate[j + 1][g];
						msdate[j + 1][g] = temp;
					}
					tp = (cases + j)->title;
					(cases + j)->title = (cases + j + 1)->title;
					(cases + j + 1)->title = tp;

					temp = (cases + j)->pri;
					(cases + j)->pri = (cases + j + 1)->pri;
					(cases + j + 1)->pri = temp;

					tp = (cases + j)->desc;
					(cases + j)->desc = (cases + j + 1)->desc;
					(cases + j + 1)->desc = tp;

					strcpy_s(tm, (cases + j)->date);
					strcpy_s((cases + j)->date, (cases + j + 1)->date);
					strcpy_s((cases + j + 1)->date, tm);
				}
			}
		}
	
		
		break;
		case 2:
			for (int i = 0; i < col; i++)
			{
				for (int j = 0; j < col - 1; j++)
				{
					if ((cases + j)->pri < (cases + j + 1)->pri)
					{
						temp = (cases + j)->pri;
						(cases + j)->pri = (cases + j + 1)->pri;
						(cases + j + 1)->pri = temp;
					}
				}
			}
		break;
	default:
		break;
	}
	for (int i = 0; i < col; i++)
	{
		delete[]msdate[i];
	}
	delete[]msdate;
	
}

void _print(to_do_list*& cases, int& col)
{
	int art;
	do
	{
		cout << "schedule:" << endl;
		cout << "1 - for the day" << endl;
		cout << "2 - for a week" << endl;
		cout << "3 - for a month" << endl;
		cout << "0 - exit" << endl;
		cin >> art;
		if (art == 0)
		{
			exit;
		}
		//int ddate;
		//cout << "Enter the date";
		//cin >> ddate;

		int** msdate = new int* [col+1];
		for (int i = 0; i < col; i++)
		{
			msdate[i] = new int[18];
		}

		for (int i = 0; i < col; i++)
		{
			for (int j = 0, r = 0; j < 18; j++)
			{
				if ((cases + i)->date[j] != '.' && (cases + i)->date[j] != ' ' && (cases + i)->date[j] != '/' && (cases + i)->date[j] != '\0') {
					msdate[i][r] = (cases + i)->date[j] - '0';
					r++;
				}
			}
		}

		for (int i = 0; i < col; i++)
		{
			for (int j = 0; j < 18; j++)
			{

				msdate[i][13] = ((msdate[i][1] * 10) + msdate[i][2]);
				msdate[i][14] = ((msdate[i][3] * 10) + msdate[i][4]);
				msdate[i][15] = (msdate[i][5] * 1000) + (msdate[i][6] * 100) + (msdate[i][7] * 10) + msdate[i][8];

				msdate[i][16] = ((msdate[i][9] * 10) + msdate[i][10]);
				msdate[i][17] = ((msdate[i][11] * 10) + msdate[i][12]);

			}
		}
		switch (art)
		{
		case 1:
			
			char fdt1[18];
			cout << "enter date dd.mm.yyyy: ";
			//	fgets(fdt, 18, stdin);
			cin >> fdt1;
			//strstr(cases)->date, fdt);
			for (int i = 0; i < col; i++)
			{
				if (strstr((cases + i)->date, fdt1) != 0)
				{
					cout << i + 1 << " " << (cases + i)->title << "   ";

					cout << (cases + i)->pri << "   ";

					cout << (cases + i)->desc << "   ";

					puts((cases + i)->date);
					cout << endl;
				}
			}
			break;
		case 2:
			int ddate2;
			cout << "Enter the beginning of the week";
			//cin >> ddate2;
			_sort(cases, col);
			ddate2 = msdate[0][13];
			for (int i = 0; i < col; i++)
			{
				if (ddate2 <= 23 && (msdate[i][13] >= ddate2 && msdate[i][13] < ddate2 + 7 && msdate[i][15] == msdate[0][15] && msdate[i][14] == msdate[0][14]))
				{

						cout << i+1<<" "<<(cases + i)->title << "   ";

						cout << (cases + i)->pri << "   ";

						cout << (cases + i)->desc << "   ";

						puts((cases + i)->date);
						cout << endl;
					
				}
				else if (ddate2 > 23&& (msdate[i][13] >= ddate2 && msdate[i][13] <= 30 && msdate[i][15] == msdate[0][15] && msdate[i][14] == msdate[0][14]))
				{
					
						cout << i + 1 << " " << (cases + i)->title << "   ";

						cout << (cases + i)->pri << "   ";

						cout << (cases + i)->desc << "   ";

						puts((cases + i)->date);
						cout << endl;
				}

				if (ddate2 > 23&&(msdate[i][13] >= 1 && msdate[i][13] <= 7-(30-ddate2) && msdate[i][15] == msdate[0][15] && msdate[i][14] == (msdate[0][14]+1)))
				{
						cout << i + 1 << " " << (cases + i)->title << "   ";

						cout << (cases + i)->pri << "   ";

						cout << (cases + i)->desc << "   ";

						puts((cases + i)->date);
						cout << endl;
				}

			}
			break;
		case 3:
			int ddate1;
			_sort(cases, col);
			ddate1 = msdate[0][14];
			for (int i = 0; i < col; i++)
			{
				if (msdate[i][14] == ddate1&&msdate[i][15]==msdate[0][15])
				{
					cout << i + 1 << " " << (cases + i)->title << "   ";

					cout << (cases + i)->pri << "   ";

					cout << (cases + i)->desc << "   ";

					puts((cases + i)->date);
					cout << endl;
				}
			}
			break;
		default:
			break;
		}
	} while (art != 0);
	

}

void _printall(to_do_list* cases, int& col)
{
	for (int i = 0; i < col; i++)
	{
		cout << (cases + i)->number << "   ";

		cout << (cases + i)->title << "   ";

		cout << (cases + i)->pri << "   ";

		cout << (cases + i)->desc << "   ";

		puts((cases + i)->date);

		cout << endl;
	}
}

void _search(to_do_list* cases, int& col)
{
	int a;
	cout << "search by:" << endl;
	cout << "1 - title" << endl;
	cout << "2 - priority" << endl;
	cout << "3 - task" << endl;
	cout << "4 - date" << endl;
	cout << "0 - exit" << endl;
	cin >> a;
	string fd;
	int fnd;
		if (a == 1)
		{
			cout << "enter title: ";
			cin >> fd;
			for (int i = 0; i < col; i++)
			{
				if (bool((cases + i)->title.find(fd)) != true)
				{
					cout << (cases + i)->title << "   ";

					cout << (cases + i)->pri << "   ";

					cout << (cases + i)->desc << "   ";

					puts((cases + i)->date);
					cout << endl;
				}
			}
		}
		else if (a == 2)
		{
			cout << "enter priority: ";
			cin >> fnd;
			for (int i = 0; i < col; i++)
			{
				if ((cases + i)->pri == fnd)
				{
					cout << (cases + i)->title << "   ";

					cout << (cases + i)->pri << "   ";

					cout << (cases + i)->desc << "   ";

					puts((cases + i)->date);
					cout << endl;
				}
			}
		}
		else if (a == 3)
		{
			cout << "enter task: ";
			cin >> fd;
			for (int i = 0; i < col; i++)
			{
				if (bool((cases + i)->desc.find(fd)) != true)
				{
					cout << (cases + i)->title << "   ";

					cout << (cases + i)->pri << "   ";

					cout << (cases + i)->desc << "   ";

					puts((cases + i)->date);
					cout << endl;
				}
			}
		}
		else if (a == 4)
		{
			string dt;
			char fdt[18];
			cout << "enter date: ";
		//	fgets(fdt, 18, stdin);
			cin >> fdt;
			//strstr(cases)->date, fdt);
			for (int i = 0; i < col; i++)
			{
				if (strstr((cases + i)->date, fdt) != 0)
				{
					cout << (cases + i)->title << "   ";

					cout << (cases + i)->pri << "   ";

					cout << (cases + i)->desc << "   ";

					puts((cases + i)->date);
					cout << endl;
				}
			}

			
		}
}

	int main()
	{
		int col;
		cout << "enter the number of notes" << endl;
		cin >> col;
		int& c = col;
		to_do_list* cases=new to_do_list[col];
		to_do_list*& cases1 = cases;
		_list(cases, col);
		int fin;
		do
		{
			cout << "1 - add the not "<<endl;
			cout << "2 - delete the not" << endl;
			cout << "3 - redact the not" << endl;
			cout << "4 - print the not" << endl;
			cout << "5 - searsh the not" << endl;
			cout << "6 - print all the not" << endl;
			cout << "7 - sort all the not" << endl;
			cout << "exit - 0 ";
			cin >> fin;
			switch (fin)
			{
			case 1:
				_add(cases1, c);
				break;
			case 2:
				_dell(cases1, c);
				break;
			case 3:
				_redact(cases, col);
				break;
			case 4:
				_print(cases1, c);
				break;
			case 5:
				_search(cases, c);
				break;
			case 6:
				_printall(cases, c);
				break;
			case 7:
				_sort(cases, c);
				break;
			case 0:
				exit;
				break;
			default:
				break;
			}


		} while (fin!=0);

		
		
	}



