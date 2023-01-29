//panploy rakpanya 65543206073-0 sec 1
//https://youtu.be/fK1qcpR1RJ4
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
struct Node {
 int data ;
 struct Node *next ;
 struct Node *back ;
} ;

void ShowAll( struct Node *start ) ;
void ShowBack(struct Node *start);
struct Node *AddNode ( struct Node **start, int data ) ;


int main() {
 struct Node *start , *back , *now;
 	start = NULL;
 	now = AddNode( &start, 10 );
    now = AddNode( &start, 20 );
    now = AddNode( &start, 30 );
    now = AddNode( &start, 40 );
    back = now;
    ShowAll(start); //10, 20, 30, 40
   	ShowBack(back); //40, 30, 20, 10
 return 0 ;
}//end function

struct Node *AddNode (  struct Node **start, int data ) {
 	struct Node *temp = NULL;
	while ( *start != NULL ) {
		temp = *start;
		start = &(*start)->next ;
	} 
	*start =  new struct Node;
	(*start)->data = data ;
	(*start)->next = NULL ;
	(*start)->back = temp ;
	return *start ;
}

void ShowAll( struct Node *start ) {
	while( start != NULL ) {
  		printf( "%d ", start->data ) ;
  		start = start->next ;
}//end while
 
	printf( " \n" ) ;
}//end function

 
void ShowBack(struct Node *start){
	while( start != NULL ) {
  		printf( "%d ", start->data ) ;
  		start = start->back ;
}//end while
 	printf( " \n" ) ;
}//end function


	
	
	
	




