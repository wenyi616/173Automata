/* Project1 CSC173
 * Contributor: Wenyi Chu && Xiaoyu Zheng
 */

#include <stdio.h>
#include <stdlib.h>
#include "IntSet.h"
#include "nfa.h"


#ifndef _nfa_h
#define _nfa_h


NFA *NFA_new(int nstates){
	NFA *nfa = (NFA*)malloc(sizeof(NFA)); /*frees space for the dfa*/
    nfa->nstates = nstates;  

    // sets starting state to {0}
    IntSet *start_state;
    start_state = IntSet_new();
    IntSet_add(start_state,0);
    nfa->current_states = start_state; 

    nfa->states = (NFA_State*)malloc(nstates*sizeof(NFA_State)); 
    for(int i=0; i<nstates; i++) {
    	nfa->states[i].is_accepting = false;
    } 

    // initialize all the subsets as empty set
    for (int i=0; i<nstates; i++) {
    	for(int j=0; j<NFA_NSYMBOLS; j++) {
    		IntSet *emptyset;
    		emptyset = IntSet_new();
    		nfa->states[i].transitions[j]=emptyset;
    	}
    } 
    return nfa; 
}


void NFA_free(NFA *nfa){
    for (int i = 0; i < nfa->nstates; i++) {
        NFA_State *state = &nfa->states[i]; 
        for (int k = 0; k < NFA_NSYMBOLS; k++) {
            IntSet_free(state->transitions[k]); 
        }
    }
    IntSet_free(nfa->current_states);
    free(nfa->states); 
    free(nfa); // free the nfa
};

int NFA_get_size(NFA *nfa){
    return nfa->nstates;
};

// return a set of possible states, for example: {0, 1}
// those sets are initially set to empty set {}
IntSet *NFA_get_transitions(NFA *nfa, int statenum, char symbol){
	return nfa->states[statenum].transitions[symbol];
}

void NFA_add_transition(NFA *nfa, int src, char symbol, int dst){
    IntSet_add(nfa->states[src].transitions[symbol], dst);
};
void NFA_add_transition_str(NFA *nfa, int src, char *str, int dst){
    for(int i=0;i<str[i]!='\0';i++){
         IntSet_add(nfa->states[src].transitions[str[i]], dst);
    }
};
void NFA_add_transition_all(NFA *nfa, int src, int dst){
    for(int i=0; i<NFA_NSYMBOLS; i++){
        IntSet_add(nfa->states[src].transitions[i], dst);
    }
};

IntSet *NFA_get_current_states(NFA *nfa){
    return nfa->current_states;
}

// add a set of states into the exsiting set of states
void NFA_set_current_states(NFA *nfa, IntSet *states){
    //IntSet_union(NFA_get_current_states(nfa), states);
    nfa->current_states = states;
}
// add one state into the set of states
void NFA_set_current_state(NFA *nfa, int state){
    IntSet_add(nfa->current_states, state);
}

bool NFA_get_accepting(NFA *nfa, int statenum){
return nfa->states[statenum].is_accepting;
};
void NFA_set_accepting(NFA *nfa, int statenum, bool value){
    nfa->states[statenum].is_accepting = value;
};

bool NFA_is_accepting(NFA *nfa){
	//return IntSet_contains(NFA_get_current_states(nfa), TRUE);
    // The one above is wrong... Here is the correct one: 

    // iterate thourgh the current states to see if there's an accpecting state
    IntSetIterator *itt;
    itt = IntSet_iterator(NFA_get_current_states(nfa));
    while(IntSetIterator_has_next(itt)){
        int statenum;
        statenum = IntSetIterator_next(itt);
        if(nfa->states[statenum].is_accepting){
            return true;
        }
    } 
    free(itt);
    return false;
};

bool NFA_execute(NFA *nfa, char *input){
	for (int i=0; input[i]!='\0'; i++){
        
        // new an empty set
        IntSet *states = IntSet_new();

        // iterate thourgh the current states
        // and analyze each state inside the set
        IntSetIterator *it;
        it = IntSet_iterator(NFA_get_current_states(nfa));
        while(IntSetIterator_has_next(it)){
            int statenum;
            statenum = IntSetIterator_next(it);

            // TEST: 
            // printf("%s\n","Print out the current states I am dealing now: ");
            // printf("%d\n", statenum);

            // union the teansitions on each state
            IntSet_union(states, NFA_get_transitions(nfa, statenum, input[i]));
        } 

        NFA_set_current_states(nfa, states);    
    }
    // TEST: 
    // printf("%s\n","Print out the current states(Final states): ");
    // IntSet_print(NFA_get_current_states(nfa));

	return NFA_is_accepting(nfa);
}

// True to enable tracing during NFA_Execute
int NFA_tracing;

#endif

// int main () {
//     // Strings ending in man
//     printf("%s\n","Hello World: Part2 Problem1");
//     NFA *end_with_man = NFA_new(4);

