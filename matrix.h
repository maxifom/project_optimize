//#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>

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
}

// Заполнение матрицы нолями, все элементы матрицы нули
void EnterZero(Matr A)
{
	double* end_array = A.M + A.size;
	while (A.M < end_array)
	{
		*A.M = 0.0;
		A.M++;
	}
	A.M -= A.size;
}

// заполняет матрицу случайными вещественными числами
void EnterRandom(Matr A)
{
	srand((unsigned int)time(0));
	double* end_array = A.M + A.size;
	while (A.M < end_array)
	{
		*A.M = (double)rand() * 0.0000306;
		A.M++;
	}
	A.M -= A.size;
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

// Создание единичной матрицыk
// Создание единичной матрицыk
void EnterUnit(Matr A)
{
	EnterZero(A);
	for (unsigned short int i = 0; i < A.size; i += A.order + 1)
	{
		A.M[i] = 1;
	}
	/*double* end_array = A.M + A.size;
	while (A.M < end_array)
	{
		*A.M = 1;
		A.M+=A.order+1;
	}
	A.M -= A.size +A.order;*/
}




Matr sub(Matr A, Matr B, Matr buffer)
{
	for (unsigned short int i = 0; i < A.size; i++)
		buffer.M[i] = A.M[i] - B.M[i];
	/*double* end_array = A.M + A.size;
	while (A.M < end_array)
	{
		*buffer.M = *A.M - *B.M;
		A.M++;
		B.M++;
		buffer.M++;
	}
	A.M -= A.size;
	B.M -= A.size;
	buffer.M -= A.size;*/
	return buffer;
}

Matr multiply(Matr A, Matr B, Matr buffer)
{
	EnterZero(buffer);
	//FIRST VARIANT
	/*for (unsigned short int i = 0; i < A.order; i++)
		for (unsigned short int j = 0; j < B.order; j++)
			for (unsigned short int l = 0; l < A.order; l++)
				buffer.M[i*A.order + j] += A.M[i*A.order + l] * B.M[l*A.order + j];*/
				//MULT WITH TRANSPOSING
	/*double temp;
	unsigned short int temp_i;
	unsigned short int temp_j;
	for (unsigned short int i = 0; i < B.order; i++)
	{
		for (unsigned short int j = i + 1; j < B.order; j++)
		{
			temp_i = i * B.order;
			temp_j = j * B.order;
			temp = B.M[temp_i + j];
			B.M[temp_i + j] = B.M[temp_j + i];
			B.M[temp_j + i] = temp;
		}
	}*/

	for (unsigned short int i = 0; i < A.size; i+=A.order)
	{
		for (unsigned short int j = 0; j < B.order; j++)
		{
			for (unsigned short int l = 0; l < A.order; l++)
				buffer.M[i + j] += A.M[i + l] * B.M[l*A.order + j];
		}
	}
	//POINTERS MULT REQUARES TRANSPOSE
	////unsigned short int i = 0;
	//unsigned short int j;
	////unsigned short int l;
	//double* end_array_buffer = buffer.M + A.size;
	//double* end_array_b = B.M + A.size;
	//double* temp_b;
	//while (buffer.M < end_array_buffer)
	//{
	//	j = 0;
	//	while (j < A.order)
	//	{
	//		temp_b = B.M + A.order;
	//		while (B.M < temp_b)
	//		{
	//			*buffer.M += *A.M * *B.M;
	//			B.M++;
	//			A.M++;
	//		}
	//		A.M -= A.order;
	//		buffer.M++;
	//		j++;
	//	}
	//	B.M -= A.size;
	//	A.M += A.order;
	//}
	//buffer.M -= A.size;
	//A.M -= A.size;
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


// Умножение матрицы на скаляр
Matr operator * (double a, Matr B)
{
	Matr C;
	C = InitMatr(B.order, B.order);
	EnterZero(C);
	//во вспомогательную матрицу записываем результат умножения матрицы на скаляр
	for (unsigned short int i = 0; i < B.size; i++)
		C.M[i] = B.M[i] * a;
	return C;
}


//Функция для рассчета следа матрицы
double Spur(Matr A)
{
	double t = 0;
	for (unsigned short int i = 0; i < A.size; i += A.order + 1)
		t += A.M[i];
	return t;
}

