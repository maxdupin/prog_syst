#include "syscall.h"
void print(char *str)
{
    PutString(str);
    PutChar('\n');
}
int
main()
{
    print("abcddrfdfdgtyhgrfffffffffffffffffffffffffffffffffff");
    //Halt();
    return 0;
}

/* Réponse à la VI 1: (start.s)
le resultat de exit est écraser car le syteme dit a exit d'écraser  la valeur de 
du deuxième registre là ou est la valeur de retour de putstring
il faut donc faire un move dans le registre 4 pour sauvegarder cette valeur
*/