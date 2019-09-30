#include <stdio.h> 
#include <stdbool.h>
#include <stdlib.h>
#include "parse.h"
TREE a[10];

int top=-1,i;
void push(TREE k) //Pushes The Set Of Characters on to the Stack
{
  
    if(top<9)
    a[++top]=k;
  
}
TREE TOS()        //Returns TOP of the Stack
{
  return a[top];
}
void pop()       //Pops 1 element from the Stack
{
  if(top>=0)
    a[top--]=NULL;
}
bool empty(){
  for(int j=0;j<=9;j++){
    if(a[j]!=NULL){
      return false;
    }
  }
return true;
}
void display()  //Displays Elements Of Stack
{
  for(i=0;i<=top;i++)
    printf("%c",a[i]->label);
}

TREE* stack(){
return a;
}

TREE makeNode0(char x) {
  TREE root;
  root = (TREE) malloc(sizeof(struct NODE)); 
  root->label = x;
  root->leftmostChild = NULL; 
  root->rightSibling = NULL;
      return root;
}
  
TREE makeNode2(char x, TREE t1, TREE t2){
  TREE root;
  root = makeNode0(x); 
  root->leftmostChild = t1;
  t1->rightSibling=t2; 
  return root;
}

TREE makeNode1(char x, TREE t) {
  TREE root;
  root = makeNode0(x); 
  root->leftmostChild = t; 
  return root;
}
  
TREE makeNode3(char x, TREE t1, TREE t2, TREE t3) {
  TREE root;
  root = makeNode1(x, t1); 
  t1->rightSibling = t2; 
  t2->rightSibling = t3; 
  return root;
}
TREE makeNode4(char x, TREE t1, TREE t2, TREE t3, TREE t4) {
TREE root;
root = makeNode1(x, t1); t1->rightSibling = t2; t2->rightSibling = t3; t3->rightSibling = t4; return root;
}
// TREE B() {
// TREE firstB, secondB;
// if(*nextTerminal == '(') /* follow production 2 */ { 
// nextTerminal++;
// firstB = B();
// if(firstB != FAILED && *nextTerminal == ')') {
// nextTerminal++; secondB = B(); if(secondB == FAILED)
//                      return FAILED;
//                  else
// return makeNode4('B', makeNode0('('),
// firstB, makeNode0(')'), secondB);
// }
// else /* first call to B failed */
//                  return FAILED;
// }
// else /* follow production 1 */
// return makeNode1('B', makeNode0('e'));
// }

  // <E> -> <T><K>
  //multiplication and division production 

// char is Digit from 0 to 9
TREE D () {
	for (int i = 0; i < 10; i++) {
		if (*nextTerminal == term [i]) {
			nextTerminal++;
			return makeNode1 ('D',makeNode0(term[i])); //TODO
		}
	}
	return FAILED;
}

//<X> -> <N> | e
TREE X() {
 TREE n;
 if(*nextTerminal=='\0'){
   return makeNode1('X',makeNode0('e'));
 }  
 n = N();
 if (n!= FAILED) {
  return makeNode1('X',n);
 } else {
  return makeNode1('X',makeNode0('e'));
 }
}
//<C> ->sincos<N>|<N>
TREE C(){
  TREE n;
  if(*nextTerminal=='s'){
   nextTerminal++;
   if(*nextTerminal=='i'){
   nextTerminal++;
   if(*nextTerminal=='n'){
   nextTerminal++;
   n=N();
   if(n!=FAILED){
    return makeNode4('C',makeNode0('s'),makeNode0('i'),makeNode0('n'),n);
   }else{
    return FAILED;
   }
  }
}
  return FAILED;
  }else if(*nextTerminal=='c'){
   nextTerminal++;
   if(*nextTerminal=='o'){
   nextTerminal++;
   if(*nextTerminal=='s'){
   nextTerminal++;
   n=N();
   if(n!=FAILED){
    return makeNode4('C',makeNode0('c'),makeNode0('o'),makeNode0('s'),n);
   }else{
    return FAILED;
   }
  }
}
  return FAILED;
  }else{
   n=N();
   if(n!=FAILED){
    return makeNode1('C', n);
   }else{
    return FAILED;
   }
  }
}
//<N> -> <D><X>
TREE N() {
 TREE d,x;
 d = D();
 if (d != FAILED) {
 	x = X();
 	if (x != FAILED) {
 		return makeNode2 ('N',d,x);
 	} else {
 		return FAILED;
 	}
 } else {
 	return FAILED;
 }
}
//<F> -> (<E>) | <N>
TREE F() {
	TREE e,c;
 if (*nextTerminal== '(') {
 	nextTerminal++;
   e=E();
   if (e != FAILED) {
   	 if (*nextTerminal == ')') {
   	 	nextTerminal++;
   	 	return makeNode3('F',makeNode0('('),e,makeNode0(')'));
   	 } else {
   	 	return FAILED;
   	 }
   } else {
   	return FAILED;
   }
 } else {
   c = C();
   if (c != FAILED) {
    return makeNode1('F',c);
   } else {
   	return FAILED;
   }
 }
}

