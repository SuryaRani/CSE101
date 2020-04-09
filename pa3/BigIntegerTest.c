//-----------------------------------------------------------------------------
// Surya Rani, srani, Pa3
// BigIntegerTest.c
// Test file for BigInteger ADT
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "List.h"
#include "BigInteger.h"

int main()
{
    /*
    BigInteger M = stringToBigInteger("-6523485630758234007488392857982374523487612398700554");
    printBigInteger(stdout, M);
    printf("\n");

    printf("SIGN: %d\n", sign(M));
    printf("\n");

    printf("COPY:\n");
    BigInteger co = copy(M);
    printBigInteger(stdout, co);
    printf("\n");

    printf("EQUALS: %d\n", equals(M, co));
    printf("\n");

    printf("COMPARE EQUAL: %d\n", compare(M, co));
    printf("\n");

    BigInteger bigger = stringToBigInteger("-7523485630758234007488392857982374523487612398700554");
    printf("COMPARE BIGGER: %d\n", compare(bigger, M));
    printf("\n");

    BigInteger A = stringToBigInteger("355797");
    BigInteger B = stringToBigInteger("-149082");
    BigInteger C = sum(A, B);
    printf("THIS IS THE SUM AFter NORMALIZED\n");
    printBigInteger(stdout, C);
    printf("\n");

    BigInteger D = stringToBigInteger("355797");
    BigInteger E = stringToBigInteger("149082");
    BigInteger F = diff(D, E);
    printf("THIS IS THE DIFF AFter NORMALIZED\n");
    printBigInteger(stdout, F);
    printf("\n");


    BigInteger G = stringToBigInteger("-0041085449");
    printBigInteger(stdout,G);
    
    BigInteger H = stringToBigInteger("7402779357");
        printBigInteger(stdout,H);

    BigInteger I = prod(G, H);
    printf("THIS IS THE MULT AFter NORMALIZED\n");
    printBigInteger(stdout, I);
    printf("\n");
    */

    BigInteger J = stringToBigInteger("3322");
    BigInteger K = stringToBigInteger("4433");
    BigInteger L = prod(J,K);
    printf("THIS IS THE MULT OK\n");
    printBigInteger(stdout,L);
        printf("\n");



    /*makeZero(bigger);
    freeBigInteger(&bigger);
    makeZero(co);
    freeBigInteger(&co);
    makeZero(M);
    freeBigInteger(&M);
    */
}
