#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct studentNode {
char name[20] ;
int age ;
char sex ;
float gpa ;
struct studentNode *next ;
struct studentNode *back ;
} ;

void ShowAll( struct studentNode *walk ) ;
struct studentNode *AddNode ( struct studentNode **walk, char name[], int age, char sex, float gpa ) ;
void InsNode( struct studentNode *walk, char name[], int age, char sex, float gpa ) ;
void DelNode( struct studentNode *walk );
void GoBack( struct studentNode **walk );

int main() {
 struct studentNode *start, *now ;
 start = NULL ;
 now = AddNode( &start,"one", 6 ,'M', 3.11 ) ; 
 ShowAll( start ) ;
 now = AddNode( &start, "two", 8 ,'F' , 3.22 ) ;
 ShowAll( start ) ;	
 InsNode( now, "three", 10, 'M', 3.33 ) ; 
 ShowAll( start ) ;
 InsNode( now, "four", 12, 'F', 3.44 ) ; 
 ShowAll( start ) ;
 GoBack( &now ) ;
 DelNode( now ) ; ShowAll( start ) ;
 DelNode( now ) ; ShowAll( start ) ;
 DelNode( now ) ; ShowAll( start ) ;
return 0 ;
}//end function



void ShowAll( struct studentNode *walk ) {

 while( walk != NULL ) {
  printf( "%s ", walk->name ) ;
  walk = walk->next ;
 }//end while
 printf( " \n" ) ;
}//end function

 struct studentNode *AddNode ( struct studentNode **walk, char name[], int age, char sex, float gpa ) {
	struct studentNode *temp = NULL;
	while ( *walk != NULL ) {
		temp = *walk;
		walk = &(*walk)->next ;
	} 
	*walk =  new struct studentNode ;
	strcpy((*walk)->name, name) ;
	(*walk)->age = age ;
	(*walk)->sex = sex ;
	(*walk)->gpa = gpa ;
	(*walk)->next = NULL ;
	(*walk)->back = temp ;
	return *walk ;
}
void InsNode( struct studentNode *walk, char name[], int age, char sex, float gpa ) {
	struct studentNode *ins = new struct studentNode ;
	strcpy(ins->name, name) ;
	ins->age = age ;
	ins->sex = sex ;
	ins->gpa = gpa ;
	ins->next = walk->next ;
	walk->next = ins ;
}
void DelNode( struct studentNode *walk ) {
	struct studentNode *ins = new struct studentNode ;
	ins = walk->next->next ;
	walk->next = ins ;
}
void GoBack( struct studentNode **walk ) {
	if ( (*walk)->back != NULL ) {
		*walk = (*walk)->back ;
	}
}
