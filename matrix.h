//#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>

struct Matr // ����� ��� ���������� �������
{
	double* M; // ���������� ���� �������
	int order;  //������� �������
	int size;	//������ �������
};

// ������� ����������� �������. �� �� ��������. ���������� ������ �������
Matr InitMatr(int n, int m)
{
	//���������� ��������� �������
	Matr temp;
	//�������� ������ ��� ������
	temp.size = n * n;
	temp.M = new double[temp.size];
	//��������� ������� �������
	temp.order = n;
	//���������� ��������� �������
	return temp;
}

// �������� ������� �� ������
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

// ���������� ������� ������, ��� �������� ������� ����
Matr EnterZero(Matr A)
{
	for (int i = 0; i < A.size; i++)
	{
		A.M[i] = 0;
	}
	return A;
}

// ��������� ������� ���������� ������������� �������
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

// ��������� ������� ������� ���������� � ����������
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

// �������� ��������� �������
Matr EnterUnit(Matr A)
{
	A = EnterZero(A);
	for (int i = 0; i < A.size; i += A.order + 1)
	{
		A.M[i] = 1;
	}
	return A;
}

// ���������� �������� ���� ������
Matr operator -(Matr A, Matr B)
{
	for (int i = 0; i < A.size; i++)
		A.M[i] -= B.M[i];
	return A;
}

// ���������� ����� ���� ������
Matr operator +(Matr A, Matr B)
{
	for (int i = 0; i < A.size; i++)
		A.M[i] += B.M[i];
	return A;
}

// ��������� ���� ������
Matr operator *(Matr A, Matr B)
{
	//������� ��������������� �������
	Matr C;
	C = InitMatr(A.order, B.order);
	C = EnterZero(C);
	//�� ��������������� ������� ���������� ��������� ��������� ���� �������� ������
	for (int i = 0; i < A.order; i++)
		for (int j = 0; j < B.order; j++)
			for (int l = 0; l < A.order; l++)
				C.M[i*A.order + j] += A.M[i*A.order + l] * B.M[l*A.order + j];
	//���������� ��������� ���������
	return C;
}


// ��������� ������� �� ������
Matr operator * (double a, Matr B)
{
	Matr C;
	C = InitMatr(B.order, B.order);
	C = EnterZero(C);
	//�� ��������������� ������� ���������� ��������� ��������� ������� �� ������
	for (int i = 0; i < B.size; i++)
		C.M[i] = B.M[i] * a;
	return C;
}


//������� ��� �������� ����� �������
double Spur(Matr A)
{
	double t = 0;
	for (int i = 0; i < A.size; i += A.order + 1)
		t += A.M[i];
	return t;
}

