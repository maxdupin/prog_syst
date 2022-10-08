#include "syscall.h"
//Pour pouvoir tester cette fonction veuillez rentrer dans le répertoire userprog et taper : 
//'./nachos -x ../test/getchar'

void print()
{
    int i = GetChar();
    PutChar(i);
    PutChar('\n');
}
int
main()
{
    print();
    return 0;
}