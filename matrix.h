//#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>

struct Matr // Новый тип Квадратная матрица
{
	double* M; // Собственно сама матрица
	int order;  //Порядок матрицы
	int size;	//Размер матрицы
};

// Функция определения матрицы. по ее размерам. Возвращает пустую матрицу
Matr InitMatr(int n, int m)
{
	//Определяем временную матрицу
	Matr temp;
	//выделяем память под строки
	temp.size = n * n;
	temp.M = new double[temp.size];
	//запсываем размеры матрицы
	temp.order = n;
	//возвращаем созданную матрицу
	return temp;
}

// Печатает матрицу на экране
void Print(Matr A)
{
	//printf("\n\nEnter Matrix To Console!!!\n");
	for (int i = 0; i < A.order; i++)
	{
		for (int j = 0; j < A.order; j++)
		{
			printf("%10.8f    ", A.M[i*A.order + j]);
		}
		printf("\n");
	}
}

// Заполнение матрицы нолями, все элементы матрицы нули
Matr EnterZero(Matr A)
{
	for (int i = 0; i < A.size; i++)
	{
		A.M[i] = 0;
	}
	return A;
}

// заполняет матрицу случайными вещественными числами
Matr EnterRandom(Matr A)
{
	srand((unsigned int)time(0));
	for (int i = 0; i < A.size; i++)
	{
		A.M[i] = (double)rand() * 0.0000306;
		//A.M[i] = (double)rand() / RAND_MAX;
	}
	return A;
}

// заполняет матрицу числами введенными с клавиатуры
Matr EnterMatr(Matr A)
{
	printf("\nEnter elements of matrix from Console...");

	for (int i = 0; i < A.order; i++)
	{
		for (int j = 0; j < A.order; j++)
		{
			printf("\nEnter A[%i][%i]: ", i, j);
			scanf("%lf", &A.M[i*A.order + j]);
		}
	}

	return A;
}

// Создание единичной матрицы
Matr EnterUnit(Matr A)
{
	A = EnterZero(A);
	for (int i = 0; i < A.size; i += A.order + 1)
	{
		A.M[i] = 1;
	}
	return A;
}

// Возвращает разность двух матриц
Matr operator -(Matr A, Matr B)
{
	for (int i = 0; i < A.size; i++)
		A.M[i] -= B.M[i];
	return A;
}

// Возвращает сумму двух матриц
Matr operator +(Matr A, Matr B)
{
	for (int i = 0; i < A.size; i++)
		A.M[i] += B.M[i];
	return A;
}

// Умножение двух матриц
Matr operator *(Matr A, Matr B)
{
	//создаем вспомогательную матрицу
	Matr C;
	C = InitMatr(A.order, B.order);
	C = EnterZero(C);
	//во вспомогательную матрицу записываем результат умножения двух заданных матриц
	for (int i = 0; i < A.order; i++)
		for (int j = 0; j < B.order; j++)
			for (int l = 0; l < A.order; l++)
				C.M[i*A.order + j] += A.M[i*A.order + l] * B.M[l*A.order + j];
	//возвращаем результат умножения
	return C;
}


// Умножение матрицы на скаляр
Matr operator * (double a, Matr B)
{
	Matr C;
	C = InitMatr(B.order, B.order);
	C = EnterZero(C);
	//во вспомогательную матрицу записываем результат умножения матрицы на скаляр
	for (int i = 0; i < B.size; i++)
		C.M[i] = B.M[i] * a;
	return C;
}


//Функция для рассчета следа матрицы
double Spur(Matr A)
{
	double t = 0;
	for (int i = 0; i < A.size; i += A.order + 1)
		t += A.M[i];
	return t;
}

