#include <iostream>

#include "utilities.h"

using namespace std;

double MaxNorm(double* v, int length) {
	double max = v[0];

	for (int i = 1; i < length; i++) {
		if (fabs(v[i]) > max)
			max = fabs(v[i]);
	}

	return max;
}

double EuclideanNorm(double* v, int length) {
	return sqrt(ScalarMultiply(v, v, length));
}

double ScalarMultiply(double* v1, double* v2, int length) {
	double result = 0;

	for (int i = 0; i < length; i++)
		result += v1[i] * v2[i];

	return result;
}

void PrintMatrix(double** m, int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++)
			cout << m[i][j] << ' ';

		cout << '\n';
	}
}

void PrintVector(double* v, int length) {
	for (int i = 0; i < length; i++)
		cout << v[i] << ' ';

	cout << "\n";
}

void CopyMatrix(double** src, double** dst, int rows, int columns) {
	for (int i = 0; i < rows; i++)
		memcpy(dst[i], src[i], columns * sizeof(double));
}

void CopyVector(double* src, double* dst, int length) {
	memcpy(dst, src, length * sizeof(double));
}

void Multiply(double** m, int rows, int columns,
	double* v, int length, double* b) {

	for (int i = 0; i < rows; i++) {
		b[i] = 0;

		for (int j = 0; j < columns; j++)
			b[i] += m[i][j] * v[j];
	}
}

void Subtract(double* v1, double* v2, int length, double* result) {
	for (int i = 0; i < length; i++)
		result[i] = v1[i] - v2[i];
}