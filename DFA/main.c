/* Project1 CSC173
 * Contributor: Wenyi Chu && Xiaoyu Zheng
 */

#include <stdio.h> 
#include <stdlib.h>
#include "dfa.h"
#include "nfa.h"
#include "nfa_dfa.h"

int main () {
    printf("%s\n","Hello World: Enter 1 or 2 or 3 to test Part 1 or 2 or 3: ");

    char ch1;
    scanf("%c%*c", &ch1);
    if(ch1 == '1'){
        printf("%s\n","Hello World: Part1 >>> Enter 1 or 2 or 3 or 4 or 5 to test each small problem: ");
        char ch2;
        scanf("%c%*c", &ch2);
        
        if(ch2 == '1'){
            printf("%s\n","Hello World: Enter a string to test: (a sample input would be ab or abb)");
            DFA *ab = DFA_new(3);
            DFA_set_transition(ab, 0, 'a', 1);
            DFA_set_transition(ab, 1, 'b', 2);
            DFA_set_accepting(ab, 2, true);
            char ch3[20];
            scanf("%s%*c", ch3);
            printf("For this string: %s, the result is: \n",ch3);
            printf("%d\n", DFA_execute(ab, ch3));

        }else if(ch2 == '2'){
            printf("%s\n","Hello World: Enter a string to test: (a sample input would be ab or abc)");
            DFA *start_with_ab = DFA_new(3);
            DFA_set_transition(start_with_ab, 0, 'a', 1);
            DFA_set_transition(start_with_ab, 1, 'b', 2);
            DFA_set_transition_all(start_with_ab, 2, 2); //loop to itself with all inputs
            DFA_set_accepting(start_with_ab, 2, true);
            char ch3[20];
            scanf("%s%*c", ch3);
            printf("For this string: %s, the result is: \n",ch3);
            printf("%d\n", DFA_execute(start_with_ab, ch3));
        
        }else if(ch2 == '3'){
            printf("%s\n","Hello World: Enter a string to test: (a sample input would be 011 or 11)");
            DFA *even_1 = DFA_new(2);
            DFA_set_transition(even_1, 0, '0', 0);
            DFA_set_transition(even_1, 0, '1', 1);
            DFA_set_transition(even_1, 1, '0', 1);
            DFA_set_transition(even_1, 1, '1', 0);
            DFA_set_accepting(even_1, 0, true);
            char ch3[20];
            scanf("%s%*c", ch3);
            printf("For this string: %s, the result is: \n",ch3);
            printf("%d\n", DFA_execute(even_1, ch3));

        }else if(ch2 == '4'){
            printf("%s\n","Hello World: Enter a string to test: (a sample input would be ab or abc)");
            DFA *even0_even_1 = DFA_new(4);
            DFA_set_transition(even0_even_1, 0, '0', 1);
            DFA_set_transition(even0_even_1, 0, '1', 3);
            DFA_set_transition(even0_even_1, 1, '0', 0);
            DFA_set_transition(even0_even_1, 1, '1', 2);
            DFA_set_transition(even0_even_1, 2, '0', 3);
            DFA_set_transition(even0_even_1, 2, '1', 1);
            DFA_set_transition(even0_even_1, 3, '0', 2);
            DFA_set_transition(even0_even_1, 3, '1', 0);
            DFA_set_accepting(even0_even_1, 0, true);
            char ch3[20];
            scanf("%s%*c", ch3);
            printf("For this string: %s, the result is: \n",ch3);
            printf("%d\n", DFA_execute(even0_even_1, ch3));

        }else if(ch2 == '5'){
            printf("%s\n","Hello World: Enter a string to test: (a sample input would be california)");
            DFA *customized = DFA_new(4);
            DFA_set_transition(customized, 0, 'a', 1);
            DFA_set_transition(customized, 0, 'c', 2);
            DFA_set_transition(customized, 1, 'b', 3);
            DFA_set_transition(customized, 2, 'a', 3);
            DFA_set_transition_all(customized, 3, 3); //loop to itself with all inputs
            DFA_set_accepting(customized, 3, true);
            char ch3[20];
            scanf("%s%*c", ch3);
            printf("For this string: %s, the result is: \n",ch3);
            printf("%d\n", DFA_execute(customized, ch3));
        }



    //  <--- Part2 --->

    }else if(ch1 == '2'){
        printf("%s\n","Hello World: Part2 >>> Enter 1 or 2 or 3 to test each small problem: ");
        char ch2;
        scanf("%c%*c", &ch2);
        
        if(ch2 == '1'){
            printf("%s\n","Hello World: Enter a string to test: (a sample input would be hhman or manhh)");
            NFA *end_with_man = NFA_new(4);

            NFA_add_transition(end_with_man, 0, 'm', 1);
            NFA_add_transition(end_with_man, 1, 'a', 2);
            NFA_add_transition(end_with_man, 2, 'n', 3);
            NFA_add_transition_all(end_with_man, 0, 0);
            NFA_set_accepting(end_with_man, 3, true);

            char ch3[20];
            scanf("%s%*c", ch3);
            printf("For this string: %s, the result is: \n",ch3);
            printf("%d\n", NFA_execute(end_with_man, ch3));

        }else if(ch2 == '2'){
            printf("%s\n","Hello World: Enter a string to test: (a sample input would be aa or washington)");
            NFA *aghiostwnn = NFA_new(20);

            NFA_add_transition_all(aghiostwnn, 0, 0);
            NFA_add_transition(aghiostwnn, 0, 'a', 1);
            NFA_add_transition_all(aghiostwnn, 1, 1);
            NFA_add_transition(aghiostwnn, 1, 'a', 2);
            NFA_add_transition_all(aghiostwnn, 2, 2);
            NFA_add_transition(aghiostwnn, 0, 'g', 3);
            NFA_add_transition_all(aghiostwnn, 3, 3);
            NFA_add_transition(aghiostwnn, 3, 'g', 4);
            NFA_add_transition_all(aghiostwnn, 4, 4);
            NFA_add_transition(aghiostwnn, 0, 'h', 5);
            NFA_add_transition_all(aghiostwnn, 5, 5);
            NFA_add_transition(aghiostwnn, 5, 'h', 6);
            NFA_add_transition_all(aghiostwnn, 6, 6);
            NFA_add_transition(aghiostwnn, 0, 'i', 7);
            NFA_add_transition_all(aghiostwnn, 7, 7);
            NFA_add_transition(aghiostwnn, 7, 'i', 8);
            NFA_add_transition_all(aghiostwnn, 8, 8);
            NFA_add_transition(aghiostwnn, 0, 'n', 9);
            NFA_add_transition_all(aghiostwnn, 9, 9);
            NFA_add_transition(aghiostwnn, 9, 'n', 10);
            NFA_add_transition_all(aghiostwnn, 10, 10);
            NFA_add_transition(aghiostwnn, 10, 'n', 11);
            NFA_add_transition_all(aghiostwnn, 11, 11);
            NFA_add_transition(aghiostwnn, 0, 'o', 12);
            NFA_add_transition_all(aghiostwnn, 12, 12);
            NFA_add_transition(aghiostwnn, 12, 'o', 13);
            NFA_add_transition_all(aghiostwnn, 13, 13);
            NFA_add_transition(aghiostwnn, 0, 's', 14);
            NFA_add_transition_all(aghiostwnn, 14, 14);
            NFA_add_transition(aghiostwnn, 14, 's', 15);
            NFA_add_transition_all(aghiostwnn, 15, 15);
            NFA_add_transition(aghiostwnn, 0, 't', 16);
            NFA_add_transition_all(aghiostwnn, 16, 16);
            NFA_add_transition(aghiostwnn, 16, 't', 17);
            NFA_add_transition_all(aghiostwnn, 17, 17);
            NFA_add_transition(aghiostwnn, 0, 'w', 18);
            NFA_add_transition_all(aghiostwnn, 18, 18);
            NFA_add_transition(aghiostwnn, 18, 'w', 19);
            NFA_add_transition_all(aghiostwnn, 19, 19);

            NFA_set_accepting(aghiostwnn, 2, true);
            NFA_set_accepting(aghiostwnn, 4, true);
            NFA_set_accepting(aghiostwnn, 6, true);
            NFA_set_accepting(aghiostwnn, 8, true);
            NFA_set_accepting(aghiostwnn, 11, true);
            NFA_set_accepting(aghiostwnn, 13, true);
            NFA_set_accepting(aghiostwnn, 15, true);
            NFA_set_accepting(aghiostwnn, 17, true);
            NFA_set_accepting(aghiostwnn, 19, true);

            char ch3[20];
            scanf("%s%*c", ch3);
            printf("For this string: %s, the result is: \n",ch3);
            printf("%d\n", NFA_execute(aghiostwnn, ch3));

        }else if(ch2 == '3'){
            printf("%s\n","Hello World: Enter a string to test: (a sample input would be acbc or abca)");
            NFA *abc = NFA_new(4);
            NFA_add_transition(abc, 0, 'a', 0);
            NFA_add_transition(abc, 0, 'b', 0);
            NFA_add_transition(abc, 0, 'c', 0);
            NFA_add_transition(abc, 0, 'a', 1);
            NFA_add_transition(abc, 1, 'b', 2);
            NFA_add_transition(abc, 2, 'c', 3);
            NFA_add_transition(abc, 3, 'a', 3);
            NFA_add_transition(abc, 3, 'b', 3);
            NFA_add_transition(abc, 3, 'c', 3);

            NFA_set_accepting(abc, 3, true);

            char ch3[20];
            scanf("%s%*c", ch3);
            printf("For this string: %s, the result is: \n",ch3);
            printf("%d\n", NFA_execute(abc, ch3));        
        }
    

    //  <--- Part3 --->

    }else if(ch1 == '3'){
        printf("%s\n","Hello World: Part3 >>> Enter 1 or 2 to test each small problem: ");
        char ch2;
        scanf("%c%*c", &ch2);
        
        // printf("%s\n","Hello World: Part3 Problem123");

        if(ch2 == '1'){
            printf("%s\n","Hello World: Part3 Problem1");
            printf("%s\n","Hello World: Enter a string to test: (a sample input would be hhman or manhh)");
            
            NFA *end_with_man = NFA_new(4);

            NFA_add_transition(end_with_man, 0, 'm', 1);
            NFA_add_transition(end_with_man, 1, 'a', 2);
            NFA_add_transition(end_with_man, 2, 'n', 3);
            NFA_add_transition_all(end_with_man, 0, 0);
            NFA_set_accepting(end_with_man, 3, true);
            
            char ch3[20];
            scanf("%s%*c", ch3);
            printf("For this string: %s, the result is: \n",ch3);
            DFA *dfa_end_with_man = NFA_to_DFA(end_with_man);   
            printf("%d\n", DFA_execute(dfa_end_with_man, ch3));        
        
        }else if(ch2 == '2'){
            printf("%s\n","Hello World: Part3 Problem2");
            printf("%s\n","Hello World: Enter a string to test: (a sample input would be washington or aa)");
            
            NFA *aghiostwnn = NFA_new(12);

            NFA_add_transition_all(aghiostwnn, 0, 0);
            NFA_add_transition_all(aghiostwnn, 1, 1);
            NFA_add_transition_all(aghiostwnn, 2, 2);
            NFA_add_transition_all(aghiostwnn, 3, 3);
            NFA_add_transition_all(aghiostwnn, 4, 4);
            NFA_add_transition_all(aghiostwnn, 5, 5);
            NFA_add_transition_all(aghiostwnn, 6, 6);
            NFA_add_transition_all(aghiostwnn, 7, 7);
            NFA_add_transition_all(aghiostwnn, 8, 8);
            NFA_add_transition_all(aghiostwnn, 9, 9);
            NFA_add_transition_all(aghiostwnn, 10, 10);
            NFA_add_transition_all(aghiostwnn, 11, 11);            

            NFA_add_transition(aghiostwnn, 0, 'a', 1);
            NFA_add_transition(aghiostwnn, 1, 'a', 11);

            NFA_add_transition(aghiostwnn, 0, 'g', 2);
            NFA_add_transition(aghiostwnn, 1, 'g', 11);


            NFA_add_transition(aghiostwnn, 0, 'h', 3);
            NFA_add_transition(aghiostwnn, 1, 'h', 11);

            NFA_add_transition(aghiostwnn, 0, 'i', 4);
            NFA_add_transition(aghiostwnn, 1, 'i', 11);

            NFA_add_transition(aghiostwnn, 0, 'o', 5);
            NFA_add_transition(aghiostwnn, 1, 'o', 11);

            NFA_add_transition(aghiostwnn, 0, 's', 6);
            NFA_add_transition(aghiostwnn, 1, 's', 11);

            NFA_add_transition(aghiostwnn, 0, 't', 7);
            NFA_add_transition(aghiostwnn, 1, 't', 11);

            NFA_add_transition(aghiostwnn, 0, 'w', 8);
            NFA_add_transition(aghiostwnn, 1, 'w', 11);

            NFA_add_transition(aghiostwnn, 0, 'n', 9);
            NFA_add_transition(aghiostwnn, 1, 'n', 10);
            NFA_add_transition(aghiostwnn, 1, 'n', 11);

            NFA_set_accepting(aghiostwnn, 11, true);
            char ch3[20];
            scanf("%s%*c", ch3);
            printf("For this string: %s, the result is: \n",ch3);

            DFA *dfa_aghiostwnn = NFA_to_DFA(aghiostwnn);   
            printf("%d\n",DFA_execute(dfa_aghiostwnn,ch3));


        }else if(ch2 =='3'){
            printf("%s\n","Hello World: Part3 Problem3");
            printf("%s\n","Hello World: Enter a string to test: (a sample input would be acbc or abca)");
            
            NFA *abc = NFA_new(4);
            NFA_add_transition(abc, 0, 'a', 0);
            NFA_add_transition(abc, 0, 'b', 0);
            NFA_add_transition(abc, 0, 'c', 0);
            NFA_add_transition(abc, 0, 'a', 1);
            NFA_add_transition(abc, 1, 'b', 2);
            NFA_add_transition(abc, 2, 'c', 3);
            NFA_add_transition(abc, 3, 'a', 3);
            NFA_add_transition(abc, 3, 'b', 3);
            NFA_add_transition(abc, 3, 'c', 3);

            NFA_set_accepting(abc, 3, true);
            
            char ch3[20];
            scanf("%s%*c", ch3);
            printf("For this string: %s, the result is: \n",ch3);

            DFA *dfa_abc = NFA_to_DFA(abc);   
            printf("%d\n",DFA_execute(dfa_abc,ch3));
        }
    }

    return 0;
}

// int main(){
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
//     printf("%s\n", " ");


//     // <--- Part2 --->

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
//     printf("%s\n", " ");

    

//     // <--- Part3 --->
//     printf("%s\n","Hello World: Part3 Problem123");

//     DFA *dfa_end_with_man = NFA_to_DFA(end_with_man);   
//     printf("%d\n",DFA_execute(dfa_end_with_man,"problem"));
    
//     // DFA *dfa_aghiostwnn = NFA_to_DFA(aghiostwnn);   
//     // printf("%d\n",DFA_execute(dfa_aghiostwnn,"aa"));

//     DFA *dfa_abc = NFA_to_DFA(abc);   
//     printf("%d\n",DFA_execute(dfa_abc,"abca"));
//     return 0;
// }