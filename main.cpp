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


	//test();
	//system("PAUSE");
	//return 0;


	//���������� � ������������ � ��������� ������ �������, � ������� ����� ��������
	//printf("Enter Size of Matrix: ");
	unsigned const short int N = 3;
	//scanf("%i", &N);
	//SquareMatr A2 = InitMatr(N, N);
	//���� ������� ��������� �������, ����������������� ��� ������� ����� 
	//��������� ������� ���������� ������� ( ��� ������� �������� ������ ���������)
	////A = EnterRandom(A);
	//Matr buffer = InitMatrSSE(N, N);
	//Matr A = InitMatrSSE(N, N);
	//Matr B = InitMatrSSE(N, N);
	//A.size = N*N;
	//A.order = N;

	//void *ptr = _aligned_malloc(A.size * sizeof(double), 16);
	//A.M = reinterpret_cast<double*>(ptr);
	//A.M[0] = 10.0; A.M[1] = 11.0; A.M[2] = 12.0; A.M[3] = 13.0;
	//A.M[4] = 14.0; A.M[5] = 15.0; A.M[6] = 16.0; A.M[7] = 17.0;
	//A.M[8] = 18.0;
	//B.size = N*N;
	//B.order = N;
	//void *ptr1 = _aligned_malloc(B.size * sizeof(double), 16);
	//B.M = reinterpret_cast<double*>(ptr1);
	//B.M[0] = 0.0; B.M[1] = 1.0; B.M[2] = 2.0; B.M[3] = 3.0;
	//B.M[4] = 4.0; B.M[5] = 5.0; B.M[6] = 6.0; B.M[7] = 7.0;
	//B.M[8] = 8.0;
	//Print(A);
	//Print(B);
	//Print(sub(A, B, buffer));
	//system("PAUSE");
	//return 0;


	bool print = true;
	//unsigned int count = 2;
	unsigned int count = 1000;
	unsigned int start_time = clock();
	for (unsigned int _i = 0; _i < count; _i++)
	{
		//������� ������� ��������� �������
		Matr A = InitMatrSSE(N, N);

		Matr buffer = InitMatrSSE(N, N);




		Matr buffer2 = InitMatrSSE(N, N);
		Matr buffer3 = InitMatrSSE(N, N);
		//Matr buffer4 = InitMatr(N, N);
		//buffer3 = EnterZero(buf)
		//A = EnterMatr(A);


		//A.size = 9;
		//A.order = 3;
		//A.M = new double[9]{
		//	1.0,2.0,3.0,4.0,10.0,6.0,7.0,8.0,9.0
		//};

		//SquareMatr A2 = InitMatr(N, N);
		//���� ������� ��������� �������, ����������������� ��� ������� ����� 
		//��������� ������� ���������� ������� ( ��� ������� �������� ������ ���������)
		A = EnterRandom(A);
		//Print(A);
		//��������� ������� � ����������, ��������� ��� �������� �������� �������
		//A = EnterMatr(A);
		//A2 = EnterMatr(A2);
		//Print(A*A2);
		//std::cout << Spur(A*A2) << std::endl;
		//������� ������� �� �����
		/*Print(A);

		Matr b = InitMatr(N, N);
		b = mulScalar(10, A, buffer3);
		Print(b);
		Print(mulScalar(10, b, buffer3));

		return 1;*/


		//������� ��� ��������������� �������, ��� ����� ��� ��������...
		Matr A1 = InitMatrSSE(N, N);
		Matr B1 = InitMatrSSE(N, N);
		//������� B1 ������� ���������
		B1 = EnterUnit(B1);
		//std::cout << "Unit Matrix:";
		//Print(B1 * B1);
		//Print(A*B1);
		//������� �������, ��� ����� �������� ��������
		Matr UA = InitMatrSSE(N, N);
		//������� ��������� �������, ����� ��� ��������
		Matr E = InitMatrSSE(N, N);
		E = EnterUnit(E);
		//Print(A-A);
		//������� ������, ��� ���� �������� ������������ ������������������� ��������
		double* lamb = new double[N];
		//����� ������� ������ ��������� ������� �����, ����� ������� ����� ���������� ��������
		//unsigned int start_time = clock();
		//�������� ��� �������� �������-��������, ��������� �� �� ���������� ��������
		//��������� ��� ������� ��������
		for (unsigned short int i = 1; i < N; i++)
		{
			//������������� ������� A1 � B1 �� �������� ��������
			A1 = multiply(A, B1, buffer);
			//A1 = A*B1;
			//std::cout << "A1:" << std::endl;
			//Print(A1);
			//std::cout << std::endl;
			//���������� ��������� ����������� ������������������� ��������
			lamb[i - 1] = Spur(A1) / i;


			B1 = sub(A1, mulScalar(lamb[i - 1], E, buffer3), buffer2);

			//B1 = sub(A1, lamb[i - 1] * E, buffer2);


			//B1 = A1 - lamb[i - 1] * E;
		}
		//cout << "B1:\n" << endl;
		//Print(B1);
		//�� ��������� ���� ������� ������ ������� A1 ������������
		//������� B1 �� ���������� ���� ������ ���� � ����
		A1 = multiply(A, B1, buffer);
		//cout << "A1:\n" << endl;
		//Print(A1);
		//A1 = A*B1;
		//�������� ��������� ����������� ��������
		lamb[N - 1] = Spur(A1) / N;
		//��������� �������� �������, ��� ��������� ����� ������������� ������� B1
		//������ �� � �� ������� B 1��� ���...
		//Print(A1);
		//Print(B1);
		//cout << "buffer3:\n" << endl;
		//Print(buffer3);
		UA = mulScalar((1 / lamb[N - 1]), B1, buffer3);
		//cout << "UA:\n" << endl;
		//Print(UA);

		//UA = (1 / lamb[N - 1]) * B1;
		//������� ����� � ����� ����� ���������...
		//unsigned int end_time = clock();
		//������� ������������ ������������������� ��������
		//printf("\n\nCoeff polynom's: \n");
		//for (int i = 0; i < N; i++)
			//printf("Lambda %i  --   %6.8f\n", i + 1, lamb[i]);
		//�������� �������� �������
		//printf("\n\nInverse Matrix:\n");
		//Print(UA);
		//��������� ������������ �������� �������, ������ ��������� ��������� �������� ������� � ��������
		//printf("\n\ncheck to Inverse matrix: A^-1 * A\n");
		//printf("Print A");
		//Print(A);
		if (print)
		{
			Print(multiply(UA, A, buffer));
		}
		//Print(UA*A);
	}

	unsigned int end_time = clock();
	//������� �� ����� ����� ������ ���������...
	printf("Run time --- %i\n\n", end_time - start_time);
	printf("Run time --- %10.8f\n\n", (float)(end_time - start_time) / count);
	return 0;
}
