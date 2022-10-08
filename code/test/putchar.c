#include "syscall.h"
//Pour pouvoir tester cette fonction veuillez rentrer dans le répertoire userprog et taper :
// './nachos -x ../test/putchar'


void print(char c, int n)
{
    int i;

    for (i = 0; i < n; i++) {
        PutChar(c + i);
    }
    PutChar('\n');
}
int
main()
{
    print('a',4);
    //Halt();
    return 0;
}