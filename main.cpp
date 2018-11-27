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
	//printf("Enter Size of Matrix: ");
	unsigned short int N = 3;
	//scanf("%i", &N);
	//SquareMatr A2 = InitMatr(N, N);
	//двва способа заполнить матрицу, раскоменнтировать тот который нужен 
	//заполняем матрицу случайными числами ( для больших размеров матриц актуально)
	////A = EnterRandom(A);


	/*Matr A = InitMatr(N, N);

	A.size = 9;
	A.order = 3;
	A.M = new double[9]{
		1.0,2.0,3.0,4.0,10.0,6.0,7.0,8.0,9.0
	};

	Print(A);

	A = transpose(A);

	Print(A);

	return 0;*/



	//unsigned int count = 2;
	unsigned int count = 1;
	unsigned int start_time = clock();
	for (unsigned int _i = 0; _i < count; _i++)
	{
		//Создаем матрицу заданного размера
		Matr A = InitMatr(N, N);

		Matr buffer = InitMatr(N, N);
		Matr buffer2 = InitMatr(N, N);
		Matr buffer3 = InitMatr(N, N);
		//Matr buffer4 = InitMatr(N, N);
		//buffer3 = EnterZero(buf)
		//A = EnterMatr(A);


		//A.size = 9;
		//A.order = 3;
		//A.M = new double[9]{
		//	1.0,2.0,3.0,4.0,10.0,6.0,7.0,8.0,9.0
		//};

		//SquareMatr A2 = InitMatr(N, N);
		//двва способа заполнить матрицу, раскоменнтировать тот который нужен 
		//заполняем матрицу случайными числами ( для больших размеров матриц актуально)
		//A = EnterRandom(A);
		//заполняем матрицу с клавиатуры, актуально для небольши размеров матрицы
		A = EnterMatr(A);
		//A2 = EnterMatr(A2);
		//Print(A*A2);
		//std::cout << Spur(A*A2) << std::endl;
		//выводим матрицу на экран
		/*Print(A);

		Matr b = InitMatr(N, N);
		b = mulScalar(10, A, buffer3);
		Print(b);
		Print(mulScalar(10, b, buffer3));

		return 1;*/


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
		for (unsigned short int i = 1; i < N; i++)
		{
			//Пересчитываем матрицу A1 и B1 по формулам Фаддеева
			A1 = multiply(A, B1, buffer);
			//A1 = A*B1;
			//std::cout << "A1:" << std::endl;
			//Print(A1);
			//std::cout << std::endl;
			//Записываем очередной коэффициент характеристического полинома
			lamb[i - 1] = Spur(A1) / i;


			B1 = sub(A1, mulScalar(lamb[i - 1], E, buffer3), buffer2);

			//B1 = sub(A1, lamb[i - 1] * E, buffer2);


			//B1 = A1 - lamb[i - 1] * E;
		}
		//cout << "B1:\n" << endl;
		//Print(B1);
		//На последнем шаге считаем только матрицу A1 икоэффициент
		//матрица B1 на посчледнем шаге должна уйти в ноль
		A1 = multiply(A, B1, buffer);
		//cout << "A1:\n" << endl;
		//Print(A1);
		//A1 = A*B1;
		//записали последний коэффициент полинома
		lamb[N - 1] = Spur(A1) / N;
		//посчитали обратную матрицу, она считается через предпоследнюю матрицу B1
		//Почему мы и не считаем B 1еще раз...
		//Print(A1);
		//Print(B1);
		//cout << "buffer3:\n" << endl;
		//Print(buffer3);
		UA = mulScalar((1 / lamb[N - 1]), B1, buffer3);
		//cout << "UA:\n" << endl;
		//Print(UA);

		//UA = (1 / lamb[N - 1]) * B1;
		//Смотрим время в конце работ алгоритма...
		//unsigned int end_time = clock();
		//Выводим коэффициенты характеристического полинома
		printf("\n\nCoeff polynom's: \n");
		for (int i = 0; i < N; i++)
			printf("Lambda %i  --   %6.8f\n", i + 1, lamb[i]);
		//Печатаем обратную матрицу
		printf("\n\nInverse Matrix:\n");
		Print(UA);
		//Проверяем правильность обратной матрицы, выводм результат умножения обратной амтрицы и исходной
		printf("\n\ncheck to Inverse matrix: A^-1 * A\n");
		printf("Print A");
		//Print(A);
		Print(multiply(UA, A, buffer));
		//Print(UA*A);
	}

	unsigned int end_time = clock();
	//Выводим на экран время работы алгоритма...
	printf("Run time --- %i\n\n", end_time - start_time);
	printf("Run time --- %10.8f\n\n", (float)(end_time - start_time) / count);
	return 0;
}
