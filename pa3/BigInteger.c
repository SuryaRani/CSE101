//-----------------------------------------------------------------------------
// Surya Rani, srani, Pa3
// BigInteger.c
// Implementation file for BigInteger ADT
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "List.h"
#include "BigInteger.h"
#include <string.h>
#include <math.h>

#define POWER 9
#define BASE (int)pow(10, POWER)

typedef struct BigIntegerObj
{
    int sign;
    List list;
} BigIntegerObj;

typedef BigIntegerObj *BigInteger;

BigInteger newBigInteger()
{
    BigInteger B;
    B = malloc(sizeof(BigIntegerObj));
    B->sign = 0;
    B->list = newList();

    return B;
}

void freeBigInteger(BigInteger *pB)
{
    if (pB != NULL && *pB != NULL)
    {
        free(*pB);
        *pB = NULL;
    }
}

// sign()
// Returns -1 if N is negative, 1 if N is positive, and 0 if N is in the zero // state.
int sign(BigInteger N)
{
    return N->sign;
}
// compare()
// Returns -1 if A<B, 1 if A>B, and 0 if A=B.
int compare(BigInteger A, BigInteger B)
{
    if (A->sign > B->sign)
    {
        return 1;
    }
    if (A->sign < B->sign)
    {
        return -1;
    }
    if (A->sign == 0 && B->sign == 0)
    {
        return 0;
    }

    if (listEquals(A->list, B->list))
    {
        return 0;
    }
    moveFront(A->list);
    moveFront(B->list);
    if (A->sign == -1 && B->sign == -1)
    {
        while (index(A->list) != -1 && index(B->list) != -1)
        {
            if (get(A->list) > get(B->list))
            {
                return -1;
            }
            else if (get(B->list) > get(A->list))
            {
                return 1;
            }
            moveNext(A->list);
            moveNext(B->list);
        }
    }
    else
    {
        while (index(A->list) != -1 && index(B->list) != -1)
        {
            if (get(A->list) > get(B->list))
            {
                return 1;
            }
            else if (get(B->list) > get(A->list))
            {
                return -1;
            }
            moveNext(A->list);
            moveNext(B->list);
        }
    }
    return 0;
}
// equals()
// Return true (1) if A and B are equal, false (0) otherwise.
int equals(BigInteger A, BigInteger B)
{
    if (A->sign == B->sign)
    {
        if (listEquals(A->list, B->list))
        {
            return 1;
        }
    }
    return 0;
}

// Manipulation procedures ----------------------------------------------------
// makeZero()
// Re-sets N to the zero state.
void makeZero(BigInteger N)
{
    N->sign = 0;
    clear(N->list);
}
// negate()
// Reverses the sign of N: positive <--> negative. Does nothing if N is in the // zero state.
void negate(BigInteger N)
{
    if (N->sign == -1)
    {
        N->sign = 1;
    }
    else if (N->sign == 1)
    {
        N->sign = -1;
    }
}
// BigInteger Arithmetic operations -----------------------------------------------
// stringToBigInteger()
// Returns a reference to a new BigInteger // represented in base 10 by the string s. // Pre: s is a non-empty string containing // and an optional sign {+, -} prefix.
BigInteger stringToBigInteger(char *s)
{
    BigInteger B = newBigInteger();

    if (s[0] == '\0')
    {
        printf("BigInteger Error: calling stringToBigInteger() on an empty String\n");
        exit(1);
    }

    int end = 0;
    if (s[0] == '+')
    {
        end = 1;
        B->sign = 1;
    }
    else if (s[0] == '-')
    {
        B->sign = -1;
        end = 1;
    }
    else
    {
        B->sign = 1;
    }

    int x = strlen(s) - 1;
    char num[POWER];
    int mod = (x + 1 - end) % POWER;
    int counter = 0;
    long insert;
    char *ptr;
    //FIGURE OUT HOW TF TO ADD LEADING ZEROES BUT OTHER THAN THAT THIS IS PERFECT
    char smallBoy[mod - 1];
    while (counter < mod && mod != 0)
    {
        smallBoy[counter] = s[end];
        end++;
        counter++;
    }
    if (mod != 0)
    {
        insert = strtol(smallBoy, &ptr, 10);
        append(B->list, insert);
    }

    counter = 0;

    while (end <= x)
    {
        char *pt;
        while (counter < POWER)
        {
            num[counter] = s[end];
            printf("EACH NUMBER: %c\n",num[counter]);
            counter++;
            end++;
        }
        insert = strtol(num, &pt, 10);
         printf("TBH WHATS HATTNING HERE: %ld\n",insert);
        append(B->list, insert);

        counter = 0;
    }
    return B;
}
// copy()
// Returns a reference to a new BigInteger
BigInteger copy(BigInteger N)
{
    BigInteger cop = newBigInteger();
    cop->sign = N->sign;
    cop->list = copyList(N->list);
    return cop;
}

