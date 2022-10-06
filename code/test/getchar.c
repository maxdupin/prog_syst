#include "syscall.h"
void print()
{
    int i = GetChar();
    PutChar(i);
}
int
main()
{
    print();
    return 0;
}