#include "syscall.h"


void print(char c)
{
    PutChar("\n");
    PutChar(c);
    PutChar("\n");
    ThreadExit();
}

int
main()
{
    ThreadCreate(print, "a");
    PutChar("h");
    //while(true); 
    return 0;
}

