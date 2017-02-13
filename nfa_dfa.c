/* Project1 CSC173
 * Contributor: Wenyi Chu && Xiaoyu Zheng
 */

#include <stdio.h> 
#include <stdbool.h>
#include <stdlib.h>
#include "nfa.h"
#include "dfa.h"
#include "IntSet.h"

int power(int b, int a){
  int size=1;
  for(int i=0;i<b;i++){
    size=size*a;
  }
  return size;
}

DFA *NFA_to_DFA(NFA *nfa){
    int size=power(NFA_get_size(nfa),2);
    DFA *dfa=DFA_new(size);
    IntSet *set=IntSet_new();
    IntSet_add(set,0);
    dfa->states[0].content=set;
    
    if(NFA_get_accepting(nfa, 0)){
        DFA_set_accepting(dfa,0,true);
    }
    
    int stateNo=0;
    //check every state

    for(int j=0;j<size;j++){
      //try every input in states
      if(j>stateNo){
        break;
    }

    for(int i=0;i<NFA_NSYMBOLS;i++){
   
      //every state has one number and an IntSet content
      IntSet *mycontent=dfa->states[j].content;
      IntSetIterator *it;
      it = IntSet_iterator(mycontent);
      IntSet *transition=IntSet_new();
      
      while(IntSetIterator_has_next(it)){
        int statenum=IntSetIterator_next(it);
        
        //check if there is a transition. If not, break out of the input
        IntSet *check=NFA_get_transitions(nfa,statenum,i);
     
        //new transition
        IntSet_union(transition,check);
      }; 
      free(it);
     
      // if there is a transition
      //boolean to record if this state already exists
      bool repeat=false;
      
      if(IntSet_is_empty(transition)!=true){
        //check if this state exists
        for(int k=0;k<(j+1);k++){
          if(IntSet_equals(transition,dfa->states[k].content)==true){
            DFA_set_transition(dfa,j,i,k);
            repeat=true;
          }
        }

      if(repeat==false){
        //new state!
        stateNo++;
        //set transition for the new state
        DFA_set_transition(dfa,j,i,stateNo);
        //set IntSet content to the new state
        dfa->states[stateNo].content=transition;
    
      IntSetIterator *it;
      it = IntSet_iterator(transition);
      while(IntSetIterator_has_next(it)){
        int statenum=IntSetIterator_next(it);
        //if there is an accepting state in the content, accept the state
        if(NFA_get_accepting(nfa, statenum)){
          DFA_set_accepting(dfa,stateNo,true);
        }
      }
      free(it);
    }
  }  
  }
}
return dfa;
}
