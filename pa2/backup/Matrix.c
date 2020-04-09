//-----------------------------------------------------------------------------
// Matrix.c
// Surya Rani 
// srani
// pa2
//-----------------------------------------------------------------------------
#include<stdio.h>
#include<stdlib.h>
#include "List.h"
#include "Matrix.h"

typedef struct EntryObj{
	int column;
	double value;
} EntryObj;

typedef EntryObj* Entry;

Entry newEntry(int colNum, double val){
	Entry E = malloc(sizeof(EntryObj));
	E->column = colNum;
	E->value = val;
	return E;
}

void freeEntry(Entry *pE){
	if(pE!=NULL && *pE!=NULL){
		free(*pE);
		pE = NULL;
	}
}

typedef struct MatrixObj{
	List *lists;
	int size;
	int nnz;
} MatrixObj; 


typedef MatrixObj* Matrix;


// newMatrix()
// Returns a reference to a new nXn Matrix object in the zero state. 
Matrix newMatrix(int n){
	Matrix M = malloc(sizeof(MatrixObj));
	M->lists = (List*)malloc(sizeof(List)*(n+1));
	for(int i =0; i<n; i++){
		M->lists[i] = newList();
	}
	M->size = n;
	M->nnz = 0;
	return M;
}
// freeMatrix()
// Frees heap memory associated with *pM, sets *pM to NULL. 
void freeMatrix(Matrix* pM){
	if(pM!=NULL && *pM!=NULL){
		free(*pM);
		pM = NULL;
	}
}
// Access functions
// size()
// Return the size of square Matrix M.
int size(Matrix M){
	return M->size;
}
// NNZ()
// Return the number of non-zero elements in M.
int NNZ(Matrix M){
	return M->nnz;
}
// equals()
// Return true (1) if matrices A and B are equal, false (0) otherwise. 
int equals(Matrix A, Matrix B){
	//int equals;
	if(A== NULL && B == NULL){
		printf("Matrix Error: calling equals() on a NULL List\n");
		exit(1);
	}
	if(A==B){
		return 1;
	}
	if(size(A)!=size(B) || NNZ(A)!=NNZ(B)){
		return 0;
	}

	for(int i = 0; i<size(A);i++){
		List lA = A->lists[i];
		moveFront(lA);
		List lB = B->lists[i];
		moveFront(lB);
		if(length(lA) != length(lB)){
			return 0;
		}
		while(index(lA) != -1 && index(lA) != -1){
			Entry eA = get(lA);
			Entry eB = get(lB);

			if(eA->value != eB->value){
				return 0;
			}
			else{
				moveNext(lA);
				moveNext(lB);
			}
		}

	}
	return 1;
	}	


	/*if(A == B){
		return 1;
	}
	if(size(A) == 0 && size(B)==0){
		return 1;
	}
	if(size(A) == size(B)){
		if(NNZ(A) == NNZ(B)){
			moveBack(A->lists[d]);
			moveBack(B->lists[d]);
			Entry eA;
			Entry eB;
			

			if(index(A->lists[d])!=-1 && index(B->lists[d])!=-1){
				eA = get(A->lists[d]);
				eB = get(B->lists[d]);
				if(eA->column == eB->column && eA->value == eB->value){
							return 1;
						}
			}
			for(int d =0; d<size(A);d++){
				
				*/
				/*if(length(A->lists[d]) == length(A->lists[d])){
					if(index(A->lists[d])!=-1 && index(B->lists[d])!=-1){
						eA = get(A->lists[d]);
						eB = get(B->lists[d]);
						if(eA->column == eB->column && eA->value == eB->value){
							return 1;
						}
					}
				}*/
			//}
		//}
		//return 0;
