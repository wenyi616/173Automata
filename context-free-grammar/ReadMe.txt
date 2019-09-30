/* Project2 CSC173
 * Contributor: Wenyi Chu && Xiaoyu Zheng
 */


a. Collaborators:
	Wenyi Chu <wchu6@u.rochester.edu>		
	Xiaoyu Zheng <xzheng10@u.rochester.edu> 	
---------------------------------------------------------------------------------

b. How to build your project:
	We had multiple files:
	
	main.c | Where the programs were connected; Allows for selecting to test part 1/2/3; Allows for reading input successively from user(please see the sample output below)
	
	Node.c | We defined and implemented the node in this file
	
	parse.c and parse.h | Part1, recursive decent parser
	
	printTree.c and printTree.c | Using the file to print a standardized output
		
---------------------------------------------------------------------------------

c. How to run our code?
	We made a Makefile in advance. 
	Download our zip file and navigate it to the folder in the terminal.
	Enter “Make” to the terminal and follow the procedure.
	
	Basically, you just follow the prompts,
	"Hello World: Enter 1 or 2 or 3 to test Part 1 or 2 or 3: ”
	>>> enter 1 for example
	“Hello World: Enter an expression to test, or QUIT to quit”
	>>> enter an input. 1*20+sin30 for example

---------------------------------------------------------------------------------

d. The grammar for arithmetic algorithm is:
<D> -> 0|1|2|…|9
<X> -> <N> | e		<x> aka <NT>
<N> -> <D><X>		
<F> -> (<E>) | <N>		
<M> -> *<F><M> | /<F><M> | e		<M> aka <FT>
<T> -> <F><M>
<K> -> +<T><K> | -<T><K> | e		<K> aka <TT>
<E> -> <T><TT>

Our parsing table would be:
	'0','0','0','0','0','0','1','0','1','1',
	'e','e','1','2','e','e','e','e','e','e',
	'0','0','0','0','0','0','1','0','1','1',
	'e','e','e','e','1','2','e','e','e','e',
	'2','0','0','0','0','0','1','0','1','1',
	'0','0','0','0','0','0','1','0','0','0',
	'e','e','e','e','e','e','1','e','0','0',
	'0','0','0','0','0','0','1','0','0','0',
	'0','0','0','0','0','0','3','0','1','2',

---------------------------------------------------------------------------------

e. A sample output would be:
Sampe1 to test part1
        Hello World: Enter 1 or 2 or 3 to test Part 1 or 2 or 3: 
        1
        Hello World: Enter an expression to test, or QUIT to quit
        1+2
        >>> Testing part1 >>> Your input is: 1+2
        E
         T
          N
           N
            D
             1
            X
             e
          M
           e
         K
          +
          T
           N
            N
             D
              2
             X
              e
           M
            e
          K
           e
        
        Hello World: Enter an expression to test, or QUIT to quit
        QUIT
        QUIT detected. Program finished.

Sample 2 to test part2:
        Hello World: Enter 1 or 2 or 3 to test Part 1 or 2 or 3: 
        2
        Hello World: Enter an expression to test, or QUIT to quit
        1+2
        >>> Testing part1 >>> Your input is: 1+2
        E
         T
          N
           N
            D
             1
            X
             e
          M
           e
         K
          +
          T
           N
            N
             D
              2
             X
              e
           M
            e
          K
           e
        
        Hello World: Enter an expression to test, or QUIT to quit
        QUIT
        QUIT detected. Program finished.

Sample3 to test part 3:
	Hello World: Enter 1 or 2 or 3 to test Part 1 or 2 or 3: 
	3
	Hello World: Enter an expression to test, or QUIT to quit
	1+2
	>>> Testing part3 >>> Your input is: 1+2
	Start calculationg.
	connected
	1+2
	3.000000
	QUIT
	QUIT detected. Program finished.

---------------------------------------------------------------------------------
f. We did all three extra credits tasks:

Builtin functions are achieved in this program. Sin() function for example.
A sample input would be: sin2/7
A sample output would be:

Hello World: Enter 1 or 2 or 3 to test Part 1 or 2 or 3: 
1
Hello World: Enter an expression to test, or QUIT to quit
sin2/7
>>> Testing part1 >>> Your input is: sin2/7
E
 T
  N
   C
    s
    i
    n
    N
     D
      2
     X
      e
  M
   /
   N
    C
     N
      D
       7
      X
       e
   M
    e
 M
  e
QUIT
---------
Hello World: Enter an expression to test, or QUIT to quit
1+29*1
>>> Testing part3 >>> Your input is: 1+29*1
E
 T
  F
   C
    N
     D
      1
     X
      e
  M
   e
 K
  +
  T
   F
    C
     N
      D
       2
      X
       N
        D
         9
        X
         e
   M
    *
    F
     C
      N
       D
        1
       X
        e
    M
     e
  K
   e
Start calculating: 30.000000
QUIT
QUIT detected. Program finished.
And others are explained in the comment with the code. 
