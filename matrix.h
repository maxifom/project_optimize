//#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <omp.h>

struct Matr // ����� ��� ���������� �������
{
	double* M; // ���������� ���� �������
	int order;  //������� �������
	int size;	//������ �������
};

// ������� ����������� �������. �� �� ��������. ���������� ������ �������
Matr InitMatr(unsigned int n, unsigned int m)
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
void EnterZero(Matr A)
{
	double* end_array = A.M + A.size;
	while (A.M < end_array)
	{
		*A.M = 0.0;
		A.M++;
	}
	A.M -= A.size;
	/*#pragma omp parallel for
	for (int i = 0; i < A.size; i++)
	{
		A.M[i] = 0.0;
	}*/
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
	A.M -= A.size;
	/*#pragma omp parallel for
	for (int i = 0; i < A.size; i++)
	{
		A.M[i] = (double)rand() * 0.0000306;
	}*/
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

// �������� ��������� �������k
// �������� ��������� �������k
void EnterUnit(Matr A)
{
	EnterZero(A);
	for (int i = 0; i < A.size; i += A.order + 1)
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
	#pragma omp parallel for
	for (int i = 0; i < A.size; i++)
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
	#pragma omp parallel for
	for (int i = 0; i < A.size; i += A.order)
	{
		//std::cout << "Thread " << omp_get_thread_num() << " execute " << i << std::endl;
		for (int j = 0; j < B.order; j++)
		{
			for (int l = 0; l < A.order; l++)
				buffer.M[i + j] += A.M[i + l] * B.M[l*A.order + j];
		}
	}
	return buffer;
}

Matr mulScalar(double a, Matr B, Matr buffer)
{
	//buffer = EnterZero(buffer);
	//�� ��������������� ������� ���������� ��������� ��������� ������� �� ������
	#pragma omp parallel for
	for (int i = 0; i < B.size; i++)
		buffer.M[i] = B.M[i] * a;
	return buffer;
}


//������� ��� �������� ����� �������
double Spur(Matr A)
{
	double t = 0;
	for (int i = 0; i < A.size; i += A.order + 1)
		t += A.M[i];
	return t;
}

