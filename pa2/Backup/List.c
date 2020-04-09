//-----------------------------------------------------------------------------
// List.c
// Surya Rani 
// srani
// pa2
//-----------------------------------------------------------------------------

#include<stdio.h>
#include<stdlib.h>
#include "List.h"

// structs --------------------------------------------------------------------

// private NodeObj type
typedef struct NodeObj{
   void* data;
   struct NodeObj* next;
   struct NodeObj* prev;
} NodeObj;

// private Node type
typedef NodeObj* Node;

// private StackObj type
typedef struct ListObj{
   Node front;
   Node back;
   Node cursor;
   int index;
   int length;
} ListObj;

// Constructors-Destructors ---------------------------------------------------

// newNode()
// Returns reference to new Node object. Initializes next and data fields.
// Private.
Node newNode(void* node_data){
   Node N = malloc(sizeof(NodeObj));
   N->data = node_data;
   N->next = NULL;
   N->prev = NULL;
   return(N);
}

// freeNode()
// Frees heap memory pointed to by *pN, sets *pN to NULL.
// Private.
void freeNode(Node* pN){
   if( pN!=NULL && *pN!=NULL ){
      free(*pN);
      *pN = NULL;
   }
}
// -----------------------------------------
// PUBLIC FUNCTIONS
typedef ListObj* List;

List newList(void){
   List L;
   L = malloc(sizeof(ListObj));
   L->front = NULL;
   L->back = NULL;
   L->cursor = NULL;
   L->index = -1;
   L->length = 0;

   return L;
}

void freeList(List* pL){
   if(pL!=NULL && *pL!=NULL){
      free(*pL);
      pL = NULL;
   }
}

int length(List L){
   return L->length;
}

int index(List L){
   return L->index;
}

void* front(List L){
   if( L->length == 0 ){
      printf("List Error: calling front() on an empty List\n");
      exit(1);
   }
   return L->front->data;

}

void* back(List L){
   if( L->length == 0 ){
      printf("List Error: calling back() on an empty List\n");
      exit(1);
   }
   return L->back->data;
}

void* get(List L){
   if( L->length == 0){
      printf("List Error: calling get() on an empty List\n");
      exit(1);
   }
    if( L->index < 0){
      printf("List Error: calling get() with undefined cursor\n");
      exit(1);
   }
   return L->cursor->data;
}

/*int equals(List A, List B){
   int eq = 0;
   Node N = NULL;
   Node M = NULL;

   eq = ( A->length == B->length );
   N = A->front;
   M = B->front;
   while( eq && N!=NULL){
      eq = (N->data==M->data);
      N = N->next;
      M = M->next;
   }
   return eq;
}
*/

void clear(List L){ //might have some leaked memory here 
   if(L->length == 0){

   }
   else{
     if(L->index!=-1){
         freeNode(&L->cursor);
         L->cursor = NULL;
         L->index =-1;
      }
      if(L->length == 1){
         freeNode(&L->front);
         freeNode(&L->back);
         L->front = NULL;
         L->back = NULL;
      }
      else{
         Node delete = L->front;
         Node deleteNext = delete->next;
         while(deleteNext!=NULL){
            freeNode(&delete);
            delete = deleteNext;
            deleteNext = delete->next;
         }
         freeNode(&delete);
         delete =NULL;
         deleteNext = NULL;
      }
      L->length= 0;
   }

}

void moveFront(List L){
   if(length >0){
      L->cursor = L->front;
   }
   L->index =0;
}

void moveBack(List L){
   if(length >0){
      L->cursor = L->back;
   }
   L->index = L->length -1;
}

void movePrev(List L){
   if(L->cursor != NULL && L->cursor != L->front){
      L->cursor = L->cursor->prev;
      L->index = L->index-1;
   }
   else if(L->cursor != NULL && L->cursor == L->front){
      L->cursor = NULL;
      L->index = -1;

   }
   else{

   }
}

void moveNext(List L){
   if(L->cursor != NULL && L->cursor != L->back){
      L->cursor = L->cursor->next;
      L->index = L->index+1;

   }
   else if(L->cursor != NULL && L->cursor == L->back){
      L->cursor = NULL;
      L->index = -1;

   }
   else{
      
   }
}

