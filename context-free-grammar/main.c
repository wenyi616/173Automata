#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
#include "parse.h"
#include "printTree.h"
#include "calculator.c"
#include "Node.c"

int main() {

	term = malloc(sizeof(char)*10); 
	term[0]='0';
	term[1]='1';
	term[2]='2';
	term[3]='3';
	term[4]='4';
	term[5]='5';
	term[6]='6';
	term[7]='7';
	term[8]='8';
	term[9]='9';

	char pro[9][10]={
		'0','0','0','0','0','0','1','0','1','1',
		'e','e','1','2','e','e','e','e','e','e',
		'0','0','0','0','0','0','1','0','1','1',
		'e','e','e','e','1','2','e','e','e','e',
		'2','0','0','0','0','0','1','0','1','1',
		'0','0','0','0','0','0','1','0','0','0',
		'e','e','e','e','e','e','1','e','0','0',
		'0','0','0','0','0','0','1','0','0','0',
		'0','0','0','0','0','0','3','0','1','2',
	};

	/* Part1 */

	printf("%s\n","Hello World: Enter 1 or 2 or 3 to test Part 1 or 2 or 3: ");
	char ch1;
    scanf("%c%*c", &ch1);

    if(ch1 == '1'){

    	printf("%s\n","Hello World: Enter an expression to test, or QUIT to quit");
    	char input[10];
		scanf("%s", input);

		while( input[0] != 'Q' && input[1] != 'U' ){
			nextTerminal = input;
			printf(">>> Testing part1 >>> Your input is: %s\n", nextTerminal);

			TREE parseTree = E(); 
			if(parseTree == NULL){
				printf("%s\n", "Invalid input");
			}else{
				printTree(parseTree);
					
				/* Part3 */	
				// printf("Start calculating: ");
    //     		printf("%f\n",Et(parseTree));
			}
			
			printf("%s\n", "Hello World: Enter another expression to test, or QUIT to quit");
			scanf("%s", input);
		}

		printf("%s\n", "QUIT detected. Program finished.");
		
		
        return 0;

	}else if(ch1 == '2'){
		
		// nextTerminal="sin2/80";
		printf("%s\n","Hello World: Enter an expression to test, or QUIT to quit");
    	char input[10];
		scanf("%s", input);

		while( input[0] != 'Q' && input[1] != 'U' ){
			nextTerminal = input;
			printf(">>> Testing part2 >>> Your input is: %s\n", nextTerminal);

			
		TREE e=makeNode0('E');
		push(e);
		TREE tree=e;
		int boo=1;
		
		while(empty()==false){

			TREE root=TOS();
			pop();
			int fir;
			int sec;
			char label=root->label;
			char sym=*nextTerminal;

			if(label==')'){
				nextTerminal++;
			}else{
			if(label=='E'){
				fir=0;
			}else if(label=='K'){
				fir=1;
			}else if(label=='T'){
				fir=2;
			}else if(label=='M'){
				fir=3;
			}else if(label=='F'){
				fir=4;
			}else if(label=='N'){
				fir=5;
			}else if(label=='X'){
				fir=6;
			}else if(label=='C'){
				fir=8;
			}else{
				fir=7;
			}
			if(sym=='('){
				sec=0;
			}else if(sym==')'){
				sec=1;
			}else if(sym=='+'){
				sec=2;
			}else if(sym=='-'){
				sec=3;
			}else if(sym=='*'){
				sec=4;
			}else if(sym=='/'){
				sec=5;
			}else if(sym=='\0'){
				sec=7;
			}else if(sym=='s'){
				sec=8;
			}else if(sym=='c'){
				sec=9;
			}else{
				sec=6;
			}
			char part=pro[fir][sec];
			TREE cn;
			if(label=='E'){
				cn=E1(root,part);
			}else if(label=='K'){
				cn=K1(root,part);
			}else if(label=='T'){
				cn=T1(root,part);
			}else if(label=='M'){
				cn=M1(root,part);
			}else if(label=='F'){
				cn=F1(root,part);
			}else if(label=='N'){
				cn=N1(root,part);
			}else if(label=='X'){
				cn=X1(root,part);
			}else if(label=='C'){
				cn=C1(root,part);
			}else{
				cn=D1(root,part);
			}
			if(cn==NULL){
				printf("%s\n","Invalid Input.");
				break;
				boo=0;
			}
			}
			}
			if(boo==1){
			printTree(tree);
		}
			
			printf("%s\n", "Hello World: Enter another expression to test, or QUIT to quit");
			scanf("%s", input);
		}

		printf("%s\n", "QUIT detected. Program finished.");
		return 0;

	}else if(ch1 == '3'){
		printf("%s\n","Hello World: Enter an expression to test, or QUIT to quit");
    	char input[10];
		scanf("%s", input);

		while( input[0] != 'Q' && input[1] != 'U' ){
			nextTerminal = input;
			printf(">>> Testing part3 >>> Your input is: %s\n", nextTerminal);

			TREE parseTree = E(); 

			if(parseTree == NULL){
				printf("%s\n", "Invalid input");
			}else{
				// printTree(parseTree);
					
				/* Part3 */	
				printf("Start calculating: ");
        		printf("%f\n",Et(parseTree));
			}
			printf("%s\n", "Hello World: Enter another expression to test, or QUIT to quit");

			scanf("%s", input);
		}

		printf("%s\n", "QUIT detected. Program finished.");
		return 0;
	}

}