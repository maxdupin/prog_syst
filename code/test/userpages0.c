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
    return 0;
}