void prepend(List L, void* data){
   Node pre = newNode(data);
   if(L->length == 0){
     L->front = pre; 
     L->back = pre;
   }
   else{
      Node next = L->front;
      L->front = pre;
      L->front->next = next;
      next->prev = pre;
      if(L->index != -1){
      L->cursor = next;
      L->index ++;
   }
   }
   L->length++;
} 
// Insert new element into L. If L is non-empty, // insertion takes place before front element.
void append(List L, void* data){
   Node app = newNode(data);
   if(L->length == 0){
     L->front = app; 
     L->back = app;
   }
   else{
     L->back->next = app;
     app->prev = L->back;
     L->back = L->back->next;
   }
   //app = NULL;
   L->length++;

} 
// Insert new element into L. If L is non-empty, // insertion takes place after back element.
void insertBefore(List L, void* data){
   if( L->length == 0){
      printf("List Error: calling insertBefore() on an empty List\n");
      exit(1);
   }
   if( L->index < 0){
      printf("List Error: calling insertBefore() with undefined cursor\n");
      exit(1);
   }

   Node before = newNode(data);
   if(L->index == 0){
      before->next = L->cursor;
      L->cursor ->prev = before;
      L->front = before;
      L->index =1;
   }
   else{
      before->prev = L->cursor->prev;
      before->next = L->cursor;
      L->cursor->prev->next = before;
      L->cursor->prev = before;
      L->index++;
   }
   L->length++;
} 
// Insert new element before cursor. // Pre: length()>0, index()>=0
void insertAfter(List L, void* data){
   if( L->length == 0){
      printf("List Error: calling insertBefore() on an empty List\n");
      exit(1);
   }
   if( L->index < 0){
      printf("List Error: calling insertBefore() with undefined cursor\n");
      exit(1);
   }
   Node after = newNode(data);
   if(L->index == L->length-1){
      after->prev = L->cursor;
      L->cursor->next = after;
      L->back = after;
   }
   else{
   after->next = L->cursor->next;
   after->prev = L->cursor;
   L->cursor->next->prev = after;
   L->cursor->next = after;
   }
      L->length++;

} 
// Insert new element before cursor. // Pre: length()>0, index()>=0
void deleteFront(List L){
   if( L->length == 0){
      printf("List Error: calling insertBefore() on an empty List\n");
      exit(1);
   }
   if(L->length == 1){
      freeNode(&L->front);
      freeNode(&L->back);
      L->front = NULL;
      L->back = NULL;
      if(L->index==0){
         L->index =-1;
         L->cursor =NULL;
      }
   }
   else{
      Node delete = L->front;
      L->front = L->front->next;
      freeNode(&delete);
      delete = NULL;
      if(L->index!=-1){
         L->index --;
      }
   }
      L->length--;
}

void deleteBack(List L){
   if( L->length == 0){
      printf("List Error: calling insertBefore() on an empty List\n");
      exit(1);
   }
   if(L->length == 1){
      freeNode(&L->front);
      freeNode(&L->back);
      L->front = NULL;
      L->back = NULL;
      if(L->index==0){
         L->index =-1;
         L->cursor =NULL;
      }
   }
   else{
      Node delete = L->back;
      L->back = L->back->prev;
      freeNode(&delete);
      delete =NULL;
      if(L->index ==  L->length-1){
         L->index = -1;
         L->cursor = NULL;
      }
   }
   L->length--;
}
void delete(List L){
   if( L->length == 0){
      printf("List Error: calling insertBefore() on an empty List\n");
      exit(1);
   }
   if( L->index < 0){
      printf("List Error: calling insertBefore() with undefined cursor\n");
      exit(1);
   }
   if(L->index == 0){
      deleteFront(L);
      L->cursor = NULL;
   }
   else if(L->index == L->length-1){
      deleteBack(L);
      L->cursor = NULL;
   }
   else{
      Node delete = L->cursor;
      L->cursor->prev->next = L->cursor->next;
      L->cursor->next->prev = L->cursor->prev;
      freeNode(&delete);
      delete = NULL;
      L->cursor = NULL;
   }

}

void printList(FILE* out, List L){
   Node iterate = L->front;
   while(iterate!=NULL){
      fprintf(out, "%p ",iterate->data);
      iterate = iterate->next;
   }
}

/*List copyList(List L){
   Node iterate = L->front;
   List N = newList();
   while(iterate!=NULL){
      append(N,iterate->data);
      iterate = iterate->next;
   }
   return N;
}
*/