List normalize(List C)
{
    List norm = newList();
    moveBack(C);
    long carry = 0;
    long numb = 0; 
    long bigBoy = 0;
    long numDiv;
    while (index(C) != -1)
    {
        if (get(C) > (BASE))
        {
            

            if(index(C) == length(C)-1){
            carry = get(C)/BASE;
            //printf("carry1: %ld\n",carry);
            //carry++;
            bigBoy = carry * BASE;
            numb = (get(C) - bigBoy);
            //printf("NUMB1: %ld\n",numb);
            //carry++;
            set(C,numb);
            }
            else if (index(C) != length(C)-1){
                        
                numDiv = (get(C)+carry)/BASE;
                bigBoy = numDiv *BASE;

            numb = ((get(C)+carry)-bigBoy);
                        //printf("NUMB2: %ld\n",numb);

            carry = (get(C)+carry)/BASE;           
            set(C,numb);
            }
        
           
            prepend(norm, numb);
        }
        else if (get(C) < 0)
        {
            if(index(C) == length(C)-1){
                carry = (-1*get(C))/BASE;
                carry++;
            bigBoy = carry * BASE;
            
            numb = (get(C) +bigBoy);
            set(C,numb);
            }
            else if (index(C) != length(C)-1){
                numDiv = -1*(get(C)-carry)/BASE;
                numDiv++;
                bigBoy = numDiv *BASE;
                numb = ((get(C)-carry)+bigBoy);
                carry = -1*(numDiv);
                set(C,numb);
            }
            prepend(norm, numb);
        }
        else
        {
            numb = get(C) + carry;
            prepend(norm, numb);
            carry = 0;
        }

        movePrev(C);
    }
    if (carry >0)
    {
        prepend(norm, carry);

    }
    return norm;
}

//object representing the decimal integer only base ten digits {0,1,2,3,4,5,6,7,8,9}
//object in the same state as N.
// add()
// Places the sum of A and B in the existing BigInteger S, overwriting its // current state: S = A + B
void add(BigInteger S, BigInteger A, BigInteger B)
{
    if(A==S){
        A = copy(S);
    }
    if(B==S){
        B = copy(S);
    }
    if(A==B){
        A = copy(B);
    }

   //freeBigInteger(&S);
    BigInteger E = sum(A,B);
    S ->sign = E->sign;
    S->list = E->list;
}
// sum()
// Returns a reference to a new BigInteger object representing A + B.

