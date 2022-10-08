#include "syscall.h"
//Pour pouvoir tester cette fonction veuillez rentrer dans le répertoire userprog et taper : 
//'./nachos -x ../test/getstring'

void print()
{
    int size=20;
    char s[size];
    GetString(s,size);
    PutString(s);
    PutChar('\n');
}
int
main()
{
    
    print();
    return 0;
}