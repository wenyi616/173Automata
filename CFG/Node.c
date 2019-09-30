#include <stdio.h> 
#include <stdbool.h>
#include <stdlib.h>
#ifndef _Node_c
#define _Node_c
typedef struct NODE *TREE; 
struct NODE {
char label;
TREE leftmostChild, rightSibling; };
char *nextTerminal; 
char *term;

/* current position in input string */
#endif