//TEST THIS MORE U BETTER TEST IT TMRW BUT FOR NOW GOOD JOB MAN U DID HELLA WORK AND GO REST
BigInteger sum(BigInteger A, BigInteger B)
{
    if(A==B){
        B=copy(A);
    }
    BigInteger C = newBigInteger();
    List aL = A->list;
    List bL = B->list;
    List cL = C->list;


    moveBack(aL);
    moveBack(bL);
    long aSum;
    long bSum;
    long cSum;
    //IF IT STARTS FUCKING UP MAKE THIS BACK TO ONE WHILE LOOP CHECKING BOTH A AND B
    while (index(aL) != -1 || index(bL) != -1)
    {
        if(index(aL)!=-1){
            if (A->sign == -1)
            {
                aSum = -1 * get(aL);
            }
            else
            {
                aSum = get(aL);
            }
        }
        else{
            aSum = 0;
        }
        //printf("ASUM: %ld\n",aSum);
    
   // while(index(bL) != -1){
       if(index(bL)!=-1){
            if (B->sign == -1)
            {
                bSum = -1 * get(bL); 
            }
            else
            {
                bSum = get(bL);
            }
       }
       else{
           bSum =0;
       }
             //printf("BSUM: %ld\n",bSum);

   // }
   // while(index(aL)!=-1 || index(bL)!=-1){
        //DELETE THIS SECTION IF IT STARTS FUCKING UP
        if(index(aL) == -1 && index(bL)!=-1){
            aSum = 0;
        }
         if(index(bL) == -1 && index(aL)!=-1){
            bSum = 0;
        }
        cSum = aSum + bSum;
                //printf("CSUM: %ld\n",cSum);

        prepend(cL, cSum);

        movePrev(aL);
        movePrev(bL);
    }
    // This is to check if the leading number is negative then we have flip the signs for each number then renormalize it
    List cc = C->list;

    moveFront(cc);
    if (index(cc) != -1)
    {
        if(get(cc) == 0){
            deleteFront(cc);
        }
        moveFront(cc);
        if (get(cc) < 0)
        {
            C->sign = -1;

            while (index(cc) != -1)
            {
                int switchup = -1 * get(cc);
                //im pretty sure my set is fucking up fix this
                set(cc, switchup);

                moveNext(cc);
            }
           
            C->list = normalize(cc);
        }
        else{
            C->list = normalize(cL);
            C->sign = 1;
        }
    }

    
    return C;
}
// subtract()
// Places the difference of A and B in the existing BigInteger D, overwriting //itscurrentstate: D=A-B
void subtract(BigInteger D, BigInteger A, BigInteger B)
{
    if(A==D){
        A = copy(D);
    }
    if(B==D){
        B = copy(D);
    }
    if(A==B){
        A = copy(B);
    }

    //freeBigInteger(&D);
     BigInteger E = diff(A,B);
    D->sign = E->sign;
    D->list = E->list;
}
// diff()
// Returns a reference to a new BigInteger object representing A - B.
BigInteger diff(BigInteger A, BigInteger B)
{
    if(A==B){
        B = copy(A);
    }
    BigInteger dif = newBigInteger();
    negate(B);

    dif = sum(A,B);

    negate(B);


    return dif;
}
// multiply()
// Places the product of A and B in the existing BigInteger P, overwriting // its current state: P = A*B
void multiply(BigInteger P, BigInteger A, BigInteger B)
{
    if(A==P){
        A = copy(P);
    }
    if(B==P){
        B=copy(P);
    }
    if(A==B){
        A = copy(B);
    }
    BigInteger p = prod(A,B);
    P->sign = p->sign;
    p->list = p->list;

}
// prod()
// Returns a reference to a new BigInteger object representing A*B
BigInteger prod(BigInteger A, BigInteger B)
{
    if(A ==B){
        B= copy(A);
    }
    if(B==A){
        A = copy(B);
    }
    
    BigInteger place = newBigInteger();
    BigInteger mlt = newBigInteger();
    place->sign = A->sign * B->sign;

    List Al = A->list;
    List Bl = B->list;
    //List placeList = place->list;
    //List mltList = mlt->list;
    moveBack(Al);
    moveBack(Bl);

    long insert = 0;
    int counter = 0;
    while(index(Bl)!=-1){

        while(index(Al)!=-1){
            insert = get(Al) * get(Bl);
            prepend(place->list,insert);

            movePrev(Al);
        }

        moveBack(Al);
        counter++;
        // IM LIKE 70 PERCENT SURE I LOSE MEMORY RIGHT HERE CUZ WHERE DOES THE PREV LIST GO HUH 
        //List pTrash = place->list;
        place->list = normalize(place->list);

        //clear(pTrash);


    if(length(mlt->list) == 0){
         mlt = copy(place);

    }
    else{
         moveBack(place->list);
         moveBack(mlt->list);
         long num =0;
        while(index(place->list)!=-1){
            if(index(mlt->list) ==-1){
                prepend(mlt->list,get(place->list));

            }
            else{
                num = get(mlt->list) + get(place->list);
                set(mlt->list,num);
            
            }
            
            movePrev(mlt->list);
            movePrev(place->list);
            
        }
        mlt->list = normalize(mlt->list);

    }
   
    clear(place->list);

    for(int i=0;i<counter;i++){
        prepend(place->list,0);

    }
    movePrev(Bl);

    //printf("GET OF B second %ld\n",get(Bl));

    }


    /*if(length(mltList == 0)){
        mlt = copy(place);
    }
    else{

    }
    */
    return mlt;
   // while(index(A->lists))
}
/*
{
    
    BigInteger mlt = newBigInteger();
    BigInteger dummy = newBigInteger();
    List Alist = A->list;
    List Blist = B->list;
    List Mlist = mlt->list;
    List dumList = dummy->list;
    dummy->sign = A->sign * B->sign;
    moveBack(Alist);
    moveBack(Blist);
    long Anum = 0;
    long Bnum = 0;
    long insert = 0;
    int counter = 0;
    //BEFORE I FORGET I PROBABLY NEED TO USE ANOTHER BIGINTEGER AND THEN IN THE LOOP I KEEP SETTING IT BACK TO ZERO TO BE ABLE TO KEEP ADDING TO IT
    while(index(Blist) != -1){
                        printf("HERE 1");

        Bnum = get(Blist);
        while(index(Alist)!=-1){
            Anum = get(Alist);
            printf("HERE 2");
            insert = Anum * Bnum;
            prepend(dumList,insert);
            movePrev(Alist);
            counter++;
        }
                                

        if(length(Mlist)!=0){
        moveBack(Mlist);
        }
        moveBack(dumList);

        while(index(dumList)!=-1){
            printf("HERE 3");
            while(index(dumList)!=-1 && (get(dumList)<0 || get(dumList) > BASE)){
                normalize(dumList);
            }
             movePrev(dumList);
        }
        if(length(Mlist) == 0){
            mlt = copy(dummy);
        }
        else{
            //int mNum;
            //int dumNum;
            while(index(Mlist)!=-1){
                // right here i probably want to get individually so i can add a zero if needed if the lengths are not the same
                //mNum = get()
                //if(index)
                printf("IS IT RIGHT HERE");
                long ad = get(Mlist) + get(dumList);
                set(Mlist,ad);
            }
        }
        clear(dumList);
        for(int i =0; i<counter;i++){
                prepend(dumList,0);
             }

        
       

        //I think right here i normalize until its fully normal in a loop maybe
        // add to the mlt biginteger list here  then dummy can go back to zero 
        movePrev(Blist);
        
    }
    


    return mlt;
    */
//}
// Other operations -----------------------------------------------------------
// printBigInteger()
// Prints a base 10 string representation of N to filestream out.
void printBigInteger(FILE *out, BigInteger N)
{
    if(N->sign == -1){
        fprintf(out,"-");
    }
    printList(out, N->list);
}
