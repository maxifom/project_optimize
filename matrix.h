//#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <xmmintrin.h>
struct Matr // Новый тип Квадратная матрица
{
	double* M; // Собственно сама матрица
	unsigned short int order;  //Порядок матрицы
	unsigned short int size;	//Размер матрицы
};

// Функция определения матрицы. по ее размерам. Возвращает пустую матрицу
Matr InitMatr(unsigned int n, unsigned int m)
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
	for (unsigned short int i = 0; i < A.order; i++)
	{
		for (unsigned short int j = 0; j < A.order; j++)
		{
			printf("%10.8f    ", A.M[i*A.order + j]);
		}
		printf("\n");
	}
	printf("\n");
}

// Заполнение матрицы нолями, все элементы матрицы нули
//Matr EnterZero(Matr A)
//{
//	for (unsigned short int i = 0; i < A.size; i++)
//	{
//		A.M[i] = 0;
//	}
//	return A;
//}

Matr EnterZero(Matr A)
{
	for (double *i = A.M; i < A.M + A.size; i++)
	{
		*i = 0;
	}
	return A;
}





// заполняет матрицу случайными вещественными числами
Matr EnterRandom(Matr A)
{
	srand((unsigned int)time(0));
	//for (unsigned short int i = 0; i < A.size;i++)
	for (double *i = A.M; i < A.M + A.size; i++)
	{
		*i = (double)rand() * 0.0000306;
		//A.M[i] = (double)rand() * 0.0000306;
		//A.M[i] = (double)rand() / RAND_MAX;
	}


	return A;
}

// заполняет матрицу числами введенными с клавиатуры
Matr EnterMatr(Matr A)
{
	printf("\nEnter elements of matrix from Console...");

	for (unsigned short int i = 0; i < A.order; i++)
	{
		for (unsigned short int j = 0; j < A.order; j++)
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
	//for (unsigned short int i = 0; i < A.size; i += A.order + 1)
	for (double *i = A.M; i < A.M + A.size; i += A.order + 1)
	{
		*i = 1;
		//A.M[i] = 1;
	}
	return A;
}




Matr sub(Matr A, Matr B, Matr buffer)
{
	//buffer = EnterZero(buffer);
	for (unsigned short int i = 0; i < A.size; i++)
	{
		buffer.M[i] = A.M[i] - B.M[i];
	}
	return buffer;
}

Matr multiply(Matr A, Matr B, Matr buffer)
{
	//создаем вспомогательную матрицу
	buffer = EnterZero(buffer);
	double temp;
	unsigned short int temp_i;
	unsigned short int temp_j;
	for (unsigned short int i = 0; i < B.order; i++)
	{
		for (unsigned short int j = i + 1; j < B.order; j++)
		{
			temp_i = i*B.order;
			temp_j = j*B.order;
			temp = B.M[temp_i + j];
			B.M[temp_i + j] = B.M[temp_j + i];
			B.M[temp_j + i] = temp;
		}
	}

	//во вспомогательную матрицу записываем результат умножения двух заданных матриц
	for (unsigned short int i = 0; i < A.order; i++)
	{
		temp_i = i*A.order;
		for (unsigned short int j = 0; j < B.order; j++)
		{
			buffer.M[temp_i + j] += A.M[temp_i + j] * B.M[temp_i + j];
		}
	}
	//возвращаем результат умножения
	return buffer;
}



Matr mulScalar(double a, Matr B, Matr buffer)
{
	//buffer = EnterZero(buffer);
	//во вспомогательную матрицу записываем результат умножения матрицы на скаляр
	for (unsigned short int i = 0; i < B.size; i++)
		buffer.M[i] = B.M[i] * a;
	return buffer;
}




//Функция для рассчета следа матрицы
double Spur(Matr A)
{
	double t = 0;
	//for (unsigned short int i = 0; i < A.size; i += A.order + 1)
	for (double *i = A.M; i < A.M + A.size; i += A.order + 1)
	{
		t += *i;
		//t += A.M[i];
	}
	return t;
}

//Matr transpose(Matr A)
//{
//	double temp;
//	for (unsigned short int i = 0; i < A.order; i++)
//	{
//		for (unsigned short int j = i + 1; j < A.order; j++)
//		{
//			temp = A.M[i*A.order + j];
//			A.M[i*A.order + j] = A.M[j*A.order + i];
//			A.M[j*A.order + i] = temp;
//		}
//	}
//	return A;
//}