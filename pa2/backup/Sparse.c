//-----------------------------------------------------------------------------
// Sparse.c
// Surya Rani 
// srani
// pa2
//-----------------------------------------------------------------------------

#include<stdio.h>
#include<stdlib.h>
#include "string.h"
#include "Matrix.h"

int main(int argc, char* argv[]){
	if(argc!=3){
		fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
		exit(1);
	}

	FILE *in = fopen(argv[1],"r");
	FILE *out = fopen(argv[2],"w");
	int matrixSize=0;
	//char c;
	int aSize=0;
	int bSize=0;
	int row;
	int col;
	double value;


	fscanf(in,"%d",&matrixSize);
	fscanf(in,"%d",&aSize);
	fscanf(in,"%d",&bSize);



	Matrix A = newMatrix(matrixSize);
	Matrix B = newMatrix(matrixSize);

	int z=0;
	while(fscanf(in, "%d %d %lf", &row, &col, &value) != EOF && z<aSize-1){
		changeEntry(A,row-1,col,value);	
		z++;
	}
	changeEntry(A,row-1,col,value);	



	int d=0;
	//fscanf(in, "%d %d %lf", &row, &col, &value);
	//changeEntry(B,row-1,col,value);	

	while(fscanf(in, "%d %d %lf", &row, &col, &value) != EOF && d<bSize){
		changeEntry(B,row-1,col,value);	
		d++;
	}

	fprintf(out,"A has %d non-zero entries:\n",NNZ(A));
	printMatrix(out,A);
	fprintf(out,"\n");

	fprintf(out,"B has %d non-zero entries:\n",NNZ(B));
	printMatrix(out,B);
	fprintf(out,"\n");

	Matrix mlt = scalarMult(1.5,A);
	fprintf(out,"(1.5)*A =\n");
	printMatrix(out,mlt);
	fprintf(out,"\n");


	Matrix Add = sum(A,B);
	//fprintf(out,"Add has %d non-zero entries:\n",NNZ(Add));
	fprintf(out,"A+B =\n");
	printMatrix(out,Add);
	fprintf(out,"\n");


	Matrix sameAdd = sum(A,A);
	fprintf(out,"A+A =\n");
	printMatrix(out,sameAdd);
	fprintf(out,"\n");
	
	Matrix Diff = diff(B,A);
	//fprintf(out,"Diff has %d non-zero entries:\n",NNZ(Diff));
	fprintf(out,"B-A =\n");
	printMatrix(out,Diff);
	fprintf(out,"\n");

	Matrix sameDiff = diff(A,A);
	fprintf(out,"A-A =\n");
	printMatrix(out,sameDiff);
	fprintf(out,"\n");


	Matrix tran = transpose(A);
	fprintf(out,"Transpose(A) =\n");
	printMatrix(out,tran);
	fprintf(out,"\n");

	Matrix pro = product(A,B);
	fprintf(out,"A*B =\n");
	printMatrix(out,pro);
	fprintf(out,"\n");

	Matrix samePro = product(B,B);
	fprintf(out,"B*B =\n");
	printMatrix(out,samePro);
	fprintf(out,"\n");

	freeMatrix(&mlt);
	freeMatrix(&Add);
	freeMatrix(&sameAdd);
	freeMatrix(&Diff);
	freeMatrix(&sameDiff);
	freeMatrix(&tran);
	freeMatrix(&pro);
	freeMatrix(&samePro);

	fclose(in);
	fclose(out);

}