//<M> -> *<F><M> | /<F><M> | e
TREE M() {
	TREE f,m;
  if(*nextTerminal == '\0'){
    return makeNode1('M',makeNode0('e'));
  }
   if (*nextTerminal == '*') {
   	nextTerminal++;
    f = F();
    if (f != FAILED) {
    	m = M();
    	if (m!=FAILED) {
    		return makeNode3('M',makeNode0('*'),f,m);
    	} else {
        return FAILED;
      }
    } else {
      return FAILED;
    }
   } else if (*nextTerminal== '/') {
   	nextTerminal++;
     f = F();
    if (f != FAILED) {
    	m = M();
    	if (m!=FAILED) {
    		return makeNode3('M',makeNode0('/'),f,m);
    	} else {
        return FAILED;
      }
    } else {
      return FAILED;
    }
   } else {
   	return makeNode1('M',makeNode0('e')); //TODO check here
   }
  }

//<T> -> <F><M>
TREE T () {
 TREE f,m;
 f =  F();
 if (f != FAILED) {
 	m =  M();
 	if (m!= FAILED){
 		return makeNode2('T',f,m);
 	} else {
 		return FAILED;
 	}

 } else {
  return FAILED;
 }
}

//<K> -> +<T><K> | -<T><K> | e
  //improve this method
TREE K () {
   TREE t,k;
    if(*nextTerminal == '\0'){
    return makeNode1('K',makeNode0('e'));
  }
   if (*nextTerminal== '+') {
   	nextTerminal++;
   	 t = T();
   	if (t != FAILED) {
   		k = K();
   		if (k != FAILED) {
   			return makeNode3('K',makeNode0('+'),t,k);
   		} else {
   			return FAILED;
   		} 
   	} else {
   			return FAILED;
   		}	
   } else if (*nextTerminal == '-') {
   	nextTerminal++;
   	 t = T();
   	if (t != FAILED) {
   		k = K();
   		if (k != FAILED) {
   			return makeNode3('K',makeNode0('-'),t,k);
   		} else {
   			return FAILED;
   		} 
   	} else {
   			return FAILED;
   		}
   } else {

   	  return makeNode1 ('K',makeNode0('e'));
   }
}
TREE E() {
	TREE t, k;
	t = T();
  if (t != FAILED) {
  	k = K();
  	if (k != FAILED) {
  		return makeNode2('E',t,k);//TODO makeNode2
  	} else {
  		return FAILED;
  	}
  } else {
  	return FAILED;
  }
}


// char is Digit from 0 to 9
TREE D1 (TREE root,char part) {
  if(part=='0'){
    return FAILED;
  }else{
  for (int i = 0; i < 10; i++) {
    if (*nextTerminal == term [i]) {
      nextTerminal++;
      root->leftmostChild=makeNode0(term[i]);
      return makeNode1 ('D',makeNode0(term[i])); //TODO
    }
  }
  return FAILED;
}
}

