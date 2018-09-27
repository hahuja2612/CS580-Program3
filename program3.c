#include "badmem.h"
#include <stdlib.h>
#include <stdio.h>
#pragma GCC diagnostic ignored "-Wreturn-local-addr"
#pragma GCC diagnostic ignored "-Wfree-nonheap-object"

void f1(){
    int *a = malloc(sizeof(int) * 3);
    for (int i = 0; i < sizeof(int); i++){
        a[i] = i;
    }
}
void f2(){
    int a[10];
    for (int i = 0; i < sizeof(a); i++){
        a[i] = i;
    }
    for (int i = 10; i >= sizeof(a); i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void f3(){
    char * cptr = calloc(10, sizeof(char));
    cptr[10] = 'a';
    char * junk = cptr[0];
    free(junk);
}

/**** DO NOT ALTER anything below here ****/

void initialize_bomb();
void phase_1();
void phase_2();
void phase_3();
void phase_4();
void phase_5();
void phase_6();

int main(){
    printf("======= Part A: Fixing Memory Errors with Valgrind ========\n\n");
    f1();
    f2();
    f3();
    printf("Part A complete... \n\n");

    printf("======= Part B: Finding the Secret Code with GDB ========\n\n");
    printf("Welcome to my fiendish little bomb.\n");

    initialize_bomb();

    printf("There are 6 phases with which to blow yourself up.\n");
    printf("You have 300 seconds to complete them. Have a nice day!\n");

    /* Hmm... Six phases must be more secure than one phase! */
    phase_1(); /* Run the phase */
    printf("Phase 1 defused. How about the next one?\n");

    /* The second phase is harder. No one will ever figure out
    how to defuse this... */
    phase_2();
    printf("That's number 2. Keep going!\n");

    /* I guess this is too easy so far. Some more complex code will
    * confuse people. */
    phase_3();
    printf("Halfway there!\n");

    /* Oh yeah? Well, how good is your math? Try on this saucy problem! */
    phase_4();
    printf("So you got that one. Try this one.\n");

    /* Round and 'round in memory we go, where we stop, the bomb blows! */
    phase_5();
    printf("Good work! On to the next...\n");

    /* This phase will never be used, since no one will get past the
    * earlier ones. But just in case, make this one extra hard. */
    phase_6();

}
