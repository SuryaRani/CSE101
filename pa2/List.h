//-----------------------------------------------------------------------------
// Stack.h
// Surya Rani 
// srani
// pa2
//-----------------------------------------------------------------------------

#ifndef _LIST_H_INCLUDE_
#define _LIST_H_INCLUDE_

typedef struct ListObj* List;

// Constructors-Destructors ---------------------------------------------------
List newList(void);
void freeList(List* pL);
// Access functions
int length(List L);
int index(List L);
void* front(List L);
void* back(List L);
void* get(List L);
//void* equals(List A, List B); // Returns true (1) iff Lists A and B are in same
void clear(List L);
void moveFront(List L);
void moveBack(List L);
void movePrev(List L);
void moveNext(List L);
// Resets L to its original empty state.
// If L is non-empty, sets cursor under the front element, // otherwise does nothing.
// If L is non-empty, sets cursor under the back element, // otherwise does nothing.
// If cursor is defined and not at front, move cursor one // step toward the front of L; if cursor is defined and at // front, cursor becomes undefined; if cursor is undefined // do nothing
// If cursor is defined and not at back, move cursor one // step toward the back of L; if cursor is defined and at // back, cursor becomes undefined; if cursor is undefined // do nothing
// Returns back element of L. Pre: length()>0
// Returns cursor element of L. Pre: length()>0, index()>=0
void prepend(List L, void* data); // Insert new element into L. If L is non-empty, // insertion takes place before front element.
void append(List L, void* data); // Insert new element into L. If L is non-empty, // insertion takes place after back element.
void insertBefore(List L, void* data); // Insert new element before cursor. // Pre: length()>0, index()>=0
void insertAfter(List L, void* data); // Insert new element before cursor. // Pre: length()>0, index()>=0
void deleteFront(List L);
void deleteBack(List L);
void delete(List L);
// Delete the front element. Pre: length()>0
// Delete the back element. Pre: length()>0
// Delete cursor element, making cursor undefined. // Pre: length()>0, index()>=0
// Other operations ----------------------------------------------------------- void printList(FILE* out, List L); // Prints to the file pointed to by out, a
                                    // string representation of L consisting
                                    // of a space separated sequence of integers,
                                    // with front on left.
//List copyList(List L); // Returns a new List representing the same integer
// sequence as L. The cursor in the new list is undefined,
// regardless of the state of the cursor in L. The state // of L is unchanged.

#endif