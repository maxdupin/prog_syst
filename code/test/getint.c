#include "syscall.h"
void print()
{
    int i;
    GetInt(&i);
    PutChar("\n");
}
int
main()
{
    print();
    return 0;
}