/* Project1 CSC173
 * Contributor: Wenyi Chu && Xiaoyu Zheng
 */

#include <stdio.h> 
#include <stdlib.h>
#include "dfa.h"

#ifndef _dfa_h
#define _dfa_h


DFA *DFA_new(int nstates){
	DFA *dfa = (DFA*)malloc(sizeof(DFA)); 
    dfa->nstates = nstates;  
    dfa->current_state = 0;
    dfa->states = (DFA_State*)malloc(nstates*sizeof(DFA_State)); 
    for(int i=0; i<nstates; i++) {
    	dfa->states[i].is_accepting = false;
    } 
    for (int i=0; i<nstates; i++) {
    	for(int j=0; j<DFA_NSYMBOLS; j++) {
    		dfa->states[i].transitions[j]=DFA_NO_TRANSITION;
    	}
    } 
    return dfa;  
};

void DFA_free(DFA *dfa){
    free(dfa->states);
    free(dfa); //free dfa
}

int DFA_get_size(DFA *dfa);

int DFA_get_transition(DFA *dfa, int statenum, char symbol){
	return  dfa->states[statenum].transitions[symbol];
}

void DFA_set_transition(DFA *dfa, int src, char symbol, int dst){
	dfa->states[src].transitions[symbol] = dst;
}

void DFA_set_transition_str(DFA *dfa, int src, char *str, int dst);

// no matter the input is, go to the state offered as parameter.
void DFA_set_transition_all(DFA *dfa, int src, int dst){
    for(int i=0; i<DFA_NSYMBOLS; i++){
        dfa->states[src].transitions[i] = dst;
    }
}

int DFA_get_current_state(DFA *dfa){
    return dfa->current_state;
}
void DFA_set_current_state(DFA *dfa, int statenum){
	dfa->current_state = statenum;
}
bool DFA_get_accepting(DFA *dfa, int statenum){
	return dfa->states[statenum].is_accepting;
}
void DFA_set_accepting(DFA *dfa, int statenum, bool value){
	dfa->states[statenum].is_accepting = value;
}
bool DFA_is_accepting(DFA *dfa){
    return DFA_get_accepting(dfa, dfa->current_state); 
}

bool DFA_execute(DFA *dfa, char *input){
	for (int i=0; input[i]!='\0'; i++){
        // printf("%s\n","For this input string, I am dealing with: ");
        // printf("%c\n",input[i]);
		DFA_set_current_state(dfa, DFA_get_transition(dfa, DFA_get_current_state(dfa), input[i]));
        // printf("%s\n","After this, I am in the state: ");
        // printf("%d\n",dfa->current_state);
	}
    // finishing all the transitions, check if the final state is an accepting state and return
	return DFA_is_accepting(dfa);
	
}
void DFA_print(DFA *dfa);

#endif

// int main () {
//     printf("%s\n","Hello World: Part1 Problem1");
//     DFA *ab = DFA_new(3);
//     DFA_set_transition(ab, 0, 'a', 1);
//     DFA_set_transition(ab, 1, 'b', 2);
//     DFA_set_accepting(ab, 2, true);
//     printf("%d\n", DFA_execute(ab, "ab"));

//     printf("%s\n","Hello World: Part1 Problem2");
//     DFA *start_with_ab = DFA_new(3);
//     DFA_set_transition(start_with_ab, 0, 'a', 1);
//     DFA_set_transition(start_with_ab, 1, 'b', 2);
//     DFA_set_transition_all(start_with_ab, 2, 2); //loop to itself with all inputs
//     DFA_set_accepting(start_with_ab, 2, true);
//     printf("%d\n", DFA_execute(start_with_ab, "abc"));


//     printf("%s\n","Hello World: Part1 Problem3");
//     DFA *even_1 = DFA_new(2);
//     DFA_set_transition(even_1, 0, '0', 0);
//     DFA_set_transition(even_1, 0, '1', 1);
//     DFA_set_transition(even_1, 1, '0', 1);
//     DFA_set_transition(even_1, 1, '1', 0);
//     DFA_set_accepting(even_1, 0, true);
//     printf("%d\n", DFA_execute(even_1, "011"));


//     printf("%s\n","Hello World: Part1 Problem4");
//     DFA *even0_even_1 = DFA_new(4);
//     DFA_set_transition(even0_even_1, 0, '0', 1);
//     DFA_set_transition(even0_even_1, 0, '1', 3);
//     DFA_set_transition(even0_even_1, 1, '0', 0);
//     DFA_set_transition(even0_even_1, 1, '1', 2);
//     DFA_set_transition(even0_even_1, 2, '0', 3);
//     DFA_set_transition(even0_even_1, 2, '1', 1);
//     DFA_set_transition(even0_even_1, 3, '0', 2);
//     DFA_set_transition(even0_even_1, 3, '1', 0);
//     DFA_set_accepting(even0_even_1, 0, true);
//     printf("%d\n", DFA_execute(even0_even_1, "0110"));


//     printf("%s\n","Hello World: Part1 Problem5");
//     DFA *customized = DFA_new(4);
//     DFA_set_transition(customized, 0, 'a', 1);
//     DFA_set_transition(customized, 0, 'c', 2);
//     DFA_set_transition(customized, 1, 'b', 3);
//     DFA_set_transition(customized, 2, 'a', 3);
//     DFA_set_transition_all(customized, 3, 3); //loop to itself with all inputs
//     DFA_set_accepting(customized, 3, true);
//     printf("%d\n", DFA_execute(customized, "california"));


//     return 0;

// }
