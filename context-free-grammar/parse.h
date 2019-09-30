#include <stdio.h> 
#include <stdbool.h>
#include <stdlib.h>
#include "Node.c"

#define FAILED NULL
void push(TREE k);
TREE TOS();
void pop() ;
bool empty();
void display(); 
TREE* stack();
TREE makeNode0(char x);
TREE makeNode1(char x, TREE t);
TREE makeNode2(char x, TREE t1, TREE t2);
TREE makeNode3(char x, TREE t1, TREE t2, TREE t3); 
// void termDigit ();
TREE parseTree; /* holds the result of the parse */
// char *term;
TREE D();
TREE X();
TREE N();
TREE F();
TREE M();
TREE T ();
TREE K ();
TREE E() ;
TREE C();
TREE D1 (TREE root,char part);
TREE C1 (TREE root,char part);
TREE X1(TREE root,char part);
TREE N1(TREE root,char part) ;
TREE F1(TREE root,char part);
TREE M1(TREE root,char part);
TREE T1 (TREE root,char part);
TREE K1 (TREE root,char part) ;
TREE E1(TREE root,char part) ;