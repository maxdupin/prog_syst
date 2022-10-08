#include "syscall.h"
void print(int n)
{
    PutInt(n);
}
int
main()
{
    print(1);
    //Halt();
    return 0;
}