//     NFA_add_transition(end_with_man, 0, 'm', 1);
//     NFA_add_transition(end_with_man, 1, 'a', 2);
//     NFA_add_transition(end_with_man, 2, 'n', 3);
//     NFA_add_transition_all(end_with_man, 0, 0);

//     NFA_set_accepting(end_with_man, 3, true);
//     printf("%d\n", NFA_execute(end_with_man, "hhhman"));



//     // Strings with more than one a, g, h, i, o, s, t, or w, or more than two n’s. 
//     printf("%s\n","Hello World: Part2 Problem2");
//     NFA *aghiostwnn = NFA_new(20);

//     NFA_add_transition_all(aghiostwnn, 0, 0);
//     NFA_add_transition(aghiostwnn, 0, 'a', 1);
//     NFA_add_transition_all(aghiostwnn, 1, 1);
//     NFA_add_transition(aghiostwnn, 1, 'a', 2);
//     NFA_add_transition_all(aghiostwnn, 2, 2);
//     NFA_add_transition(aghiostwnn, 0, 'g', 3);
//     NFA_add_transition_all(aghiostwnn, 3, 3);
//     NFA_add_transition(aghiostwnn, 3, 'g', 4);
//     NFA_add_transition_all(aghiostwnn, 4, 4);
//     NFA_add_transition(aghiostwnn, 0, 'h', 5);
//     NFA_add_transition_all(aghiostwnn, 5, 5);
//     NFA_add_transition(aghiostwnn, 5, 'h', 6);
//     NFA_add_transition_all(aghiostwnn, 6, 6);
//     NFA_add_transition(aghiostwnn, 0, 'i', 7);
//     NFA_add_transition_all(aghiostwnn, 7, 7);
//     NFA_add_transition(aghiostwnn, 7, 'i', 8);
//     NFA_add_transition_all(aghiostwnn, 8, 8);
//     NFA_add_transition(aghiostwnn, 0, 'n', 9);
//     NFA_add_transition_all(aghiostwnn, 9, 9);
//     NFA_add_transition(aghiostwnn, 9, 'n', 10);
//     NFA_add_transition_all(aghiostwnn, 10, 10);
//     NFA_add_transition(aghiostwnn, 10, 'n', 11);
//     NFA_add_transition_all(aghiostwnn, 11, 11);
//     NFA_add_transition(aghiostwnn, 0, 'o', 12);
//     NFA_add_transition_all(aghiostwnn, 12, 12);
//     NFA_add_transition(aghiostwnn, 12, 'o', 13);
//     NFA_add_transition_all(aghiostwnn, 13, 13);
//     NFA_add_transition(aghiostwnn, 0, 's', 14);
//     NFA_add_transition_all(aghiostwnn, 14, 14);
//     NFA_add_transition(aghiostwnn, 14, 's', 15);
//     NFA_add_transition_all(aghiostwnn, 15, 15);
//     NFA_add_transition(aghiostwnn, 0, 't', 16);
//     NFA_add_transition_all(aghiostwnn, 16, 16);
//     NFA_add_transition(aghiostwnn, 16, 't', 17);
//     NFA_add_transition_all(aghiostwnn, 17, 17);
//     NFA_add_transition(aghiostwnn, 0, 'w', 18);
//     NFA_add_transition_all(aghiostwnn, 18, 18);
//     NFA_add_transition(aghiostwnn, 18, 'w', 19);
//     NFA_add_transition_all(aghiostwnn, 19, 19);

//     NFA_set_accepting(aghiostwnn, 2, true);
//     NFA_set_accepting(aghiostwnn, 4, true);
//     NFA_set_accepting(aghiostwnn, 6, true);
//     NFA_set_accepting(aghiostwnn, 8, true);
//     NFA_set_accepting(aghiostwnn, 11, true);
//     NFA_set_accepting(aghiostwnn, 13, true);
//     NFA_set_accepting(aghiostwnn, 15, true);
//     NFA_set_accepting(aghiostwnn, 17, true);
//     NFA_set_accepting(aghiostwnn, 19, true);

//     printf("%d\n", NFA_execute(aghiostwnn, "aa"));


//     // Strings in the format: abcxxxx (x can only be a or b or c)
//     printf("%s\n","Hello World: Part2 Problem3");
//     NFA *abc = NFA_new(4);
//     NFA_add_transition(abc, 0, 'a', 0);
//     NFA_add_transition(abc, 0, 'b', 0);
//     NFA_add_transition(abc, 0, 'c', 0);
//     NFA_add_transition(abc, 0, 'a', 1);
//     NFA_add_transition(abc, 1, 'b', 2);
//     NFA_add_transition(abc, 2, 'c', 3);
//     NFA_add_transition(abc, 3, 'a', 3);
//     NFA_add_transition(abc, 3, 'b', 3);
//     NFA_add_transition(abc, 3, 'c', 3);

//     NFA_set_accepting(abc, 3, true);
//     printf("%d\n", NFA_execute(abc, "abca"));



//    	return 0;
// }
