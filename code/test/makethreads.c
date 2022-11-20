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

//La partie en commentaire si dessous représente le premier test que l'on a implémenté avec les boucles 
//while qui permettait en premier lieu au thread d'écrire le a comme voulu.
/*
void print(char c)
{  
    PutChar(c);
    while(1);
    PutChar('\n');
}

int
main()
{
    ThreadCreate(print,'a');
    while(1);
    //ThreadExit(); 
    return 0;
}

*/
