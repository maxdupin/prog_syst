#include "syscall.h"

volatile int i;
void print(char c)
{  
    PutChar(c);
    PutChar('\n');
    //while(1);
    ThreadExit();
}

int
main()
{
    for(i = 0; i<20; i++){
        ThreadCreate(print, 'a');
    }
    ThreadExit(); 
    return 0;
}

