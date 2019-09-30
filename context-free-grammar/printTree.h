#include <stdio.h> 
#include <stdbool.h>
#include <stdlib.h>
#include "Node.c"
	
	char string[100];
	void printSpace(int s);
	void print(TREE t, int s);
	void Track(TREE t, int s);
	void printTree(TREE t);
	char ch(TREE t);
	void Trace(TREE t);
	// void makestring(TREE t);
	double Et(TREE root);
	double TTt(TREE root);
	double Tt(TREE root);
	double FTt(TREE root);
	double Ft(TREE root);
	double Ct(TREE root);
	double combine(double a, double b);
	double Nt(TREE root);
	double NTt(TREE root);
	double Dt(TREE root);