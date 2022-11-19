#include "syscall.h"

volatile int i;
void print(char c)
{  
    PutChar(c);
    ThreadExit();
    PutChar('\n');
}

int
main()
{
    for(i = 0; i<10; i++){
        ThreadCreate(print, 'a');
    }
    ThreadExit(); 
    return 0;
}

