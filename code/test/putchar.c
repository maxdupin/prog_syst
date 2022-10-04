#include "syscall.h"
void print(char c, int n)
{
    int i;

    for (i = 0; i < n; i++) {
        PutChar(c + i);
    }
    PutChar('\n');
}

void print2(char * s) {
    PutString(s);
}

int
main()
{
    char s [5] = {'a', 'b', 'c', 'd', '\0'};
    print('a',4);
    print2(s);
    Halt();
}