//	}*/

	

	/*int equals=0;
	Entry a;
	Entry b;
	if( A == B){
		return 1;
	}
	if(size(A)==0 && size(B)==0){
		return 1;
	}
	for(int d=0; d<size(A);d++){
		if(length(A->lists[d])==length(A->lists[d])){
			equals = 1;
		}
		else{
			return 0;
		}
	}

	if (size(A) == size(B) && NNZ(A) == NNZ(B)){ 
		for(int i =0; i<size(A);i++){
			moveFront(A->lists[i]);
			moveFront(B->lists[i]);

			if(index(A->lists[i])!= -1 && length(A->lists[i])!=0){
				if(index(B->lists[i])!= -1 && length(B->lists[i])!=0){

					a = get(A->lists[i]);
					b = get(B->lists[i]);
					if(a->column == b->column && a->value == b->value){
						equals = 1;
						moveNext(A->lists[i]);
						moveNext(B->lists[i]);
					}
					else{
						return 0; 
					}
				}
				else{
					return 0; 
				}
			}
		}
	}
	else{
		return 0;
	}

	return equals;
	*/

// Manipulation procedures

// makeZero()
// Re-sets M to the zero Matrix.
void makeZero(Matrix M){
	for(int i=0;i<M->size;i++){
		clear(M->lists[i]);
	}
	M->size =0;
	M->nnz = 0;
}
// changeEntry()
// Changes the ith row, jth column of M to the value x.
// Pre: 1<=i<=size(M), 1<=j<=size(M)
void changeEntry(Matrix M, int i, int j, double x){
	if(!(size(M)>=i) && !(i>=1)){
		printf("Matrix Error: calling changeEntry() on an empty List\n");
		exit(1);
	}
	if(!(size(M)>=j) && !(j>=1)){
		printf("Matrix Error: calling changeEntry() on an empty List\n");
		exit(1);
	}

	Entry new = newEntry(j,x);
	List L = M->lists[i];
	moveFront(L);
	Entry e = NULL;

	if(length(L) == 0){
		if(x!=0.0){
			append(L,new);
			M->nnz++;
		}
		return;
	}

	if(index(L)!=-1){
		e = get(L);
	}
	while(index(L)!=-1){
		if(e->column > j){
			insertBefore(L,new);
			M->nnz++;
			return;
		}
		else if(e->column == j){
			break;
		}
		else{
			moveNext(L);
		}
	}

	if(x==0.0){
		if(index(L)==-1){

		}
		else{
			freeEntry(&new);
			freeEntry(&e);
			delete(L);
			M->nnz--;
		}
	}
	else{
		if(index(L)==-1){
			append(L,new);
			M->nnz++;

		}
		else{
			insertBefore(L,new);
			freeEntry(&e);
			delete(L);
		}
	}

	/*Entry new = newEntry(j,x);
	moveFront(M->lists[i]);


	for(int k=0; k<j;k++){
		if(k ==(j-1)){

		}
		else{
			moveNext(M->lists[i]);
		}
	}




	Entry ent;
	int n =0;
	if(length(M->lists[i])!=0 && index(M->lists[i])!=-1){
		ent = get(M->lists[i]);
		while(n<size(M)){
			if(n!=j){
				n = ent->column;
				moveNext(M->lists[i]);
			}
			else{

			}
		}
	}
	else{
		ent =NULL;
	}
	if(x==0.0){
		freeEntry(&new);
		if(ent==NULL){

		}
		else{
			freeEntry(&ent);
			delete(M->lists[i]);
			M->nnz--;
		}
	}
	else{
		if(ent==NULL){
			append(M->lists[i],new);
			M->nnz++;

		}
		else{
			insertBefore(M->lists[i],new);
			freeEntry(&ent);
			delete(M->lists[i]);
			M->nnz++;

		}
	} */
}

	


