#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include <time.h>
using namespace std;

int main()
{
	//Спрашиваем у пользователя и считываем размер матрицы, с которой будем работать
	printf("Enter Size of Matrix: ");
	int N;
	scanf("%i", &N);
	//SquareMatr A2 = InitMatr(N, N);
	//двва способа заполнить матрицу, раскоменнтировать тот который нужен 
	//заполняем матрицу случайными числами ( для больших размеров матриц актуально)
	//A = EnterRandom(A);




	int count = 10000;
	unsigned int start_time = clock();
	for (int _i = 0; _i < count; _i++)
	{
		//Создаем матрицу заданного размера
		Matr A = InitMatr(N, N);
		//SquareMatr A2 = InitMatr(N, N);
		//двва способа заполнить матрицу, раскоменнтировать тот который нужен 
		//заполняем матрицу случайными числами ( для больших размеров матриц актуально)
		A = EnterRandom(A);
		//заполняем матрицу с клавиатуры, актуально для небольши размеров матрицы
		//A = EnterMatr(A);
		//A2 = EnterMatr(A2);
		//Print(A*A2);
		//std::cout << Spur(A*A2) << std::endl;
		//выводим матрицу на экран
		//Print(A);
		//создаем две вспомогательных матрицы, они нужны для расчетов...
		Matr A1 = InitMatr(N, N);
		Matr B1 = InitMatr(N, N);
		//Матрица B1 сначала единичная
		B1 = EnterUnit(B1);
		//std::cout << "Unit Matrix:";
		//Print(B1 * B1);
		//Print(A*B1);
		//создаем матрицу, где будет записана обратная
		Matr UA = InitMatr(N, N);
		//создаем единичную матрицу, нужна для расчетов
		Matr E = InitMatr(N, N);
		E = EnterUnit(E);
		//Print(A-A);
		//создаем массив, где бдут записаны коэффициенты характеристического полинома
		double* lamb = new double[N];
		//Перед началом работы алгоритма снимаем время, чтобы оценить время выполнения расчетов
		//unsigned int start_time = clock();
		//начинаем сам алгоритм Леверье-Фаддеева, запускаем не до последнего элемента
		//последний шаг считаем отдельно
		for (int i = 1; i < N; i++)
		{
			//Пересчитываем матрицу A1 и B1 по формулам Фаддеева
			A1 = A * B1;
			//std::cout << "A1:" << std::endl;
			//Print(A1);
			//std::cout << std::endl;
			//Записываем очередной коэффициент характеристического полинома
			lamb[i - 1] = Spur(A1) / i;
			B1 = A1 - lamb[i - 1] * E;
		}
		//На последнем шаге считаем только матрицу A1 икоэффициент
		//матрица B1 на посчледнем шаге должна уйти в ноль
		A1 = A * B1;
		//записали последний коэффициент полинома
		lamb[N - 1] = Spur(A1) / N;
		//посчитали обратную матрицу, она считается через предпоследнюю матрицу B1
		//Почему мы и не считаем B 1еще раз...
		UA = (1 / lamb[N - 1]) * B1;
		//Смотрим время в конце работ алгоритма...
		//unsigned int end_time = clock();
		//Выводим коэффициенты характеристического полинома
		//printf("\n\nCoeff polynom's: \n");
		//for (int i = 0; i < N; i++)
			//printf("Lambda %i  --   %6.8f\n", i + 1, lamb[i]);
		//Печатаем обратную матрицу
		//printf("\n\nInverse Matrix:\n");
		//Print(UA);
		//Проверяем правильность обратной матрицы, выводм результат умножения обратной амтрицы и исходной
		//printf("\n\ncheck to Inverse matrix: A^-1 * A\n");
		//printf("Print A");
		//Print(A);
		Print(UA * A);
	}

	unsigned int end_time = clock();
	//Выводим на экран время работы алгоритма...
	printf("Run time --- %i\n\n", end_time - start_time);
	printf("Run time --- %10.8f\n\n", (float)(end_time - start_time) / count);
	return 0;
}
