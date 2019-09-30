# Overview
Project2 CSC173<br>
Contributor: Wenyi Chu && Xiaoyu Zheng<br>


# a. Collaborators:<br>
	Wenyi Chu <wchu6@u.rochester.edu>	<br>
	Xiaoyu Zheng <xzheng10@u.rochester.edu> <br>

# b. How to build your project:<br>
	We had multiple files: <br>
	
	main.c | Where the programs were connected; Allows for selecting to test part 1/2/3; Allows for reading input successively from user(please see the sample output below) <br>
	
	Node.c | We defined and implemented the node in this file <br>
	
	parse.c and parse.h | Part1, recursive decent parser <br>
	
	printTree.c and printTree.c | Using the file to print a standardized output <br>

# c. How to run our code?<br>
	We made a Makefile in advance. <br>
	Download our zip file and navigate it to the folder in the terminal. <br>
	Enter “Make” to the terminal and follow the procedure. <br>
	
	Basically, you just follow the prompts, <br>
	"Hello World: Enter 1 or 2 or 3 to test Part 1 or 2 or 3: ” <br>
	>>> enter 1 for example <br>
	“Hello World: Enter an expression to test, or QUIT to quit” <br>
	>>> enter an input. 1*20+sin30 for example <br>


# d. Grammar and Parsing Table <br>
	The grammar for arithmetic algorithm is: <br>
	<D> -> 0|1|2|…|9 <br>
	<X> -> <N> | e		<x> aka <NT> <br>
	<N> -> <D><X>		 <br>
	<F> -> (<E>) | <N>		 <br>
	<M> -> *<F><M> | /<F><M> | e		<M> aka <FT> <br>
	<T> -> <F><M> <br>
	<K> -> +<T><K> | -<T><K> | e		<K> aka <TT> <br>
	<E> -> <T><TT> <br>

# e. A sample output would be:<br>
Sampe1 to test part1<br>
        Hello World: Enter 1 or 2 or 3 to test Part 1 or 2 or 3: <br>
        1<br>
        Hello World: Enter an expression to test, or QUIT to quit
        1+2<br>
        >>> Testing part1 >>> Your input is: 1+2<br>
        E<br>
         T<br>
          N<br>
           N<br>
            D<br>
             1<br>
            X<br>
             e<br>
          M<br>
           e<br>
         K<br>
          +<br>
          T
           N<br>
            N<br>
             D<br>
              2<br>
             X<br>
              e<br>
           M<br>
            e<br>
          K<br>
           e<br>
        
        Hello World: Enter an expression to test, or QUIT to quit<br>
        QUIT<br>
        QUIT detected. Program finished.<br>

Sample 2 to test part2:<br>
        Hello World: Enter 1 or 2 or 3 to test Part 1 or 2 or 3: <br>
        2<br>
        Hello World: Enter an expression to test, or QUIT to quit<br>
        1+2<br>
        >>> Testing part1 >>> Your input is: 1+2<br>
        E<br>
         T<br>
          N<br>
           N<br>
            D<br>
             1<br>
            X<br>
             e<br>
          M<br>
           e<br>
         K<br>
          +<br>
          T<br>
           N<br>
            N<br>
             D<br>
              2<br>
             X<br>
              e<br>
           M<br>
            e<br>
          K<br>
           e<br>
        
        Hello World: Enter an expression to test, or QUIT to quit<br>
        QUIT<br>
        QUIT detected. Program finished.<br>

Sample3 to test part 3:<br>
	Hello World: Enter 1 or 2 or 3 to test Part 1 or 2 or 3: <br>
	3<br>
	Hello World: Enter an expression to test, or QUIT to quit<br>
	1+2<br>
	>>> Testing part3 >>> Your input is: 1+2<br>
	Start calculationg.<br>
	connected<br>
	1+2<br>
	3.000000<br>
	QUIT<br>
	QUIT detected. Program finished.<br>

# f. Extra credits tasks:<br>

Builtin functions are achieved in this program. Sin() function for example.<br>
A sample input would be: sin2/7<br>
A sample output would be:<br>

Hello World: Enter 1 or 2 or 3 to test Part 1 or 2 or 3: <br>
1<br>
Hello World: Enter an expression to test, or QUIT to quit<br>
sin2/7<br>
>>> Testing part1 >>> Your input is: sin2/7<br>
E<br>
 T<br>
  N<br>
   C<br>
    s<br>
    i<br>
    n<br>
    N<br>
     D<br>
      2<br>
     X<br>
      e<br>
  M<br>
   /<br>
   N<br>
    C<br>
     N<br>
      D<br>
       7<br>
      X<br>
       e<br>
   M<br>
    e<br>
 M<br>
  e<br>
QUIT<br>
<br>
Hello World: Enter an expression to test, or QUIT to quit<br>
1+29*1<br>
>>> Testing part3 >>> Your input is: 1+29*1<br>
E<br>
 T<br>
  F<br>
   C<br>
    N<br>
     D<br>
      1<br>
     X<br>
      e<br>
  M<br>
   e<br>
 K<br>
  +<br>
  T<br>
   F<br>
    C<br>
     N<br>
      D<br>
       2<br>
      X<br>
       N<br>
        D<br>
         9<br>
        X<br>
         e<br>
   M<br>
    *<br>
    F<br>
     C<br>
      N<br>
       D<br>
        1<br>
       X<br>
        e<br>
    M<br>
     e<br>
  K<br>
   e<br>
Start calculating: 30.000000<br>
QUIT<br>
QUIT detected. Program finished.<br>
And others are explained in the comment with the code. <br>
