#include "syscall.h"
//Pour pouvoir tester cette fonction veuillez rentrer dans le répertoire userprog et taper : 
//'./nachos -x ../test/getint'

void print()
{
    int i;
    GetInt(&i);
    PutInt(i);
    PutChar('\n');
}
int
main()
{
    print();
    return 0;
}