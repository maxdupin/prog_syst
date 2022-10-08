#include "syscall.h"
void print(int n)
{
    PutInt(n);
    PutChar('\n');
}
int
main()
{
    print(1);
    //print(1465454557845844);
    //Halt();
    return 0;
}