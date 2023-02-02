#include <stdio.h>
#include <string.h>

struct studentNode {
 char name[20] ;
 int age ;
 char sex ;
 float gpa ;
 struct studentNode *next ;
} ;

void ShowAll( struct studentNode **walk ) ;
void InsNode( struct studentNode **walk, char name[], int age, char sex, float gpa ) ;
void DelNode( struct studentNode **walk ) ;
void GoNext( struct studentNode ***walk ) ;


int main() {
 struct studentNode *start, **now ;
 start = NULL ; now = &start ;
 InsNode( now, "one", 6, 'M', 3.11 ) ; 
 ShowAll( &start ) ;
 InsNode( now, "two", 8, 'F', 3.22 ) ; 
 ShowAll( &start ) ;
 GoNext( &now ) ;
 InsNode( now, "three", 10, 'M', 3.33 ) ; 
 ShowAll( &start ) ;
 InsNode( now, "four", 12, 'F', 3.44 ) ; 
 ShowAll( &start ) ;
 GoNext( &now ) ;
 DelNode( now ) ; 
 ShowAll( &start ) ;
 return 0 ;
}//end function

void ShowAll( struct studentNode **walk ) {
 while( *walk != NULL ) {
  printf( "%s ", (*walk)->name ) ;
  walk = &(*walk)->next ;
 }//end while
 printf( " \n" ) ;
}//end function

void InsNode( struct studentNode **walk, char name[], int age, char sex, float gpa ){
	struct studentNode *before = (*walk) ;
	if ( (*walk) == NULL ) {
		*walk = new struct studentNode ;
		(*walk)->next = NULL ;
	}
	struct studentNode *ins = new struct studentNode ;
	strcpy(ins->name, name) ;
	ins->age = age ;
	ins->sex = sex ;
	ins->gpa = gpa ;
	ins->next = (*walk)->next ;
	(*walk) = ins ;
	(*walk)->next = before ;
}

void DelNode( struct studentNode **walk ){
	if ( (*walk) != NULL ){
		struct studentNode *ins = new struct studentNode ;
		ins = (*walk)->next ;
		(*walk) = ins ;	
	}
	
}
void GoNext( struct studentNode ***walk  ) {
	if ( (**walk) != NULL ) {
		(*walk) = &(**walk)->next ;
	}
}
