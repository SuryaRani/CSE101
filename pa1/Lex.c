//-----------------------------------------------------------------------------
// Lex.c
// 
//-----------------------------------------------------------------------------
#include<stdio.h>
#include<stdlib.h>
#include "List.h"
#include "string.h"
int main(int argc, char* argv[]){
	if(argc!=3){
		fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
		exit(1);
	}

	int len =0;
	char c;
	FILE *in = fopen(argv[1],"r");
	FILE *out = fopen(argv[2],"w");
	char word[100];

	for (c = getc(in); c != EOF; c = getc(in)){ 
        if (c == '\n') { // Increment count if this character is newline 
            len = len + 1; 
        }
    }
    rewind(in);
    
    char *arr[len];
    int d=0;
   	while(fgets(word,100,in) && d<len){
   		arr[d] = malloc(70);
   		//printf("Before %s",word);
   		//printf("%s",word);
   		strcpy(arr[d],word);
   		//printf("After %s",arr[d]);
   		
   		d++;
   	}
    
	
	
	
   
    /*printf("Length = %d",len);
    arr[0]= "hey";
    arr[1] = "ney";
    arr[2] = "gae";*/

    List L = newList();

	//for(int x =0; x<len;x++){
    	
    //	printf("%d %s",x, arr[x]);
   
    

    append(L,0);
    moveFront(L);
    int next =0;
    //printf("Numbers being comped %s %s %s %s\n",arr[0],arr[1], arr[2],arr[3]);
    for(int i =1; i<len;i++){
    	next =0;
    	moveFront(L);
    	while(index(L)!=-1 && next ==0){
    		//printf("The comparison %d\n",strcmp(arr[i],arr[get(L)]));
    		
    		if(strcmp(arr[i],arr[get(L)])<0){
    			insertBefore(L,i);
    			moveFront(L);
    			//printf("Front %d\n",front(L));
    			next = 1;
    		}
    		else {
    			moveNext(L);
    			if(index(L)==-1){
    				append(L,i);
    			}
    		}
    	}
    }

    moveFront(L);
    while(index(L)!=-1){
    	fprintf(out,"%s",arr[get(L)]);
    	moveNext(L);
    }
    fclose(in);
    fclose(out);


	for (int k = 0; k < len; k++){
    free(arr[k]);
	}
	clear(L);
	freeList(&L);
	L =NULL;

}