//<X> -> <C> | e
TREE X1(TREE root,char part) {
  if(part=='e'){
root->leftmostChild=makeNode0('e');
return makeNode1('X',makeNode0('e'));
  }else{
    TREE new=makeNode0('N');
    push(new);
 root->leftmostChild=new;
 return new;

 }
}
//<C> ->sincos<N>|<N>
TREE C1(TREE root, char part){
  TREE n=makeNode0('N');
  if(part=='1'){
   nextTerminal++;
   if(*nextTerminal=='i'){
   nextTerminal++;
   }
  if(*nextTerminal=='n'){
   nextTerminal++;
   root->leftmostChild=makeNode4('C',makeNode0('s'),makeNode0('i'),makeNode0('n'),n);
   push(n);
   return makeNode0('s');
   }
  return FAILED;
  }else if(part=='2'){
     nextTerminal++;
   if(*nextTerminal=='o'){
   nextTerminal++;
   }
  if(*nextTerminal=='s'){
   nextTerminal++;
   root->leftmostChild=makeNode4('C',makeNode0('c'),makeNode0('o'),makeNode0('s'),n);
   push(n);
   return makeNode0('c');
   }
  return FAILED;

  }else{
  root->leftmostChild=n;
   push(n);
   return makeNode0('n');
  }
}
//<N> -> <D><X>
TREE N1(TREE root,char part) {
  if(part=='0'){
    return FAILED;
  }else{
 TREE d,x;
 d = makeNode0('D');
 x = makeNode0('X');
 root->leftmostChild=d;
 d->rightSibling=x;
 push(x);
 push(d);
 return d;
}
}
//<F> -> (<E>) | <N>
TREE F1(TREE root,char part) {
  if(part=='0'){
    return FAILED;
  }else if(part=='2'){
    nextTerminal++;
    TREE l=makeNode0('(');
        root->leftmostChild=l;
        TREE new=makeNode0('E');
        l->rightSibling=new;
        TREE new1=makeNode0(')');
        new->rightSibling=new1;
        push(new1);
        push(new);
return new;
  }else{
TREE new=makeNode0('C');
push(new);
root->leftmostChild=new;
return new;
  }
  
}

//<M> -> *<F><M> | /<F><M> | e
TREE M1(TREE root,char part) {
  if(part=='e'){
    TREE new=makeNode0('e');
    root->leftmostChild=new;
    return new;
  }else if(part=='1'){
    nextTerminal++;
    TREE l=makeNode0('*');
    root->leftmostChild=l;
    TREE new=makeNode0('F');
    TREE r=makeNode0('M');
    l->rightSibling=new;
    new->rightSibling=r;
    push(r);
    push(new);
    return new;
  }else{
    nextTerminal++;
    TREE l=makeNode0('/');
    root->leftmostChild=l;
    TREE new=makeNode0('F');
    TREE r=makeNode0('M');
    l->rightSibling=new;
    new->rightSibling=r;
    push(r);
    push(new);
    return new;
  }
  
  }

//<T> -> <F><M>
TREE T1 (TREE root,char part) {
  if(part=='0'){
    return FAILED;
  }else{
    TREE l=makeNode0('F');
    TREE r=makeNode0('M');
    root->leftmostChild=l;
    l->rightSibling=r;
    push(r);
    push(l);
    return l;
  }
 
}

//<K> -> +<T><K> | -<T><K> | e
  //improve this method
TREE K1(TREE root,char part) {
  if(part=='e'){
    TREE new=makeNode0('e');
    root->leftmostChild=new;
     return new;
  }else if(part=='1'){
    nextTerminal++;
    TREE l=makeNode0('+');
    root->leftmostChild=l;
    TREE new=makeNode0('T');
    TREE r=makeNode0('K');
    l->rightSibling=new;
    new->rightSibling=r;
    push(r);
    push(new);
    return r;
  }else{
    nextTerminal++;
    TREE l=makeNode0('-');
    root->leftmostChild=l;
    TREE new=makeNode0('T');
    TREE r=makeNode0('K');
    l->rightSibling=new;
    new->rightSibling=r;
    push(r);
    push(new);
    return r;
  }
  
}
TREE E1(TREE root,char part) {
  if(part=='0'){
    return FAILED;
  }else{
    TREE t=makeNode0('T');
    TREE k=makeNode0('K');
    root->leftmostChild=t;
    t->rightSibling=k;
    push(k);
    push(t);
    return k;
  }

}

// int lookahed (char c) {
//  return *nextInputChar == c;
// } 

