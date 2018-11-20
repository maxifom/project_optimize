//#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>

struct Matr // Новый тип Матрица
{
	double** M; // Собственно сама матрица
	int row;    // количество строк
	int col;    // количество столбцов
};

// Функция определения матрицы. по ее размерам. Возвращает пустую матрицу
Matr InitMatr(int n, int m)
{
	//Определяем временную матрицу
	Matr temp;
	//выделяем память под строки
	temp.M = new double*[n];
	//запсываем размеры матрицы
	temp.row = n;
	temp.col = m;
	//выделяем память под каждый из столбцов...
	for (int i = 0; i < temp.row; i++)
	{
		temp.M[i] = new double[m];
	}
	//возвращаем созданную матрицу
	return temp;
}

// Печатает матрицу на экране
void Print(Matr A)
{
	printf("\n\nEnter Matrix To Console!!!\n");
	for (int i = 0; i < A.row; i++)
	{
		for (int j = 0; j < A.col; j++)
			printf("%10.8f    ", A.M[i][j]);
		printf("\n");
	}
}

// Заполнение матрицы нолями, все элементы матрицы нули
Matr EnterZero(Matr A)
{
	for (int i = 0; i < A.row; i++)
	{
		for (int j = 0; j < A.col; j++)
			A.M[i][j] = 0;
	}
	return A;
}

// заполняет матрицу случайными вещественными числами
Matr EnterRandom(Matr A)
{
	srand((unsigned int)time(0));
	for (int i = 0; i < A.row; i++)
	{
		for (int j = 0; j < A.col; j++)
			A.M[i][j] = (double)rand()/(double)RAND_MAX;
	}
	return A;
}

// заполняет матрицу числами введенными с клавиатуры
Matr EnterMatr(Matr A)
{
    printf("\nEnter elements of matrix from Console...");
	for (int i = 0; i < A.row; i++)
	{
		for (int j = 0; j < A.col; j++)
        {
            printf("\nEnter A[%i][%i]: ", i, j);
            double temp;
            scanf("%lf", &temp);
            A.M[i][j] = temp;
        }
	}
	return A;
}

// Создание единичной матрицы
Matr EnterUnit(Matr A)
{
	for (int i = 0; i < A.row; i++)
	{
		for (int j = 0; j < A.col; j++)
			A.M[i][j] = 0;
		A.M[i][i] = 1;
	}
	return A;
}

// Возвращает разность двух матриц
Matr operator -(Matr A, Matr B)
{
	for (int i = 0; i < A.row; i++)
		for (int j = 0; j < A.col; j++)
			A.M[i][j] -= B.M[i][j];

	return A;
}

// Возвращает сумму двух матриц
Matr operator +(Matr A, Matr B)
{
	for (int i = 0; i < A.row; i++)
		for (int j = 0; j < A.col; j++)
			A.M[i][j] += B.M[i][j];

	return A;
}

// Умножение двух матриц
Matr operator *(Matr A, Matr B)
{
	//создаем вспомогательную матрицу
	Matr C;
	C = InitMatr(A.row, B.col);
	C = EnterZero(C);
	//во вспомогательную матрицу записываем результат умножения двух заданных матриц
	for (int i = 0; i < A.row; i++)
    	for (int j = 0; j < B.col; j++)
			for (int l = 0; l < A.col; l++ )
			C.M[i][j] += A.M[i][l] * B.M[l][j];

	//возвращаем результат умножения
	return C;
}

// Умножение матрицы на скаляр
Matr operator * (double a, Matr B)
{
	//создаем вспомогательную матрицу
	Matr C;
	C = InitMatr(B.row, B.col);
	C = EnterZero(C);
	//во вспомогательную матрицу записываем результат умножения матрицы на скаляр
	for (int i = 0; i < B.row; i++)
    	for (int j = 0; j < B.col; j++)
			C.M[i][j] = B.M[i][j] * a;

	return C;
}


//Функция для рассчета следа матрицы
double Spur(Matr A)
{
    double t = 0;
    for (int i = 0; i < A.row; i++)
        t += A.M[i][i];
    return t;
}
