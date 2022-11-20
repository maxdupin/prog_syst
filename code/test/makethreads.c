#include "syscall.h"
/*
Pour lancer le programme de test veuillez utiliser la commande suivante: 
./nachos -rs 1234 -x ../test/makethreads
*/
volatile int i;
void print(char c)
{  
    PutChar(c);
    ThreadExit();
    PutChar('\n');
}

int
main()
{
    for(i = 0; i<10; i++){
        ThreadCreate(print, 'a');
    }
    ThreadExit(); 
    return 0;
}