// Matrix Arithmetic operations
// copy()
// Returns a reference
Matrix copy(Matrix A){
	Matrix cop= newMatrix(size(A));
	for(int k =0; k<size(A);k++){
		moveFront(A->lists[k]);
		while(index(A->lists[k])!= -1 && length(A->lists[k])!=0){
			Entry e = get(A->lists[k]);
			int c = e->column;
			double v = e->value;
			changeEntry(cop,k,c,v);
			moveNext(A->lists[k]);
		}
	}
	
	return cop;
}
// transpose()
// Returns a reference
// of A.
Matrix transpose(Matrix  A){
	Matrix trans = newMatrix(size(A));
	Entry swtch;
	for(int k =0; k<size(A);k++){
		if(length(A->lists[k])!=0){
			moveFront(A->lists[k]);
			for(int j =0; j<length(A->lists[k]);j++){
				if(index(A->lists[k])!= -1 && length(A->lists[k])!=0){
					swtch = get(A->lists[k]);
				}

				changeEntry(trans,swtch->column-1,k+1,swtch->value);
				moveNext(A->lists[k]);
			}

		}

		
	}
	return trans;
												//I NEED TO BE ABLE TO LOOP THROUGH THE LISTS ONE LESS TIME EACH TIME BECAUSE IT WILL HAVE ALREADY BEEN SWITCHED
	                                            // JUST USE THE INTEGER IN THE LOOP I THNK SINCE EACH TME IT WILL START AT 1 1 2 2 3 3 and so on I think u got it

													//HOW DO I ACCOUNT FOR ZERO ENTRIES DO I SWITCH IT SO IT WOULD MAKE ITS TRANSPOSE A ZERO MATRIX

}
// scalarMult()
// Returns a reference to a new
Matrix scalarMult(double x, Matrix A){
	Matrix mult = newMatrix(size(A));
	for(int k =0; k<size(A);k++){
		moveFront(A->lists[k]);
		while(index(A->lists[k])!= -1 && length(A->lists[k])!=0){
			Entry e = get(A->lists[k]);
			int c = e->column;
			double newVal = e->value;
			newVal = newVal *x;
			changeEntry(mult,k,c,newVal);
			moveNext(A->lists[k]);
		}
	}
	return mult;
}
// sum()
// Returns a reference to a new
// pre: size(A)==size(B)
Matrix sum(Matrix A, Matrix B){
	if(size(A)!=size(B)){
		printf("Matrix Error: calling sum() on different sized matrices.");
		exit(1);
	}

	if(A == B){
		B = copy(B);
	}
	Matrix add = newMatrix(size(A));
	int NN;
	for(int k =0;k<size(A);k++){
		moveFront(A->lists[k]);
		moveFront(B->lists[k]);
		double both;
		Entry eA;
		Entry eB;
		int aLen = length(A->lists[k]);
		int bLen = length(B->lists[k]);
		int longer;
		

		if(aLen >= bLen){
			longer = aLen;
			NN +=aLen;
		}
		else{
			longer = bLen;
			NN+= bLen;
		}

		for(int u =0; u<longer;u++){
			if(index(A->lists[k])!= -1 && length(A->lists[k])!=0){
				eA = get(A->lists[k]);
			}
			else{
				eA = NULL;
			}
			if(index(B->lists[k])!= -1 && length(B->lists[k])!=0){
				eB = get(B->lists[k]);
			}
			else{
				eB = NULL;
			}

			if(eA!=NULL && eB!=NULL){
				if(eA->column > eB->column){
					changeEntry(add,k,eB->column,eB->value);
					moveNext(B->lists[k]);
				}
				else if(eB->column > eA->column){
					changeEntry(add,k,eA->column,eA->value);
					moveNext(A->lists[k]);
				}
				else{
					both = eA->value + eB->value;
					changeEntry(add,k,eA->column,both);
					moveNext(A->lists[k]);
					moveNext(B->lists[k]);
				}
			}
			else if(eA!=NULL && eB==NULL){
				changeEntry(add,k,eA->column,eA->value);
				moveNext(A->lists[k]);
			}
			else if(eA==NULL && eB!=NULL){
				changeEntry(add,k,eB->column,eB->value);
				moveNext(B->lists[k]);
			}

			
		}
	}
	/*add->nnz =0;
	for(int r = 0;r<size(A);r++){
		if(length(A->lists[r])<length(B->lists[r])){
		add->nnz+=length(B->lists[r]);		
		}
		if(length(A->lists[r])>length(B->lists[r])){
		add->nnz+=length(A->lists[r]);		
		}
	}*/
	add->nnz = NN;
	return add;
}
// diff()
// Returns a reference to a new
// pre: size(A)==size(B)
Matrix diff(Matrix A, Matrix B){
	if(size(A)!=size(B)){
		printf("Matrix Error: calling diff() on different sized matrices.");
		exit(1);
	}
	if(A == B){
		B = copy(B);
	}
	Matrix sub = newMatrix(size(A));
	for(int k =0;k<size(A);k++){
		moveFront(A->lists[k]);
		moveFront(B->lists[k]);
		double both;
		Entry eA;
		Entry eB;
		int aLen = length(A->lists[k]);
		int bLen = length(B->lists[k]);
		int longer;

		if(aLen >= bLen){
			longer = aLen;
		}
		else{
			longer = bLen;
		}

		for(int u =0; u<longer;u++){
			if(index(A->lists[k])!= -1 && length(A->lists[k])!=0){
				eA = get(A->lists[k]);
			}
			else{
				eA = NULL;
			}
			if(index(B->lists[k])!= -1 && length(B->lists[k])!=0){
				eB = get(B->lists[k]);
			}
			else{
				eB = NULL;
			}

			if(eA!=NULL && eB!=NULL){
				if(eA->column > eB->column){
					double neg = eB->value;
					neg = neg - 2.0*neg;
					changeEntry(sub,k,eB->column,neg);
					moveNext(B->lists[k]);
				}
				else if(eB->column > eA->column){
					
					moveNext(A->lists[k]);
					changeEntry(sub,k,eA->column,eA->value);
				}
				else{
					both = eA->value - eB->value;
					moveNext(A->lists[k]);
					moveNext(B->lists[k]);
					changeEntry(sub,k,eA->column,both);
				}
			}
			else if(eA!=NULL && eB==NULL){
				moveNext(A->lists[k]);
				changeEntry(sub,k,eA->column,eA->value);
				
			}
			else if(eA==NULL && eB!=NULL){
				double neg = eB->value;
				neg = neg - 2.0*neg;
				moveNext(B->lists[k]);
				changeEntry(sub,k,eB->column,neg);
				
			}

			
		}
	}
	return sub;
}

