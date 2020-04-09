//-----------------------------------------------------------------------------
//  TestClient.c
//  A test client for the Matrix ADT
//Most commented code is for testing purpose only
//-----------------------------------------------------------------------------
#include<stdio.h>
#include<stdlib.h>
#include"Matrix.h"
#include"List.h"

int main()
{
   Matrix A = newMatrix(10);
    Matrix B = newMatrix(10);
    Matrix C, D;

    printf("\n");
    printf("\n");
    printf("\n");

    printf("********************************\n");
    printf("|                              |\n");
    printf("|  RUNNING ALL THE TEST CASES  |\n");
    printf("|                              |\n");
    printf("********************************\n\n");

    int tp = 0;
//Empty_getSize
    if (size(A) != 10)
    {
        printf("Empty_getSize: Failed\n");
    }
    else
    {
        printf("Empty_getSize: Passed\n");
        tp++;
    }


//NonEmpty_getSize
    changeEntry(A, 1, 1, 4);
    changeEntry(A, 1, 2, 2);
    changeEntry(A, 1, 3, 0);
    changeEntry(A, 2, 1, 2);
    changeEntry(A, 3, 1, 0);
    changeEntry(A, 2, 2, 2);
    changeEntry(A, 3, 3, 0);
    if (size(A) != 10)
    {
        printf("NonEmpty_getSize: Failed\n");
    }
    else
    {
        printf("NonEmpty_getSize: Passed\n");
        tp++;
    }




//Empty_getNNZ
    //freeing the Matrix for the A and B for this case only
    freeMatrix(&A);
    freeMatrix(&B);
    A = newMatrix(10);
    B = newMatrix(10);
    if (NNZ(A) != 0)
    {

        printf("Empty_getNNZ: Failed\n");
    }
    else
    {
        printf("Empty_getNNZ:Passed\n");
        tp++;
    }




//MakeZero_getNNZ
    freeMatrix(&A);
    freeMatrix(&B);
    A = newMatrix(10);
    B = newMatrix(10);

    changeEntry(A, 1, 1, 4);
    changeEntry(A, 1, 2, 2);
    changeEntry(A, 1, 3, 0);
    changeEntry(A, 2, 1, 2);
    changeEntry(A, 3, 1, 0);
    changeEntry(A, 2, 2, 2);
    changeEntry(A, 3, 3, 0);
    makeZero(A);
    if (NNZ(A) != 0)
    {
        printf("MakeZero_getNNZ: Failed\n");
    }
    else
    {
        printf("MakeZero_getNNZ: Passed\n");
        tp++;
    }


//ChangeEntry_getNNZ
    freeMatrix(&A);
    freeMatrix(&B); 
    A = newMatrix(10);
    B = newMatrix(10);
    changeEntry(A, 2, 1, 2);

    changeEntry(A, 3, 1, 5);

    changeEntry(A, 1, 2, 2);

    changeEntry(A, 1, 3, 5);

    changeEntry(A, 1, 1, 4);

    changeEntry(A, 2, 2, 2);

    changeEntry(A, 2, 5, 0);

    changeEntry(A, 2, 3, 0);

    changeEntry(A, 3, 3, 5);
    printMatrix(stderr, A);

    if (NNZ(A) != 7)
    {
        printf("ChangeEntry_getNNZ Failed at NNZ(A) != 7\n");
    }

    changeEntry(A, 1, 3, 0);
    printMatrix(stderr, A);

    printf("%d changed 1 3 0 NNZ\n", NNZ(A));
    changeEntry(A, 3, 1, 0);
    printMatrix(stderr, A);
    printf("%d changed 3 1 0 NNZ\n", NNZ(A));
    printMatrix(stderr, A);
    changeEntry(A, 3, 3, 0); // THIS ONE
    printf("%d changed 3 3 0 NNZ\n", NNZ(A));
    printMatrix(stderr, A);

    if (NNZ(A) != 4)
    {
        printf("%d last NNZ\n", NNZ(A));
        printf("ChangeEntry_getNNZ Failed at NNZ(A) != 4\n");
    }
    changeEntry(A, 7, 6, 42);
    changeEntry(A, 10, 1, 24);
    if (NNZ(A) != 6)
    {
        printf("ChangeEntry_getNNZ Failed at NNZ(A) != 6\n");
    }
    changeEntry(A, 7, 6, 0);
    if (NNZ(A) != 5)
    {
        printf("ChangeEntry_getNNZ Failed at NNZ(A) != 5\n");
    }
    makeZero(A);
    changeEntry(A, 5, 5, 5);
    if (NNZ(A) != 1)
    {
        printf("ChangeEntry_getNNZ Failed at NNZ(A) != 1\n");
    }
    else
    {

        printf("ChangeEntry_getNNZ: Passed\n");
        tp++;

    }


//Copy_getNNZ
    freeMatrix(&A);
    freeMatrix(&B);
    A = newMatrix(10);
    B = newMatrix(10);
    C = copy(A);
    if (NNZ(C) != 0)
    {
        printf("Copy_getNNZ Failed at NNZ(C) != 0\n");
    }
    changeEntry(A, 1, 1, 1);
    if (NNZ(C) != 0)
    {
        printf("Copy_getNNZ Failed at NNZ(C) != 0 2\n");
    }
    D = copy(A);
    if (NNZ(D) != 1)
    {
        printf("Copy_getNNZ Failed at NNZ(D) != 1\n");
    }
    else
    {
        printf("Copy_getNNZ: Passed\n");
        tp++;
    }


//Transpose_getNNZ
    freeMatrix(&A);
    freeMatrix(&B);
    freeMatrix(&C);
    freeMatrix(&D);
    A = newMatrix(10);
    B = newMatrix(10);

    C = transpose(A);
    if (NNZ(C) != 0)
    {
        printf("Transpose_getNNZ Failed at NNZ(C) != 0\n");
    }
    changeEntry(A, 1, 1, 4);
    changeEntry(A, 1, 2, 2);
    changeEntry(A, 1, 3, 0);
    changeEntry(A, 2, 1, 2);
    changeEntry(A, 3, 1, 0);
    changeEntry(A, 2, 2, 2);
    changeEntry(A, 3, 3, 0);
    D = transpose(A);
    if (NNZ(D) != 4)
    {
        printf("Transpose_getNNZ Failed at NNZ(D) != 4\n");
    }
    else
    {
        printf("Transpose_getNNZ: Passed\n");
        tp++;
    }



//Sum_getNNZ
    freeMatrix(&A);
    freeMatrix(&B);
//    freeMatrix(&C);
//    freeMatrix(&D);
    A = newMatrix(10);
    B = newMatrix(10);
    changeEntry(A, 1, 1, 4);
    changeEntry(A, 1, 2, 2);
    changeEntry(A, 1, 3, 0);
    changeEntry(A, 2, 1, 2);
    changeEntry(A, 3, 1, 0);
    changeEntry(A, 2, 2, 2);
    changeEntry(A, 3, 3, 0);


//    printMatrix(stdout,A);

    C = sum(A, A);
    printf("%d\n", NNZ(C));
//
//    printf("\n");
//    printMatrix(stdout,C);
//    printf("%d\n",NNZ(C));
    if (NNZ(C) != 4 || NNZ(A) !=
    4)
    {
        printf("Sum_getNNZ Failed at NNZ(C) != 4 || NNZ(A) != 4\n");
    }
    changeEntry(B, 1, 1, -4);
    changeEntry(B, 1, 2, 0);
    changeEntry(B, 2, 1, 0);
    changeEntry(B, 2, 2, -2);
    changeEntry(B, 2, 4, 2);
    changeEntry(B, 3, 1, 0);
    changeEntry(B, 3, 2, 2);
    changeEntry(B, 7, 8, 5);

    D = sum(A, B);
    printf("%d\n", NNZ(D));
//    printf("\n");
//    printMatrix(stdout,D);
//    printf("%d\n",NNZ(D));

    if (NNZ(D) != 5)
    {
        printf("Sum_getNNZ Failed at NNZ(D) != 5\n");
    }
    else
    {
        printf("Sum_getNNZ: Passed\n");
        tp++;
    }



//Diff_getNNZ
    freeMatrix(&A);
    freeMatrix(&B);
    freeMatrix(&C);
    freeMatrix(&D);
    A = newMatrix(10);
    B = newMatrix(10);
    changeEntry(A, 1, 1, -4);
    changeEntry(A, 1, 2, -2);
    changeEntry(A, 1, 3, 0);
    changeEntry(A, 2, 5, 4);
    changeEntry(A, 2, 1, -2);
    changeEntry(A, 3, 1, 2);
    changeEntry(A, 2, 2, -2);
    changeEntry(A, 3, 3, 0);
    C = diff(A, A);

    if (NNZ(C) != 0 || NNZ(A) != 6)
    {
        printf("Diff_getNNZ Failed at NNZ(C) != 0 || NNZ(A) != 6\n");
    }

    changeEntry(B, 1, 1, -4);
    changeEntry(B, 1, 2, 0);
    changeEntry(B, 2, 1, 0);
    changeEntry(B, 2, 2, -2);
    changeEntry(B, 2, 4, 2);
    changeEntry(B, 3, 1, 2);
    changeEntry(B, 3, 2, 2);
    changeEntry(B, 7, 8, 5);

//    printMatrix(stdout,A);
//    printf("%d\n",NNZ(A));
//    printf("\n");
//
//    printMatrix(stdout,B);
//    printf("%d\n",NNZ(B));
//    printf("\n");
//    printf("\n");
//    printf("\n");

    D = diff(A, B);


//    printf("\n");
//    printf("\n");
//    printMatrix(stdout,D);
//    printf("%d\n",NNZ(D));
//    printf("\n");
    if (NNZ(D) != 6)
    {
        printf("Diff_getNNZ Failed at NNZ(D) != 6\n");
    }
    else
    {
        printf("Diff_getNNZ: Passed\n");
        tp++;
    }


//ScalarMult_getNNZ
    freeMatrix(&A);
    freeMatrix(&B);
    freeMatrix(&C);
    freeMatrix(&D);
    A = newMatrix(10);
    B = newMatrix(10);
    changeEntry(A, 1, 1, 4);
    changeEntry(A, 1, 2, 2);
    changeEntry(A, 1, 3, 0);
    changeEntry(A, 2, 1, 2);
    changeEntry(A, 3, 1, 0);
    changeEntry(A, 2, 2, 2);
    changeEntry(A, 3, 3, 0);
    C = scalarMult(-20, A);
    if (NNZ(C) != 4)
    {
        printf("ScalarMult_getNNZ Failed at NNZ(C) != 4\n");
    }
    makeZero(A);
    D = scalarMult(-20, A);
    if (NNZ(D) != 0)
    {
        printf("ScalarMult_getNNZ Failed at NNZ(C) != 0\n");
    }
    else
    {
        printf("ScalarMult_getNNZ: Passed\n");
        tp++;
    }



//Product_getNNZ
    freeMatrix(&A);
    freeMatrix(&B);
    freeMatrix(&C);
    freeMatrix(&D);
    A = newMatrix(10);
    B = newMatrix(10);

    changeEntry(A, 1, 1, 1);
    changeEntry(A, 2, 2, 1);
    changeEntry(A, 3, 3, 1);
    C = product(A, A);
    if (NNZ(C) != 3)
    {
        printf("Product_getNNZ Failed at NNZ(C) != 3\n");
    }
    changeEntry(A, 1, 1, 1);
    changeEntry(A, 1, 2, 2);
    changeEntry(A, 1, 3, 3);
    changeEntry(A, 2, 1, 4);
    changeEntry(A, 2, 2, 5);
    changeEntry(A, 2, 3, 6);
    changeEntry(A, 3, 1, 7);
    changeEntry(A, 3, 2, 8);
    changeEntry(A, 3, 3, 9);
    changeEntry(B, 1, 1, 1);
    changeEntry(B, 2, 2, 1);



    //D= transpose(A);
    D = product(A, B);

//
//    printf("\n");
//    printf("\n");
//    printMatrix(stdout,D);
//    printf("%d\n",NNZ(D));
//    printf("\n");

    if (NNZ(D) != 6)
    {
        printf("Product_getNNZ Failed at NNZ(D) != 6\n");
    }
    else
    {
        printf("Product_getNNZ Passed\n");
        tp++;
    }


//Empty_equals
    freeMatrix(&A);
    freeMatrix(&B);
    freeMatrix(&C);
    freeMatrix(&D);
    A = newMatrix(10);
    B = newMatrix(10);
    C = newMatrix(15);
    if (!equals(A, B))
    {
        printf("Empty_equals Failed at !equals(A, B)\n");
    }
    if (equals(A, C))
    {
        printf("Empty_equals Failed at equals(A, C)\n");
    }
    D = newMatrix(10);
    changeEntry(D, 5, 5, 5);
    makeZero(D);
    if (!equals(A, D))
    {
        printf("Empty_equals Failed at !equals(A, D)\n");
    }
    else
    {
        printf("Empty_equals: Passed\n");
        tp++;
    }

//NonEmpty_equals
    freeMatrix(&A);
    freeMatrix(&B);
    freeMatrix(&C);
    freeMatrix(&D);
    A = newMatrix(10);
    B = newMatrix(10);
    C = newMatrix(15);
    changeEntry(A, 1, 1, 1);
    changeEntry(C, 1, 1, 1);
    if (equals(A, C))
    {
        printf("NonEmpty_equals Failed at equals(A, C)\n");
    }
    D = newMatrix(15);
    changeEntry(A, 1, 1, 1);
    changeEntry(A, 1, 3, 1);
    changeEntry(B, 1, 1, 1);
    changeEntry(B, 1, 3, 1);
    if (!equals(A, B))
    {
        printf("NonEmpty_equals Failed at !equals(A, B)\n");
    }
    changeEntry(A, 1, 3, 0);
    if (equals(A, B))
    {
        printf("NonEmpty_equals Failed at equals(A, B)\n");
    }
    changeEntry(A, 1, 1, 0);
    makeZero(B);
    changeEntry(A, 10, 10, 10);
    changeEntry(B, 10, 10, 10);
    if (!equals(A, B))
    {
        printf("NonEmpty_equals Failed at !equals(A, B)\n");
    }

    freeMatrix(&A);
    freeMatrix(&B);
    A  = newMatrix(100);
    B  = newMatrix(100);
    int valcount = 1;
    for (int j = 1; j <= 100; j++) {
        for (int k = 1; k <= 100; k++) {
            // hint: this is 1-10000 left-to-right row-by-row
            changeEntry(A, j, k, valcount++);
        }
        changeEntry(B, j, j, 1); // hint: this is the identity matrix
    }
    freeMatrix(&C);
    freeMatrix(&D);
    C = scalarMult(2, A);
    D = sum(A, A);
    if (!equals(C, D))
    {
        printf("NonEmpty_equals Failed at !equals(C, D)\n");
    }

    freeMatrix(&C);
    freeMatrix(&D);
    C = scalarMult(-2, A);
    Matrix As1 = diff(A, A);
    Matrix As2 = diff(As1, A);
    D = diff(As2, A);
    freeMatrix(&As1);
    freeMatrix(&As2);
    if (!equals(C, D))
    {
        printf("NonEmpty_equals Failed at !equals(C, D)2\n");
    }

    freeMatrix(&C);
    C = product(A, B);
    if (!equals(C, A))
    {
        printf("NonEmpty_equals Failed at !equals(C, A)\n");
    }
    else
    {
        printf("NonEmpty_equals: Passed\n");
        tp++;
    }

    freeMatrix(&A);
    freeMatrix(&B);
    freeMatrix(&C);
    freeMatrix(&D);

    printf("\n");
    printf("\n");
    printf("\n");




    if(tp == 13)
    {
        printf("Your Matrix.c File is Working AND PASSED %d/13 test cases SO YAAAAAY you are good to go\n",tp);
    }
    else
    {
        printf("Your Matrix.c File is Not Working.it got %d/13 test cases GO FIX YOUR PROGRAM\n",tp);
    }

    return EXIT_SUCCESS;
}