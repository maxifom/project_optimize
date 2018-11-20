//#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>

struct Matr // ����� ��� �������
{
	double** M; // ���������� ���� �������
	int row;    // ���������� �����
	int col;    // ���������� ��������
};

// ������� ����������� �������. �� �� ��������. ���������� ������ �������
Matr InitMatr(int n, int m)
{
	//���������� ��������� �������
	Matr temp;
	//�������� ������ ��� ������
	temp.M = new double*[n];
	//��������� ������� �������
	temp.row = n;
	temp.col = m;
	//�������� ������ ��� ������ �� ��������...
	for (int i = 0; i < temp.row; i++)
	{
		temp.M[i] = new double[m];
	}
	//���������� ��������� �������
	return temp;
}

// �������� ������� �� ������
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

// ���������� ������� ������, ��� �������� ������� ����
Matr EnterZero(Matr A)
{
	for (int i = 0; i < A.row; i++)
	{
		for (int j = 0; j < A.col; j++)
			A.M[i][j] = 0;
	}
	return A;
}

// ��������� ������� ���������� ������������� �������
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

// ��������� ������� ������� ���������� � ����������
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

// �������� ��������� �������
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

// ���������� �������� ���� ������
Matr operator -(Matr A, Matr B)
{
	for (int i = 0; i < A.row; i++)
		for (int j = 0; j < A.col; j++)
			A.M[i][j] -= B.M[i][j];

	return A;
}

// ���������� ����� ���� ������
Matr operator +(Matr A, Matr B)
{
	for (int i = 0; i < A.row; i++)
		for (int j = 0; j < A.col; j++)
			A.M[i][j] += B.M[i][j];

	return A;
}

// ��������� ���� ������
Matr operator *(Matr A, Matr B)
{
	//������� ��������������� �������
	Matr C;
	C = InitMatr(A.row, B.col);
	C = EnterZero(C);
	//�� ��������������� ������� ���������� ��������� ��������� ���� �������� ������
	for (int i = 0; i < A.row; i++)
    	for (int j = 0; j < B.col; j++)
			for (int l = 0; l < A.col; l++ )
			C.M[i][j] += A.M[i][l] * B.M[l][j];

	//���������� ��������� ���������
	return C;
}

// ��������� ������� �� ������
Matr operator * (double a, Matr B)
{
	//������� ��������������� �������
	Matr C;
	C = InitMatr(B.row, B.col);
	C = EnterZero(C);
	//�� ��������������� ������� ���������� ��������� ��������� ������� �� ������
	for (int i = 0; i < B.row; i++)
    	for (int j = 0; j < B.col; j++)
			C.M[i][j] = B.M[i][j] * a;

	return C;
}


//������� ��� �������� ����� �������
double Spur(Matr A)
{
    double t = 0;
    for (int i = 0; i < A.row; i++)
        t += A.M[i][i];
    return t;
}
