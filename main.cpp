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
	inisializ = MessageBox(NULL, "Использовать функцию генерации зерна?\nДля изменения решения нужно перезегрузить программу.","Инициализацимя программы", 4); //сообщение
	if(inisializ == 6)
	{
		srand(time(NULL));
		cout << "Зерно активированно!" << endl;
	} else cout << "Вы выбрали вариант без активации зерна!" << endl;
	cout << "\nМеню: \n 1) Начать выполнение с водом значений в ручную.\n 2) Начать выполнение с вводом значений при помощи функции псевдослучайных чисел.";
	while(intmenu == 0)
	{
		cmenu = getch();
		switch (cmenu)
		{
			case '1': intmenu = 1;
				cout << endl << "Выбран ручной режим работы" << endl;
				break;
			case '2': intmenu = 2; 
				cout << endl << "Выбран автоматический режим работы." << endl; 
				break;
			default : cout << endl << "Вы ввели не допустимые значения, попробуйте еще раз.";
		}
	}
	while(true)
	{	
		int rows = 0, cols = 0, ynum = 0;//rows - ширина cols - высота
		cout << endl << "Введите ширину матрицы. ";
		cin >> rows;
		cout << "Введите высоту матрицы. "; 
		cin >> cols;
		char inmass;
		int **massl;
		/*Инициализация основного массива*/
		massl = new int *[cols];
		for (int counter = 0; counter < cols; counter++)
		{
			massl[counter] = new int[rows];
			for (int num = 0; num < rows; num++)
			{
				massl[counter][num] = 0;
			}
		}
		/*Задание значений с клавиатуры*/
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
							MessageBox(NULL, "Вводить можно значения от 0 до 9.", "Ошибка ввода!", 0);
						}
					}
				}
				cout << endl;
			}
		}
		if(intmenu == 2)
		{
			int rMin = 0, rMax = 0;
			cout << endl << "Введите минимальное значение  принимаемое числом в матрице (от 0 до 9) ";
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
					MessageBox(NULL, "Минимальное число может принимать значения от 0 до 9!", "Ошибка ввода!", 0);
				}
			}
			cout << "Введите максимальное значение  принимаемое числом в матрице (от 0 до 9) ";
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
					MessageBox(NULL, "Максимальное число может принимать значения от 0 до 9!", "Ошибка ввода!", 0);
				}
			}
			if(rMin > rMax)
			{
				MessageBox(NULL, "Максимальное число не может быть меньше минимального!\nОбмен значений.", "Ошибка ввода!", 0);
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
		/*Создение временного массива типов */
		/* 1 0 0 0 1     и      1 0 0 0 0 1
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
Проверка является ли матрица Y образной
=====================================================*/
		while (1)
		{
			if(cols > 2 || rows > 3)
			{
				if (rows % 2 != 0)//для не четных
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
					else// для четных
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
Рассчет суммы диагоналей матрицы.
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
				cout << endl << "Сумма чисел по главной диагонали равна " << summ1 << endl << "Сумма по побочно диагонали равна " << summ2 << endl;
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
				cout << endl << "Сумма чисел по главной диагонали равна " << summ1 << endl <<"Сумма по побочно диагонали равна " << summ2 << endl;
			}
		}
		else
		{
			cout << "Матри является Y образной." << endl;
		}
		system("pause");
		system("cls");
		//Очистка выделенной памяти.
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
		
		cout << "\nМеню: \n 1) Начать выполнение с водом значений в ручную.(или любую клавишу)\n 2) Начать выполнение с вводом значений при помощи функции псевдослучайных чисел.";
		cout << endl << " 3) Выход. (любую клавишу кроме 1 и 2)";
		cmenu = getch();
		switch (cmenu)
		{
			case '1': intmenu = 1;
				cout << endl << "Выбран ручной режим работы" << endl;
				break;
			case '2': intmenu = 2;
				cout << endl << "Выбран автоматический режим работы." << endl; 
				break;
			default : return 0;
		}
	}
}
