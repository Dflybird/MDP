#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int InitialMatrix(Matrix *matrix, int row, int column) {
	int i;
	int status = 1;
	matrix->column = column;
	matrix->row = row;

	matrix->mat = (double **)malloc(row * sizeof(double *));
	if (matrix->mat == NULL)
		status = -1;
	else
	{
		for (i = 0; i < row; i++)
		{
			matrix->mat[i] = (double *)malloc(column * sizeof(double));
			if (matrix->mat[i] == NULL)
			{
				status = -1;
				break;
			}
		}
	}

	return status;
}

void InputMatrix(Matrix *matrix, double* arr) {
	int i, j;
	int k = -1;
	for (i = 0; i < matrix->row; i++)
	{
		for (j = 0; j < matrix->column; j++)
		{
			matrix->mat[i][j] = arr[++k];
		}
	}
}

void DestroyMatrix(Matrix *matrix) {
	int i;
	for (i = 0; i < matrix->row; i++)
	{
		free((matrix->mat[i]));
	}
}

int MaltiMatrix(Matrix *A, Matrix *B, Matrix *C) {
	int i, j, k;
	int status = 1;
	if (A->column == B->row)
	{
		int row = A->row;
		int column = B->column;
		/*
		C.row = row;
		C.column = column;
		C.mat = (double **)malloc(row * column * sizeof(double *));
		*/
		if (InitialMatrix(C, row, column) == -1)
			status = -1;

		for (i = 0; i < row; i++)
		{
			for (j = 0; j < column; j++)
			{
				C->mat[i][j] = 0;
			}
		}

		for (i = 0; i < row; i++)
		{
			for (j = 0; j < column; j++)
			{
				for (k = 0; k < A->column; k++)
				{
					C->mat[i][j] += A->mat[i][k] * B->mat[k][j];
				}
			}
		}
	}
	else
	{
		status = -1;
	}

	return status;
}


int DotProductMatrix(Matrix *A, Matrix *B, Matrix *C) {
	int status = 1;
	int i, j;
	if (A->column == B->column && B->row == A->row)
	{
		int row = A->row;
		int column = B->column;
		if (InitialMatrix(C, row, column) == -1)
			status = -1;
		for (i = 0; i < row; i++)
		{
			for (j = 0; j < column; j++)
			{
				C->mat[i][j] = A->mat[i][j] * B->mat[i][j];
			}
		}
	}
	else
		status = -1;
	return status;
}

void PrintMatrix(Matrix matrix) {
	int i, j;
	for (i = 0; i < matrix.row; i++)
	{
		for (j = 0; j < matrix.column; j++)
		{
			printf("%f \t", matrix.mat[i][j]);
		}
		printf("\n");
	}
}