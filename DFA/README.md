# Overview
Contributor: Wenyi Chu && Xiaoyu Zheng<br>

This is the folder for CSC173 Project1, which consists of 3 parts:
- Implement a data structure representing a DFA(determinate finite automata)
- Implement a data structure representing an NFA(non-determinate finite automata)
- Implement a "translator" which accepts an NFA as the input and generate(return) a DFA


How to build your project:
1. “dfa.c” defines the data structure of a DFA; “nfa.c” defines the data structure of a NFA <br>; in “nfa_dfa.c”, we take an instance of NFA as an input and return an instance of DFA and both of them accept the same language tested in the “main.c” file. “main.c” handles the main function, in which we created instances of DFA/NFA, specifically set transitions for each pattern, and execute to test whether the input string would be accepted by this automata. For part 3 of the project, we take three (“man” and “Washington” and one more customized NFA) instances of NFA defined in the previous question as inputs, and accordingly get three instances of DFA and test them accordingly.

How to run our code?
Download our zip file and navigate it to the folder in the terminal.<br>
> Make 
and then follow the procedures


Sample output:
Hello World: Enter 1 or 2 or 3 to test Part 1 or 2 or 3: 
1
Hello World: Part1; Enter 1 or 2 or 3 or 4 or 5 to test each small problem:
1
Hello World: Enter a string to test: (a sample input would be ab or abb)
ab
For this string: ab, the result is:
1
