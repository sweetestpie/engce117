//panploy rakpanya 65543206073-0 sec 1
//https://youtu.be/fK1qcpR1RJ4
#include <stdio.h>
#include <stdlib.h>
struct Node {
 int data ;
 struct Node *next ;
} ;

void ShowAll( struct Node *start ) ;
void Update(struct Node **start, int old, int New);
struct Node *AddNode ( struct Node **start, int data ) ;
struct Node *head = NULL;
struct Node *current = NULL;


int main() {
 struct Node *start = NULL;
 	AddNode( &start, 10 );
    AddNode( &start, 20 );
    AddNode( &start, 30 );
    AddNode( &start, 40 );
    ShowAll(start); //10, 20, 30, 40
    Update(&start, 10, 99);
    ShowAll(start); //99, 20, 30, 40
    Update(&start, 10, 98);
    ShowAll(start); //99, 20, 30, 40
    return 0;
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



void Update(struct Node **start, int old, int New) {
	
   int pos = 0;
   head = *start;
   
   if(head==NULL) {
      return;
   } 
   current = head;
   while(current->next!=NULL) {
      if(current->data == old) {
         current->data = New;
         return;
      }
      
      current = current->next;
      pos++;
   }
}

    



	
	
	

