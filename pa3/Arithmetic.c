//-----------------------------------------------------------------------------
// Surya Rani, srani, Pa3
// Arithmetic.c
// Implementation file for client module Arithmetic
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "List.h"
#include "BigInteger.h"

int main(int argc, char* argv[]){
	if(argc!=3){
		fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
		exit(1);
	}
    //printf("asdf bro\n");

    FILE *in = fopen(argv[1],"r");
	FILE *out = fopen(argv[2],"w");


    
    int aLen;
    int bLen;

    fscanf(in,"%d",&aLen);
    aLen = aLen+2;
    char Astring[aLen];

    fscanf(in,"%s",Astring);
    printf("DIS IS ASTRNIG %s\n",Astring);

     fscanf(in,"%d",&bLen);
    bLen = bLen+3;
    char Bstring[bLen];
       fscanf(in,"%s",Bstring);

    BigInteger A = stringToBigInteger(Astring);
    BigInteger B = stringToBigInteger(Bstring);
    
    
    // PRINT OUT A 
    printBigInteger(out,A);
    fprintf(out,"\n");
    fprintf(out,"\n");
   

    // PRINT OUT B
    printBigInteger(out,B);
    fprintf(out,"\n");
    fprintf(out,"\n");



    //PRINT OUT THE SUMS OF A AND B
    BigInteger added = sum(A,B);
    printBigInteger(out,added);
    fprintf(out,"\n");
    fprintf(out,"\n");
    
    
    //PRINT OUT A-B
    BigInteger difference = diff(A,B);
    printBigInteger(out,difference);
    fprintf(out,"\n");
    fprintf(out,"\n");

    //PRINT OUT A-A
    BigInteger sameDiff = diff(A,A);
    printBigInteger(out,sameDiff);
    fprintf(out,"\n");
    fprintf(out,"\n");
    

   
    //PRINT OUT 3A-2B
    BigInteger sameAdd = sum(A,A);
    BigInteger sameAdd2 = sum(sameAdd,A);
    BigInteger sameAdd3 = sum(B,B);
    BigInteger AminusB = diff(sameAdd2,sameAdd3);
    printBigInteger(out,AminusB);
    fprintf(out,"\n");
    fprintf(out,"\n");

   
    //PRINTS OUT A * B
    BigInteger multAB = prod(A,B);
    printBigInteger(out,multAB);
    printBigInteger(out, prod(A, B));
    fprintf(out,"\n");
    fprintf(out,"\n");
   

     //PRINTS OUT A * A
    BigInteger multAA = prod(A,A);
    printBigInteger(out,multAA);
    fprintf(out,"\n");
    fprintf(out,"\n");
    
   
   
    //PRINTS OUT B * B
    BigInteger multBBB = prod(B,B);
    printBigInteger(out,multBBB);
    fprintf(out,"\n");
    fprintf(out,"\n");

    
    BigInteger A2= prod(A,A);
    BigInteger A3 = prod(A2,A);
    BigInteger A4 = prod(A3,A);
    BigInteger B2= prod(B,B);
    BigInteger B3 = prod(B2,B);
    BigInteger B4 = prod(B3,B);
    BigInteger B5 = prod(B4,B);
    BigInteger A9 = stringToBigInteger("9");
    BigInteger A94 = prod(A9,A4);
    BigInteger B16 = stringToBigInteger("16");
    BigInteger B165 = prod(B16,B5);
    BigInteger last = sum(A94,B165);
    printBigInteger(out,last);
    fprintf(out,"\n");
    fprintf(out,"\n");

    
    








    fclose(in);
    fclose(out);

}
