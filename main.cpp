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
	//���������� � ������������ � ��������� ������ �������, � ������� ����� ��������
	printf("Enter Size of Matrix: ");
	int N;
	scanf("%i", &N);
	//SquareMatr A2 = InitMatr(N, N);
	//���� ������� ��������� �������, ����������������� ��� ������� ����� 
	//��������� ������� ���������� ������� ( ��� ������� �������� ������ ���������)
	//A = EnterRandom(A);




	int count = 10000;
	unsigned int start_time = clock();
	for (int _i = 0; _i < count; _i++)
	{
		//������� ������� ��������� �������
		Matr A = InitMatr(N, N);
		//SquareMatr A2 = InitMatr(N, N);
		//���� ������� ��������� �������, ����������������� ��� ������� ����� 
		//��������� ������� ���������� ������� ( ��� ������� �������� ������ ���������)
		A = EnterRandom(A);
		//��������� ������� � ����������, ��������� ��� �������� �������� �������
		//A = EnterMatr(A);
		//A2 = EnterMatr(A2);
		//Print(A*A2);
		//std::cout << Spur(A*A2) << std::endl;
		//������� ������� �� �����
		//Print(A);
		//������� ��� ��������������� �������, ��� ����� ��� ��������...
		Matr A1 = InitMatr(N, N);
		Matr B1 = InitMatr(N, N);
		//������� B1 ������� ���������
		B1 = EnterUnit(B1);
		//std::cout << "Unit Matrix:";
		//Print(B1 * B1);
		//Print(A*B1);
		//������� �������, ��� ����� �������� ��������
		Matr UA = InitMatr(N, N);
		//������� ��������� �������, ����� ��� ��������
		Matr E = InitMatr(N, N);
		E = EnterUnit(E);
		//Print(A-A);
		//������� ������, ��� ���� �������� ������������ ������������������� ��������
		double* lamb = new double[N];
		//����� ������� ������ ��������� ������� �����, ����� ������� ����� ���������� ��������
		//unsigned int start_time = clock();
		//�������� ��� �������� �������-��������, ��������� �� �� ���������� ��������
		//��������� ��� ������� ��������
		for (int i = 1; i < N; i++)
		{
			//������������� ������� A1 � B1 �� �������� ��������
			A1 = A * B1;
			//std::cout << "A1:" << std::endl;
			//Print(A1);
			//std::cout << std::endl;
			//���������� ��������� ����������� ������������������� ��������
			lamb[i - 1] = Spur(A1) / i;
			B1 = A1 - lamb[i - 1] * E;
		}
		//�� ��������� ���� ������� ������ ������� A1 ������������
		//������� B1 �� ���������� ���� ������ ���� � ����
		A1 = A * B1;
		//�������� ��������� ����������� ��������
		lamb[N - 1] = Spur(A1) / N;
		//��������� �������� �������, ��� ��������� ����� ������������� ������� B1
		//������ �� � �� ������� B 1��� ���...
		UA = (1 / lamb[N - 1]) * B1;
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
		Print(UA * A);
	}

	unsigned int end_time = clock();
	//������� �� ����� ����� ������ ���������...
	printf("Run time --- %i\n\n", end_time - start_time);
	printf("Run time --- %10.8f\n\n", (float)(end_time - start_time) / count);
	return 0;
}
