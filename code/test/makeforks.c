#include "syscall.h"

int main()
{
    PutChar('a');
    ForkExec("../test/putchar");
    //ForkExec("../test/putchar");
    while(1);
}