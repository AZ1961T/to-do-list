#include <iostream>
#include <ctime> 
using namespace std;


struct _gogo
{
	int pl;
	int gy=2;
	int gx=2;
	int game;
	int caunt = 0;
	bool finish = false;
	bool ato = false;
};

void pole(_gogo* str1,int**&board1,int&line1,int&up1)
{
	//int line, up;
	int a;
	cout << "select the field size" << endl;
	cout << "1 - 3x3" << endl;
	cout << "2 - 4x4" << endl;
	cout << "0 - exit" << endl;
	cin >> str1->pl;
	 a =str1->pl;
	 //line1 = line;
	// up1 = up;
	if (a == 1)
	{
		line1 = 13;
		up1 = 13;
	}
	else if (a == 2)
	{
		line1 = 17;
		up1 = 17;
	}
	else if (a == 0)
	{
		exit;
	}
	else
	{
		cout << "incorrect input" << endl;
	}
	int** board = new int* [line1];

	for (int i = 0; i < line1; i++)
	{
		board[i] =new int[up1];
	}
	int*& ms1 = *board;
	for (int i = 0; i < line1; i++)
	{
		for (int j = 0; j < up1; j++)
		{
			if (i == 0 || i == 4 || i == 8 || i == 12 || i == 16 || j == 0 || j == 4 || j == 8 || j == 12 || j == 16)
			{
			
				cout << "* ";
			}

			else
			{
				cout << "  ";
			}

		}
		cout << endl;
	}
	 board1 = board;
}

void print(int**& board,int *line1,int*up1,_gogo* str1)
{
	
	

		for (int i = 0; i < *line1; i++)
		{
			for (int j = 0; j < *up1; j++)
			{

				if (i == 0 || i == 4 || i == 8 || i == 12 || i == 16 || j == 0 || j == 4 || j == 8 || j == 12 || j == 16)
				{

					cout << "* ";
				}

			
				else if (i == 2&&(j==2||j==6||j==10||j==14)|| i == 6 && (j == 2 || j == 6 || j == 10 || j == 14)|| i == 10 && (j == 2 || j == 6 || j == 10 || j == 14)||i == 14 && (j == 2 || j == 6 || j == 10 || j == 14))
				{
					
					if (board[i][j] != 0)
					{
						cout << board[i][j];
					}
					if (board[i][j] == 0)
					{
						cout << " ";
					}
						if (board[i][j] < 10)
						{
							cout << " ";
						}
					
					
				}
				else
				{
					if (i == (str1)->gx - 1 && j == str1->gy || i == str1->gx + 1 && j == str1->gy)
					{
						cout << "-";
						cout << " ";
					}		
					else {
						cout << "  ";
					}
				}

			}
			cout << endl;
		}
	
	
}

void rnd15(int**& board, int* line1, int* up1)
{
	srand(time(NULL));

	int ms[3][5]{ 2,15,3,4,9, 11,1,12,7,8, 14,10,13,5,6 };

	int ran = rand() % 3 + 1;
	int ran1 = rand() % 5 + 1;

	for (int i = 0; i < 3; i++)
	{
		int size;
		for (int j = 0; j < ran1; j++)
		{
			size = ms[i][4];
			int q = 0;
			for (int g = 0; g < 4; g++)
			{

				ms[i][4 - q] = ms[i][4 - q - 1];
				q++;
			}
			ms[i][0] = size;
		}

	}


	for (int i = 0; i < ran; i++)
	{
		int size;
		for (int j = 0; j < 5; j++)
		{
			size = ms[2][j];
			int q = 0;
			for (int g = 0; g < 2; g++)
			{

				ms[2 - q][j] = ms[2 - q - 1][j];
				q++;
			}
			ms[0][j] = size;
		}

	}

	int mms[16];
	mms[15] = 0;
	for (int i = 0, t = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			mms[t] = ms[i][j];
			t++;
		}
	}

	for (int i = 0, t = 0; i < *line1; i++)
	{
		for (int j = 0; j < *up1; j++)
		{
			if (i == 2 && (j == 2 || j == 6 || j == 10 || j == 14) || i == 6 && (j == 2 || j == 6 || j == 10 || j == 14) || i == 10 && (j == 2 || j == 6 || j == 10 || j == 14) || i == 14 && (j == 2 || j == 6 || j == 10 || j == 14))
			{
				board[i][j] = mms[t];
				t++;
			}
		}
	}

};

