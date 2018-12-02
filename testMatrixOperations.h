#include "matrix.h"
#include <time.h>
#include <iostream>

using namespace std;

Matr TrustfulSub(Matr A, Matr B)
{
	Matr C = InitMatr(A.order, B.order);
	for (int i = 0; i < A.size; i++)
		C.M[i] = A.M[i] - B.M[i];
	return C;
}

Matr TrustfulMulScalar(double lambda, Matr A)
{
	Matr C = InitMatr(A.order, A.order);
	for (int i = 0; i < A.size; i++)
		C.M[i] = A.M[i] * lambda;
	return C;
}

double TrustfulSpur(Matr A)
{
	double t = 0;
	for (int i = 0; i < A.size; i += A.order + 1)
		t += A.M[i];
	return t;
}

Matr TrustfulMul(Matr A, Matr B)
{
	Matr C = InitMatr(A.order, B.order);
	EnterZero(C);
	//во вспомогательную матрицу записываем результат умножения двух заданных матриц
	for (int i = 0; i < A.order; i++)
	for (int j = 0; j < B.order; j++)
	for (int l = 0; l < A.order; l++)
		C.M[i*A.order + j] += A.M[i*A.order + l] * B.M[l*A.order + j];
	//возвращаем результат умножения
	return C;
}
void FillMatrixSameRandomValues(Matr A, Matr B)
{
	srand((unsigned int)time(0));
	for (int i = 0; i < A.size; i++)
	{
		A.M[i] = B.M[i] = (double)rand() * 0.0000306;
	}
}

bool AreMatrixEqual(Matr A, Matr B)
{
	for (int i = 0; i < A.size; i++)
	if (A.M[i] != B.M[i])
		return false;
	return true;
}

void TestMultiply(int order)
{
	Matr buffer = InitMatr(order, order);
	Matr A = InitMatr(order, order);
	Matr B = InitMatr(order, order);
	Matr C = InitMatr(order, order);
	Matr D = InitMatr(order, order);
	FillMatrixSameRandomValues(A, C);
	FillMatrixSameRandomValues(B, D);
	Matr TrustfulResult = TrustfulMul(A, B);
	Matr ActualResult = multiply(C, D, buffer);
	if (AreMatrixEqual(TrustfulResult, ActualResult))
		cout << "Multiply is correct!\n";
	else cout << "Multiply is incorrect!\n";
	if (!AreMatrixEqual(A, C))
		cout << "	Matrix A has changed!\n";
	if (!AreMatrixEqual(B, D))
		cout << "	Matrix B has changed!\n";
}

void TestSubstract(int order)
{
	Matr buffer = InitMatr(order, order);
	Matr A = InitMatr(order, order);
	Matr B = InitMatr(order, order);
	Matr C = InitMatr(order, order);
	Matr D = InitMatr(order, order);
	FillMatrixSameRandomValues(A, C);
	FillMatrixSameRandomValues(B, D);
	Matr TrustfulResult = TrustfulSub(A, B);
	Matr ActualResult = sub(C, D, buffer);
	if (AreMatrixEqual(TrustfulResult, ActualResult))
		cout << "Substract is correct!\n";
	else cout << "Substract is incorrect!\n";
}

void TestMulScalar(int order)
{
	srand((unsigned int)time(0));
    double lambda = (double)rand() * 0.0000306;
	Matr buffer = InitMatr(order, order);
	Matr A = InitMatr(order, order);
	Matr B = InitMatr(order, order);
	FillMatrixSameRandomValues(A, B);
	Matr TrustfulResult = TrustfulMulScalar(lambda, A);
	Matr ActualResult = mulScalar(lambda, B, buffer);
	if (AreMatrixEqual(TrustfulResult, ActualResult))
		cout << "Scalar multiplication is correct!\n";
	else cout << "Scalar multiplication is incorrect!\n";
}

void TestSpur(int order)
{
	Matr buffer = InitMatr(order, order);
	Matr A = InitMatr(order, order);
	Matr B = InitMatr(order, order);
	FillMatrixSameRandomValues(A, B);
	double TrustfulResult = TrustfulSpur(A);
	double ActualResult = Spur(B);
	if (TrustfulResult == ActualResult)
		cout << "Spur is correct!\n";
	else cout << "Spur is incorrect!\n";
}