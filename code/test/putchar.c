#include "syscall.h"
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
    char tab[4]={'a','b','d','\0'};
    print('a',4);
    Halt();
}