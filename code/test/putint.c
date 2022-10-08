#include "syscall.h"
//Pour pouvoir tester cette fonction veuillez rentrer dans le répertoire userprog et taper : 
//'./nachos -x ../test/putint'

void print(int n)
{
    PutInt(n);
    PutChar('\n');
}
int
main()
{
    print(1);
    //print(1465454557845844);
    //Halt();
    return 0;
}