double dot(List A, List B, int matSize){
	double dotProd;
	moveFront(A);
	moveFront(B);
	Entry a;
	Entry b;

	while(index(A)!=-1 && index(B)!=-1){
		if(index(A)!= -1 && length(A)!=0){
			a = get(A);

		}
		if(index(B)!= -1 && length(B)!=0){
			b = get(B);
		}
		if(a->column == b->column){
		dotProd += a->value * b->value;
		moveNext(A);
		moveNext(B);
		}
		else if(a->column > b->column){
			moveNext(B);
		}
		else{
			moveNext(A);
		}
	}
	return dotProd;
}
// product()
// Returns a reference to a new Matrix
// pre: size(A)==size(B)
Matrix product(Matrix A, Matrix B){
	if(size(A)!=size(B)){
		printf("Matrix Error: calling product() on different sized matrices.");
		exit(1);
	}
	
	if(A==B){
		A = copy(B);
	}

	Matrix prod = newMatrix(size(A));
	Matrix transp = transpose(B);
	for(int k =0; k<size(A);k++){
			for(int h =0; h<size(A); h++){
				double dt = dot(A->lists[k],transp->lists[h],size(A));
				if(dt<=0.000000001){

				}
				else{   
		            // I THINK THIIS IS ONLY WORKING BECAUSE THE LENGTH OF THE LIST IS THE SAME AS THR SIZE OF MATRIX 
					changeEntry(prod,k,h+1,dt);
				}                                  // MAYBE ADD ANOTHER LOOP TO BE ANLE TO LOOP THROUGH ALL OF THE SECOND MATRIX 
			}
	}
	freeMatrix(&transp);
	return prod; 
}



// printMatrix()
// Prints a string representation of Matrix M to filestream out. Zero rows // are not printed. Each non-zero is represented as one line consisting // of the row number, followed by a colon, a space, then a space separated // list of pairs "(col, val)" giving the column numbers and non-zero values // in that row. The double val will be rounded to 1 decimal point.
void printMatrix(FILE* out, Matrix M){
	for(int i =0; i<M->size;i++){
		moveFront(M->lists[i]);
		if(length(M->lists[i])!=0){
			fprintf(out,"%d: ",i+1);
		}
		while(index(M->lists[i])!= -1 && length(M->lists[i])!=0){
				Entry e = get(M->lists[i]);
				if(index(M->lists[i])==0){

				}
				else{
					fprintf(out," ");
				}
				fprintf(out,"(%d, %.1f)", e->column,e->value);
				moveNext(M->lists[i]);
		}
		if(length(M->lists[i])!=0){
		fprintf(out,"\n");
		}
	}

}