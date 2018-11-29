//#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>

struct Matr // ����� ��� ���������� �������
{
	double* M; // ���������� ���� �������
	unsigned short int order;  //������� �������
	unsigned short int size;	//������ �������
};

// ������� ����������� �������. �� �� ��������. ���������� ������ �������
Matr InitMatr(unsigned int n,unsigned int m)
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
	for (unsigned short int i = 0; i < A.order; i++)
	{
		for (unsigned short int j = 0; j < A.order; j++)
		{
			printf("%10.8f    ", A.M[i*A.order + j]);
		}
		printf("\n");
	}
}

// ���������� ������� ������, ��� �������� ������� ����
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

// ��������� ������� ���������� ������������� �������
void EnterRandom(Matr A)
{
	srand((unsigned int)time(0));
	double* end_array = A.M + A.size;
	while (A.M < end_array)
	{
		*A.M = (double)rand() * 0.0000306;
		A.M++;
	}
	A.M -= A.size ;
}

// ��������� ������� ������� ���������� � ����������
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

// �������� ��������� �������k
// �������� ��������� �������k
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
	//buffer = EnterZero(buffer);
	for (unsigned short int i = 0; i < A.size; i++)
		buffer.M[i] = A.M[i] - B.M[i];
	return buffer;
}

Matr multiply(Matr A, Matr B, Matr buffer)
{
	EnterZero(buffer);
	/*for (unsigned short int i = 0; i < A.order; i++)
		for (unsigned short int j = 0; j < B.order; j++)
			for (unsigned short int l = 0; l < A.order; l++)
				buffer.M[i*A.order + j] += A.M[i*A.order + l] * B.M[l*A.order + j];*/
	for (unsigned short int i = 0; i < A.size; i+=A.order)
	{
		for (unsigned short int j = 0; j < B.order; j++)
		{
			for (unsigned short int l = 0; l < A.order; l++)
				buffer.M[i + j] += A.M[i + l] * B.M[l*A.order + j];
		}
	}
	//double temp;
	//unsigned short int temp_i;
	//unsigned short int temp_j;
	//for (unsigned short int i = 0; i < B.order; i++)
	//{
	//	for (unsigned short int j = i + 1; j < B.order; j++)
	//	{
	//		temp_i = i * B.order;
	//		temp_j = j * B.order;
	//		temp = B.M[temp_i + j];
	//		B.M[temp_i + j] = B.M[temp_j + i];
	//		B.M[temp_j + i] = temp;
	//	}
	//}

	//for (unsigned short int i = 0; i < A.size; i+=A.order)
	//{		
	//	for (unsigned short int j = 0; j < A.order; j++)
	//	{
	//		for (unsigned short int l = 0; l < A.order; l++)
	//		{
	//			buffer.M[i + j] += A.M[i + l] * B.M[j*A.order + l];
	//		}
	//	}
	//}

	return buffer;
}


// ��������� ���� ������
Matr operator *(Matr A, Matr B)
{
	//������� ��������������� �������
	Matr C;
	C = InitMatr(A.order, B.order);
	EnterZero(C);
	//�� ��������������� ������� ���������� ��������� ��������� ���� �������� ������
	for (unsigned short int i = 0; i < A.order; i++)
		for (unsigned short int j = 0; j < B.order; j++)
			for (unsigned short int l = 0; l < A.order; l++)
				C.M[i*A.order + j] += A.M[i*A.order + l] * B.M[l*A.order + j];
	//���������� ��������� ���������
	return C;
}

Matr mulScalar(double a, Matr B, Matr buffer)
{
	//buffer = EnterZero(buffer);
	//�� ��������������� ������� ���������� ��������� ��������� ������� �� ������
	for (unsigned short int i = 0; i < B.size; i++)
		buffer.M[i] = B.M[i] * a;
	return buffer;
}


// ��������� ������� �� ������
Matr operator * (double a, Matr B)
{
	Matr C;
	C = InitMatr(B.order, B.order);
	EnterZero(C);
	//�� ��������������� ������� ���������� ��������� ��������� ������� �� ������
	for (unsigned short int i = 0; i < B.size; i++)
		C.M[i] = B.M[i] * a;
	return C;
}


//������� ��� �������� ����� �������
double Spur(Matr A)
{
	double t = 0;
	for (unsigned short int i = 0; i < A.size; i += A.order + 1)
		t += A.M[i];
	return t;
}