void rnd8(int**& board, int* line1, int* up1)
{
	srand(time(NULL));

	int ms[2][4]{ 1,8,2,7, 3,6,4,5 };

	int ran = rand() % 2 + 1;
	int ran1 = rand() % 4 + 1;

	for (int i = 0; i < 2; i++)
	{
		int size;
		for (int j = 0; j < ran1; j++)
		{
			size = ms[i][3];
			int q = 0;
			for (int g = 0; g < 3; g++)
			{

				ms[i][3 - q] = ms[i][3 - q - 1];
				q++;
			}
			ms[i][0] = size;
		}

	}


	for (int i = 0; i < ran; i++)
	{
		int size;
		for (int j = 0; j < 4; j++)
		{
			size = ms[1][j];
			int q = 0;
			for (int g = 0; g < 1; g++)
			{

				ms[1 - q][j] = ms[1 - q - 1][j];
				q++;
			}
			ms[0][j] = size;
		}

	}

	int mms[9];
	mms[8] = 0;

	for (int i = 0, t = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			mms[t] = ms[i][j];
			t++;
		}
	}

	for (int i = 0, t = 0; i < *line1; i++)
	{
		for (int j = 0; j < *up1; j++)
		{
			if (i == 2 && (j == 2 || j == 6 || j == 10 || j == 14) || i == 6 && (j == 2 || j == 6 || j == 10 || j == 14) || i == 10 && (j == 2 || j == 6 || j == 10 || j == 14) || i == 14 && (j == 2 || j == 6 || j == 10 || j == 14))
			{
				board[i][j] = mms[t];
				t++;
			}
		}
	}

};

void hand(int**& board, int* line1, int* up1,_gogo*str1)
{
	int arr;
	int counter;
	if ((str1)->pl == 2)
	{
		cout << "Enter numbers from 0 - 15: " << endl;
	}

	else if ((str1)->pl == 1)
	{
		cout << "Enter numbers from 0 - 8: " << endl;
	}
	
	for (int i = 0; i < *line1; i++)
	{
		for (int j = 0; j < *up1; j++)
		{
			
			if (i == 2 && (j == 2 || j == 6 || j == 10 || j == 14) || i == 6 && (j == 2 || j == 6 || j == 10 || j == 14) || i == 10 && (j == 2 || j == 6 || j == 10 || j == 14) || i == 14 && (j == 2 || j == 6 || j == 10 || j == 14))
			{
				cin >> arr;
				counter = 0;
				for (int n = 0; n < *line1; n++)
				{
					for (int r = 0; r < *up1; r++)
					{
						if (arr == board[n][r])
						{
							counter++;
                        }
					}
				}
				if (counter == 0)
				{
					board[i][j] = arr;
				}
				else
				{
					cout << "Duplicate value" << endl;
					j--;
				}

			}

		}
	}



}

