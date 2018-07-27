#pragma once
#ifndef _MATRIX_H
#define _MATRIX_H

typedef struct
{
	double **mat;
	int row;
	int column;
}Matrix;

int InitialMatrix(Matrix *mat, int row, int column);
void InputMatrix(Matrix *mat);
void InputMatrix(Matrix *matrix, double* arr);
void DestroyMatrix(Matrix *mat);
int MaltiMatrix(Matrix *A, Matrix *B, Matrix *C);
int DotProductMatrix(Matrix *A, Matrix *B, Matrix *C);
void PrintMatrix(Matrix matrix);

#endif // !_MATRIX_H


