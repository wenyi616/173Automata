# Overview
This is the code for CSC173 Project1; The project consists of 3 parts: <br>
Implement a data structure representing a DFA(determinate finite automata); <br>
Implement a data structure representing an NFA(non-determinate finite automata);<br>
Implement a "translator" which accepts an NFA as the input and generate(return) a DFA;<br>

# ReadMe file copied from project submission
Project1 CSC173<br>
Contributor: Wenyi Chu && Xiaoyu Zheng<br>


a. Collaborators:<br>
	Wenyi Chu <wchu6@u.rochester.edu>		School ID:29426966<br>
	Xiaoyu Zheng <xzheng10@u.rochester.edu> 	School ID:29789009<br>

b. How to build your project:<br>
	We used “dfa.h” “nfa.h” ”IntSet.c” from the sample code offered by Professor Ferguson.<br>
	We constructed our own “dfa.c” “nfa.c” “nfa_dfa.c” and “main.c” files. <br>
	1. “dfa.c”: defines the data structure of a DFA <br>
	2. “nfa.c”: defines the data structure of a NFA <br>
	3. “nfa_dfa.c”: we take an instance of NFA as an input and return an instance of DFA and both of them accept the same language tested in the “main.c” file.<br>
	4. “main.c”: in this file, we had a main function, in which we created instances of DFA/NFA, specifically set transitions for each pattern, and execute to test whether the input string would be accepted by this automata. For part 3 of the project, we take three (“man” and “Washington” and one more customized NFA) instances of NFA defined in the previous question as inputs, and accordingly get three instances of DFA and test them accordingly. <br>

c. How to run our code?<br>
	We made a Makefile in advance. <br>
	Download our zip file and navigate it to the folder in the terminal.<br>
	Enter “Make” to the terminal and follow the procedure.<br>

d. A sample output would be:<br>

Hello World: Enter 1 or 2 or 3 to test Part 1 or 2 or 3: <br>
1<br>
Hello World: Part1; Enter 1 or 2 or 3 or 4 or 5 to test each small problem: <br>
1<br>
Hello World: Enter a string to test: (a sample input would be ab or abb)<br>
ab<br>
For this string: ab, the result is: <br>
1<br>
