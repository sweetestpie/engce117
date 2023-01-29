//panploy rakpanya 65543206073-0 sec 1
//https://youtu.be/fK1qcpR1RJ4
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
struct Node {
 int data ;
 struct Node *next ;
} ;

void ShowAll( struct Node *start ) ;
void Swap(struct Node **head_ref, int n1, int n2);
struct Node *AddNode ( struct Node **start, int data ) ;


int main() {
 struct Node *start , *now;
 	start = NULL;
 	AddNode( &start, 10 );
    AddNode( &start, 20 );
    AddNode( &start, 30 );
    AddNode( &start, 40 );
    ShowAll(start); //10, 20, 30, 40
    Swap(&start, 20, 30);
    ShowAll(start); //10, 30, 20, 40
    Swap(&start, 40, 10);
    ShowAll(start); //40, 30, 20, 10
}//end function

void ShowAll( struct Node *start ) {
	while( start != NULL ) {
  		printf( "%d ", start->data ) ;
  		start = start->next ;
}//end while
 
	printf( " \n" ) ;
}//end function

 struct Node *AddNode (  struct Node **start, int data ) {
	while ( *start != NULL ) {
		start = &(*start)->next ;
	} 
	*start =  new struct Node;
	(*start)->data = data ;
	(*start)->next = NULL ;
	return *start ;
}

void Swap(struct Node** head_ref, int n1, int n2){
    if (n1 == n2)
        return;
    // Search  n1
    struct Node *prevn1 = NULL, *currn1 = *head_ref;
    while (currn1 && currn1->data != n1) {
        prevn1 = currn1;
        currn1 = currn1->next;
    }
    // Search  n2 
    struct Node *prevn2 = NULL, *currn2 = *head_ref;
    while (currn2 && currn2->data != n2) {
        prevn2 = currn2;
        currn2 = currn2->next;
    }
    if (currn1 == NULL || currn2 == NULL)
        return;
    // If x is not head of linked list
    if (prevn1 != NULL)
        prevn1->next = currn2;
    else // Else make y as new head
        *head_ref = currn2;
 
    // If y is not head of linked list
    if (prevn2 != NULL)
        prevn2->next = currn1;
    else // Else make x as new head
        *head_ref = currn1;
    // Swap next pointers
    struct Node* temp = currn2->next;
    currn2->next = currn1->next;
    currn1->next = temp;
}
