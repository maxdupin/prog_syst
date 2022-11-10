#include "syscall.h"

volatile int i;
void print(char c)
{   for (i = 0; i < 4; i++)
{
    PutChar(c);
    PutChar('\n');
}

    PutChar('\n');
    
    //while(1);
    ThreadExit();
}

int
main()
{
    for(i = 0; i<4; i++){
        ThreadCreate(print, 'a');
    }
    PutChar('h');
    ThreadExit();
    //Pour le test de Thread EXIT créer plusieurs threads et les faire sortir et reagarder si le premier est finit et que les autres tournent toujours
    
    //while(1); 
    return 0;
}

