#include "syscall.h"

void print(char *c)
{
    PutString(c);
    PutChar('\n');
}


int
main()
{
    print("abcd");
    ThreadExit();
    return 0;
}