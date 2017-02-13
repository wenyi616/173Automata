/* Project1 CSC173
 * Contributor: Wenyi Chu && Xiaoyu Zheng
 */


a. Collaborators:
	Wenyi Chu <wchu6@u.rochester.edu>		School ID:29426966
	Xiaoyu Zheng <xzheng10@u.rochester.edu> 	School ID:29789009

b. How to build your project:
	We used “dfa.h” “nfa.h” ”IntSet.c” from the sample code offered by Professor Ferguson.
	We constructed our own “dfa.c” “nfa.c” “nfa_dfa.c” and “main.c” files. 
	1. “dfa.c”: defines the data structure of a DFA 
	2. “nfa.c”: defines the data structure of a NFA
	3. “nfa_dfa.c”: we take an instance of NFA as an input and return an instance of DFA and both of them accept the same language tested in the “main.c” file.
	4. “main.c”: in this file, we had a main function, in which we created instances of DFA/NFA, specifically set transitions for each pattern, and execute to test whether the input string would be accepted by this automata. For part 3 of the project, we take three (“man” and “Washington” and one more customized NFA) instances of NFA defined in the previous question as inputs, and accordingly get three instances of DFA and test them accordingly. 

c. How to run our code?
	We made a Makefile in advance. 
	Download our zip file and navigate it to the folder in the terminal.
	Enter “Make” to the terminal and follow the procedure.

d. A sample output would be:

Hello World: Enter 1 or 2 or 3 to test Part 1 or 2 or 3: 
>> 1
Hello World: Part1; Enter 1 or 2 or 3 or 4 or 5 to test each small problem: 
>> 1
Hello World: Enter a string to test: (a sample input would be ab or abb)
>> ab
For this string: ab, the result is: 
>> 1
