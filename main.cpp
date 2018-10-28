#include <iostream>
#include <windows.h>
#include <ctime>
#include <conio.h>


using namespace std;


int main(void)
{
	setlocale(LC_ALL, "Russian");
	int inisializ = 0, intmenu = 0;
	char cmenu = '0';
	inisializ = MessageBox(NULL, "������������ ������� ��������� �����?\n��� ��������� ������� ����� ������������� ���������.","�������������� ���������", 4); //���������
	if(inisializ == 6)
	{
		srand(time(NULL));
		cout << "����� �������������!" << endl;
	} else cout << "�� ������� ������� ��� ��������� �����!" << endl;
	cout << "\n����: \n 1) ������ ���������� � ����� �������� � ������.\n 2) ������ ���������� � ������ �������� ��� ������ ������� ��������������� �����.";
	while(intmenu == 0)
	{
		cmenu = getch();
		switch (cmenu)
		{
			case '1': intmenu = 1;
				cout << endl << "������ ������ ����� ������" << endl;
				break;
			case '2': intmenu = 2; 
				cout << endl << "������ �������������� ����� ������." << endl; 
				break;
			default : cout << endl << "�� ����� �� ���������� ��������, ���������� ��� ���.";
		}
	}
	while(true)
	{	
		int rows = 0, cols = 0, ynum = 0;//rows - ������ cols - ������
		cout << endl << "������� ������ �������. ";
		cin >> rows;
		cout << "������� ������ �������. "; 
		cin >> cols;
		char inmass;
		int **massl;
		/*������������� ��������� �������*/
		massl = new int *[cols];
		for (int counter = 0; counter < cols; counter++)
		{
			massl[counter] = new int[rows];
			for (int num = 0; num < rows; num++)
			{
				massl[counter][num] = 0;
			}
		}
		/*������� �������� � ����������*/
		if(intmenu == 1)
		{
			for(int counter = 0; counter < cols; counter++)
			{
				cout << "| ";
				for(int num = 0; num < rows; num++)
				{
					while(1)
					{
						inmass = getch();
						if(inmass >= '0' && inmass <= '9')
						{
							massl[counter][num] = atoi(&inmass);
							cout << massl[counter][num] << " | ";
							break;
						}
						else
						{
							MessageBox(NULL, "������� ����� �������� �� 0 �� 9.", "������ �����!", 0);
						}
					}
				}
				cout << endl;
			}
		}
		if(intmenu == 2)
		{
			int rMin = 0, rMax = 0;
			cout << endl << "������� ����������� ��������  ����������� ������ � ������� (�� 0 �� 9) ";
			while(1)
			{
				cmenu = getch();
				if(cmenu >= '0' && cmenu <= '9')
				{
					rMin = atoi(&cmenu);
					cout << rMin << endl;
					break;
				}
				else
				{
					MessageBox(NULL, "����������� ����� ����� ��������� �������� �� 0 �� 9!", "������ �����!", 0);
				}
			}
			cout << "������� ������������ ��������  ����������� ������ � ������� (�� 0 �� 9) ";
			while(1)
			{
				cmenu = getch();
				if(cmenu >= '0' && cmenu <= '9')
				{
					rMax = atoi(&cmenu);
					cout << rMax << endl;
					break;
				}
				else
				{
					MessageBox(NULL, "������������ ����� ����� ��������� �������� �� 0 �� 9!", "������ �����!", 0);
				}
			}
			if(rMin > rMax)
			{
				MessageBox(NULL, "������������ ����� �� ����� ���� ������ ������������!\n����� ��������.", "������ �����!", 0);
				int tmp;
				tmp = rMin;
				rMin = rMax;
				rMax = tmp;
			}
			for(int counter = 0; counter < cols; counter++)
			{
				for(int num = 0; num < rows; num++)
				{
					massl[counter][num] =  rMin + rand() % ((rMax + 1) - rMin); 
				}
			}
			for(int counter = 0; counter < cols; counter++)
			{
				cout << " | ";
				for(int num = 0; num < rows; num++)
				{
					cout << massl[counter][num] << " | ";
				}
				cout << endl;
			}
		}
		int tmpRows = rows / 2, tmpCols = cols / 2;
		/*�������� ���������� ������� ����� */
		/* 1 0 0 0 1     �      1 0 0 0 0 1
		   0 1 0 1 0			0 1 0 0 1 0
		   0 0 1 0 0			0 0 1 1 0 0
		   0 0 1 0 0			0 0 1 1 0 0
		*/
		int **massNor;
		massNor = new int *[cols];
		for (int counter = 0; counter < cols; counter++)
		{
			massNor[counter] = new int[rows];
			for (int num = 0; num < rows; num++)
			{
				massNor[counter][num] = 0;
			}
		}
		int ctrRows = 0, ctrRowsEnd = (rows - 1), ctrCols = 0, ctrColsEnd = (cols - 1);
/*=====================================================
�������� �������� �� ������� Y ��������
=====================================================*/
		while (1)
		{
			if(cols > 2 || rows > 3)
			{
				if (rows % 2 != 0)//��� �� ������
				{
					if ((ctrCols < cols) && (ctrRows < rows / 2))
					{
						massNor[ctrCols][ctrRows] = 1;
						massNor[ctrCols][ctrRowsEnd] = 1;
						ctrCols++;
						ctrRows++;
						ctrColsEnd--;
						ctrRowsEnd--;
					}
					else if (ctrCols < cols)
					{
						massNor[ctrCols][rows / 2] = 1;
						ctrCols++;
						if (ynum < 2)
						{
							ynum++;
						}
					}
					else break;
					}
					else// ��� ������
					{
						if ((ctrCols < cols) && (ctrRows < rows / 2))
					{
						massNor[ctrCols][ctrRows] = 1;
						massNor[ctrCols][ctrRowsEnd] = 1;
						ctrCols++;
						ctrRows++;
						ctrColsEnd--;
						ctrRowsEnd--;
					}
					else if (ctrCols < cols)
					{
						massNor[ctrCols][rows / 2] = 1;
						massNor[ctrCols][(rows / 2) - 1] = 1;
						ctrCols++;
						if (ynum < 2)
						{
							ynum++;
						}
					}
					else break;
				}
			}
				else
				{
					ynum = -1;
					break;
				}
	}
		
		for(int counter = 0; counter < cols; counter++)
		{
			for(int num = 0; num < rows; num++)
			{
				if((massNor[counter][num] == 0))
				{
					if(massl[counter][num] != 0)
					{
						if(ynum > 0) ynum++;
					}
				}
				else
				{
					if(massl[counter][num] == 0)
					{
						if(ynum > 0) ynum++;
					}
				}
			}
		}
/*====================================
������� ����� ���������� �������.
===================================*/
		int summ1 = 0, summ2 = 0;
		if(ynum != 2)
		{
			int num = 0;
			if(cols <= rows)
			{
				for(int counter = 0; counter < cols; counter++)
				{
					summ1 = summ1 + massl[counter][counter];
				}
				for(int counter = (cols - 1); counter >= 0; counter--)
				{
					summ2 = summ2 + massl[counter][num];
					num++;
				}
				cout << endl << "����� ����� �� ������� ��������� ����� " << summ1 << endl << "����� �� ������� ��������� ����� " << summ2 << endl;
			}
			else
			{
				for(int counter = 0; counter < rows; counter++)
				{
					summ1 = summ1 + massl[counter][counter];
				}
				for(int counter = (rows - 1); counter >=0; counter--)
				{
					summ2 = summ2 + massl[counter][num];
					num++;
				}
				cout << endl << "����� ����� �� ������� ��������� ����� " << summ1 << endl <<"����� �� ������� ��������� ����� " << summ2 << endl;
			}
		}
		else
		{
			cout << "����� �������� Y ��������." << endl;
		}
		system("pause");
		system("cls");
		//������� ���������� ������.
		for (int counter = 0; counter < cols; counter++)
		{
			delete[]massNor[counter];
			massNor[counter] = NULL;
		}
		delete[]massNor;
		massNor = NULL;
		for (int counter = 0; counter < cols; counter++)
		{
			delete[]massl[counter];
			massl[counter] = NULL;
		}
		delete[]massl;
		massl = NULL;
		
		cout << "\n����: \n 1) ������ ���������� � ����� �������� � ������.(��� ����� �������)\n 2) ������ ���������� � ������ �������� ��� ������ ������� ��������������� �����.";
		cout << endl << " 3) �����. (����� ������� ����� 1 � 2)";
		cmenu = getch();
		switch (cmenu)
		{
			case '1': intmenu = 1;
				cout << endl << "������ ������ ����� ������" << endl;
				break;
			case '2': intmenu = 2;
				cout << endl << "������ �������������� ����� ������." << endl; 
				break;
			default : return 0;
		}
	}
}
