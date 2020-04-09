//-----------------------------------------------------------------------------
// MatrixTest.c
// Surya Rani 
// srani
// pa2
//-----------------------------------------------------------------------------

#include<stdio.h>
#include<stdlib.h>
#include "Matrix.h"
#include "List.h"
#include "string.h"

int main(){
	Matrix A = newMatrix(3);
	Matrix B = newMatrix(3);
	changeEntry(A,0,1,1.0);
	changeEntry(A,1,1,4.0);
	changeEntry(A,2,1,7.0);
	changeEntry(A,0,2,2.0);
	changeEntry(A,0,3,3.0);
	changeEntry(A,2,2,8.0);
	changeEntry(A,1,2,5.0);
	changeEntry(A,1,3,6.0);
	changeEntry(A,2,3,9.0);

	changeEntry(B,0,1,1.0);
	changeEntry(B,0,3,1.0);
	changeEntry(B,2,1,1.0);
	changeEntry(B,2,2,1.0);
	changeEntry(B,2,3,1.0);


	printf("A has %d non-zero entries:\n",NNZ(A));
	printMatrix(stdout,A);
	printf("\n");

	printf("B has %d non-zero entries:\n",NNZ(B));
	printMatrix(stdout,B);
	printf("\n");

	Matrix mlt = scalarMult(1.5,A);
	printf("1.5 * A = \n");
	printMatrix(stdout,mlt);
	printf("\n");

	Matrix Add = sum(A,B);
	printf("A+B \n");
	printMatrix(stdout,Add);
	printf("\n");

	Matrix sameAdd = sum(A,A);
	printf("A+A =\n");
	printMatrix(stdout,sameAdd);
	printf("\n");

	Matrix Diff = diff(B,A);
	printf("B-A \n");
	printMatrix(stdout,Diff);
	printf("\n");

	Matrix sameDiff = diff(A,A);
	printf("A-A =\n");
	printMatrix(stdout,sameDiff);
	printf("\n");

	Matrix tran = transpose(A);
	printf("Tran A \n");
	printMatrix(stdout,tran);
	printf("\n");

	Matrix pro = product(A,B);
	printf("A*B \n");
	printMatrix(stdout,pro);
	printf("\n");

	Matrix samePro = product(B,B);
	printf("B*B \n");
	printMatrix(stdout,samePro);
	printf("\n");

	//printf("dot: %f",dot(A->lists[0],B->lists[0]));

	/*Matrix M = newMatrix(4);
	printf("Matrix Size: %d\n", size(M));
	printf("Non zero: %d\n", NNZ(M));
	changeEntry(M,0,1,1.2);
	changeEntry(M,1,1,3.4);
	changeEntry(M,0,2,3.7);
	changeEntry(M,0,3,5.6);
	//changeEntry(M,1,3,4.3);
	printf("Non zero: %d\n", NNZ(M));
	printMatrix(stdout,M);

	//changeEntry(M,0,2,2.3);

	Matrix cpy = copy(M);
	//printMatrix(stdout,M);
	printMatrix(stdout,cpy);
	Matrix Mult = scalarMult(2.0,M);
	printMatrix(stdout,Mult);
	changeEntry(Mult,1,3,2.8);
	Matrix Add = sum(M,Mult);
	printMatrix(stdout,Add);
	*/
}