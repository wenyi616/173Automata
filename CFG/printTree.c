#include <stdio.h> 
#include <stdbool.h>
#include <stdlib.h>
#include "printTree.h"
#include <math.h>
#define PI 3.14159265
int count=0;

void printSpace(int s){
	if(s!=0){
	printf("%*c", s, ' ');}
}

void print(TREE t, int s){
	printSpace(s);
	printf("%c\n",t->label);
}

void Track(TREE t, int s){
	if(t!=NULL){
		
		print(t,s);
		Track(t->leftmostChild,s+1);
		Track(t->rightSibling,s);
	}
}

void printTree(TREE t){
	int s=0;
	Track(t,s);

}

double Et(TREE root){

	double e=Tt(root->leftmostChild)+TTt(root->leftmostChild->rightSibling);
	// printf("%s\n","Et");
	// printf("%f\n",e);
	return e;
}
double TTt(TREE root){
		
	if(root->leftmostChild->label=='e'){
		// printf("%s\n","TTt");
		// printf("%d\n",0);
		return 0;
	}else{
		TREE n1,n2,n3;
		n1=root->leftmostChild;
		n2=n1->rightSibling;
		n3=n2->rightSibling;
		double result;
		if(n1->label=='+'){
         result= Tt(n2)+TTt(n3);
		}else{
		 result= -Tt(n2)-TTt(n3);
		}
          // printf("%s\n","TTt");
          // printf("%f\n",result);
		return result;
	}
}
double Tt(TREE root){
	// printf("%s\n","Tt");
  //       printf("%c\n",root->label);
		// printf("%s\n","Tt");
	double t= Ft(root->leftmostChild)*FTt(root->leftmostChild->rightSibling);
	// printf("%f\n",t);
	return t;
}
double FTt(TREE root){
		// printf("%s\n","FTt");
  //       printf("%c\n",root->label);
if(root->leftmostChild->label=='e'){
	// printf("%s\n","FTt");
	// printf("%d\n",0);
		return 1;
	}else{
TREE n1,n2,n3;
		n1=root->leftmostChild;
		n2=n1->rightSibling;
		n3=n2->rightSibling;
		if(n1->label=='*'){
         double re= Ft(n2)*FTt(n3);
      //    printf("%s\n","FTt");
	     // printf("%f\n",re);
	     return re;
		}else{
		  double re=1/(Ft(n2)*FTt(n3));
		    //  printf("%s\n","FTt");
	     // printf("%f\n",re);
	     return re;
		}
	}
}
double Ft(TREE root){
		// printf("%s\n","Ft");
  //       printf("%c\n",root->label);
	if(root->leftmostChild->label=='('){
		double re=Et(root->leftmostChild->rightSibling);
		// printf("%s\n","Ft");
		// 	printf("%f\n",re);
		return re;
	}else{
		double re=Ct(root->leftmostChild);
		// printf("%s\n","Ft");
		// 	printf("%f\n",re);
        return re;
	}
}
double Ct(TREE root){
		// printf("%s\n","Ct");
  //       printf("%c\n",root->label);
	if(root->leftmostChild->label=='s'){
		double temp=Nt(root->leftmostChild->rightSibling->rightSibling->rightSibling);
		double val = PI / 180.0;
		double count=sin(temp*val);
		// printf("%f\n",count);
        return count;
	}else if(root->leftmostChild->label=='c'){
        double temp=Nt(root->leftmostChild->rightSibling->rightSibling->rightSibling);
		double val = PI / 180.0;
       	double count=cos(temp*val);
       		// printf("%f\n",count);
        return count;
	}else{
		double count=Nt(root->leftmostChild);
			// printf("%f\n",count);
		return count;
	}
}
double combine(double a, double b) {
   double times = 1;
   while (times <= b)
      times *= 10;
   return a*times + b;
} 
double Nt(TREE root){
		// printf("%s\n","Nt");
		// printf("%c\n",root->label);
		// printf("%c\n",root->leftmostChild->label);
		// // printf("%c\n",root->leftmostChild->leftmostChild->label);
		// printf("%f\n",Dt(root->leftmostChild));
		// printf("%f\n",NTt(root->leftmostChild->rightSibling));
		double com=combine(Dt(root->leftmostChild),NTt(root->leftmostChild->rightSibling));
		// printf("%f\n",com);
return com;
}
double NTt(TREE root){
		// printf("%s\n","NTt");
	if(root->leftmostChild->label=='e'){
		// printf("%d\n",0);
		return 0;
	}else{
		double n=Nt(root->leftmostChild);
		// printf("%f\n",n);
		return n;
	}
}
double Dt(TREE root){
		// printf("%c\n",root->label);
	char c=root->leftmostChild->label;
	// printf("%c\n",c);
	if(c=='0'){
		;
		return 0;
	}else if(c=='1'){
		return 1;
	}else if(c=='2'){
		return 2;
	}else if(c=='3'){
		return 3;
	}else if(c=='4'){
		return 4;
	}else if(c=='5'){
		return 5;
	}else if(c=='6'){
		return 6;
	}else if(c=='7'){
		return 7;
	}else if(c=='8'){
		return 8;
	}else if(c=='9'){
		return 9;
	}
	// printf("%s\n","failed here");
	return 0;
}
// bool isDigit(char c){
// if(c=='0'||c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9'){
// return true;
// }else{
// 	return false;
// }
// }

// char* traverse(TREE root){
// 	char label=root->label;
// 	if(isDigit(label)==true||label=='+'||label=='-'||label=='*'||label=='/'||label=='('||label==')'){
// 		char* string=malloc(sizeof(label));
// 		string[0]=label;
// 		return string;
// 	}else{
// 		TREE n1=root->leftmostChild;
// 		char* t=traverse(n1);
// 		char c=t[0];
// 		if(c=='s'){
// 			double ret, val;
// 		double temp = strtod(traverse(n1->leftmostChild->rightSibling->rightSibling->rightSibling),NULL);
// 		val = PI / 180.0;
//         ret = sin(temp*val);
//         char* arr;
//         snprintf(arr, 8, "%2.4f", a);
// 		}else if(c=='c'){
// 		double ret, val;
// 		double temp = strtod(traverse(n1->leftmostChild->rightSibling->rightSibling->rightSibling),NULL);
// 		val = PI / 180.0;
//         ret = cos(temp*val);
// 		}else if
// 	}
// }


// char ch(TREE t){
// 	char c=t->label;
// 	for (int i = 0; i < sizeof(term); i++) {
// 		if (c == term [i]) {
// 			return c;
// 		}
// 	}
// 	if(c=='('||c==')'||c=='+'||c=='-'||c=='*'||c=='/'){
// 		return c;
// 	}
// 	return'%';
// }

// void Trace(TREE t){
// 	if(t!=NULL){
		
// 		char ele=ch(t);
// 		if(ele!='%'){
// 			string[count]=ele;
// 			count++;
// 		}
// 		Trace(t->leftmostChild);
// 		Trace(t->rightSibling);
// 	}
// }

// void makestring(TREE t){
// 	Trace(t);
// }
