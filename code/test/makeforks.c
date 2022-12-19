#include "syscall.h"
/*
Pour lancer le programme de test veuillez utiliser la commande suivante: 
./nachos -rs 1234 -x ../test/makeforks
*/
int main()
{
    //PutChar('a');
    //ForkExec("../test/putchar");
    //ForkExec("../test/putchar");
    ForkExec("../test/userpages0");
    ForkExec("../test/userpages1");

    ForkExec("../test/userpages0");
    ForkExec("../test/userpages1");

    ForkExec("../test/userpages0");
    ForkExec("../test/userpages1");

    ForkExec("../test/userpages0");
    ForkExec("../test/userpages1");

    ForkExec("../test/userpages0");
    ForkExec("../test/userpages1");

    ForkExec("../test/userpages0");
    ForkExec("../test/userpages1");
    ThreadExit();
    return 0;
}