#include "syscall.h"
//Pour pouvoir tester cette fonction veuillez rentrer dans le répertoire userprog et taper : 
//'./nachos -x ../test/putstring'

void print(char *str)
{
    PutString(str);
    PutChar('\n');
}
int
main()
{
    print("Premier test:"); 
    print("aaaaaaaaaaaaaaa"); //test pour une limite de caractères inferieur à MAX_STRING_SIZE (15=15)

    print("Second test:");
    print("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");//test pour une limite de caractères supérieur à MAX_STRING_SIZE (40>15)    
    //Halt();
    return 0;
}

/* Réponse à la VI 1: (start.s)
le resultat de exit est écraser car le compilateur dit a exit d'écraser  la valeur de 
du deuxième registre là ou est la valeur de retour de putstring
il faut donc faire un move dans le registre 4 pour sauvegarder cette valeur
*/