void drive(int**& board, int* line1, int* up1, _gogo* str1)
{
	
	
	
	str1->gy;
	str1->gx;
	cout << "4 - left" << endl;
	cout << "6 - rigth" << endl;
	cout << "8 - up" << endl;
	cout << "2 - down" << endl;
	cout << "5 - move" << endl;
	cout << "7 - auto assembly" << endl;
	cout << "0 - exit" << endl;
	cin >> str1->game;

	switch (str1->game)
	{
	case 4:
		if (str1->gy > 2)
		{
			str1->gy = str1->gy - 4;
		}
		break;
	case 6:
		if (str1->pl == 1)
		{
			if (str1->gy < 10)
			{
				str1->gy = str1->gy + 4;
			}
		}
		else if (str1->pl == 2)
		{
			if (str1->gy < 14)
			{
				str1->gy = str1->gy + 4;
			}
		}
		break;
	case 8:
		if (str1->gx > 2)
		{
			str1->gx = str1->gx - 4;
		}
		break;
	case 2:
		if (str1->pl == 1)
		{
			if (str1->gx < 10)
			{
				str1->gx = str1->gx + 4;
			}
		}
		else if (str1->pl == 2)
		{
			if (str1->gx < 14)
			{
				str1->gx = str1->gx + 4;
			}
		}

		break;
	case 5:
		for (int i = 0; i < *line1; i++)
		{
			for (int j = 0; j < *up1; j++)
			{
				if (board[i][j] == 0 && (str1->gx - i <= 4 && str1->gx - i >= -4) && (str1->gy - j <= 4 && str1->gy - j >= -4))
				{
					board[i][j] = board[str1->gx][str1->gy];
					board[str1->gx][str1->gy] = 0;
					str1->caunt++;
					//exit;
				}
			}
		}
		break;
	case 7:
		str1->ato = true;
		break;
	case 0:
		exit;
		break;
	default:
		break;
	}

	int fin1 = 1;
	if (str1->pl == 1)
	{
		if (board[2][2] == 1 && board[2][6] == 2 && board[2][10] == 3 && board[6][2] == 4 && board[6][6] == 5 && board[6][10] == 6 && board[10][2] == 7 && board[10][6] == 8)
		{
			str1->finish = true;
			str1->game = 0;
		}
	}
	
	else if(str1->pl == 2)
	{
		if (board[2][2] == 1 && board[2][6] == 2 && board[2][10] == 3 && board[2][14] == 4 && board[6][2] == 5 && board[6][6] == 6 && board[6][10] == 7 && board[6][14] == 8 && board[10][2] == 9 && board[10][6] == 10 && board[10][10] == 11 && board[10][14] == 12 && board[14][2] == 13 && board[14][6] == 14 && board[14][10] == 15)
		{
			str1->finish = true;
			str1->game = 0;
		}
	}
}

void autofin(int**& board, int* line1, int* up1)
{
	int io,iz,id;
	int jo,jz,jd;
	int st=1;


	for (int i = 0; i < *line1; i++)
	{
		for (int j = 0; j < *up1; j++)
		{
			if (board[i][j] == 0)
			{
				io = i;
				jo = j;
			}
			if (board[i][j] == st)
			{
				iz = i;
				jz = j;
			}

		}
	}
	id = io - iz;
	jd = jo - jz;

	
	
	
			if (id < -4 && jd<-4||jd>4)
			{
				board[io][jo] == board[io + 4][jo];
				board[io + 4][jo] == 0;
			}
			 if (id > 4 && jd<-4||jd>4)
			{
				board[io][jo] == board[io - 4][jo];
				board[io + 4][jo] == 0;
			}
			 if (id == 0 && jd <-4)
			{
				board[io][jo] == board[io][jo+4];
				board[io][jo+4] == 0;
			}
			 if (id == 0 && jd > 4)
			{
				board[io][jo] == board[io][jo - 4];
				board[io][jo - 4] == 0;
	         }
			 if (id > 4 && jd ==0)
			 {
				 board[io][jo] == board[io-4][jo];
				 board[io-4][jo] == 0;
			 }
			 if (id < -4 && jd == 0)
			 {
				 board[io][jo] == board[io + 4][jo];
				 board[io + 4][jo] == 0;
			 }



}


int main()
{
	clock_t time;
	
	_gogo str;
	_gogo* str1 = &str;
	int line;
	int& line1 = line;
	int up;
	int& up1 = up;
	int** board1;
	
	pole(str1,*&board1,line1,up1);
	int choice;
	cout << "1 - auto filling" << endl;
	cout << "2 - manual input" << endl;
	cout << "0 - exit" << endl;
	cin >> choice;
	switch (choice)
	{
		case 1:
			if (str1->pl == 1)
			{
				rnd8(*&board1, &line1, &up1);
			}
			else if(str1->pl == 2)
		    {
				rnd15(*&board1, &line1, &up1);
            }
			break;
		case 2:
			hand(*&board1, &line1, &up1, str1);
			break;
		case 0:
			return 0;
			break;
	default:
		break;
	}
	

	
	print(*&board1, &line1, &up1,str1);
	time = clock();
	do
	{
		
		drive(board1, &line1, &up1, str1);
		if (str1->ato = true)
		{
			autofin(*&board1, &line1, &up1);
		}
		print(*&board1, &line1, &up1, str1);
		
	
	} while (str1->game != 0);
time = clock()- time;
if (str1->finish == true)
{
	cout << "Finish!!!" << endl;
}
cout << "number of moves: " << str1->caunt-1 << endl;
cout << "time: " << (int)time/ CLOCKS_PER_SEC << endl;
}

