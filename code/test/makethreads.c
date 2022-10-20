#include "syscall.h"


void print(char c)
{
    PutChar(c);
    PutChar("\n");
    ThreadExit();
}


int
main()
{
    ThreadCreate(print, 'a');
    while(true);
    return 0;
}