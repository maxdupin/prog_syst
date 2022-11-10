#include "syscall.h"


void print(char c)
{   
    PutChar('\n');
    PutChar(c);
    PutChar('\n');
    //while(1);
    ThreadExit();
}

int
main()
{
    ThreadCreate(print, 'a');
    PutChar('h');
    ThreadExit();
    //Pour le test de Thread EXIT créer plusieurs threads et les faire sortir et reagarder si le premier est finit et que les autres tournent toujours
    
    //while(1); 
    return 0;
}

