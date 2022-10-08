#include "syscall.h"
void print()
{
    int i;
    GetInt(&i);
    PutInt(i);
    PutChar("\n");
}
int
main()
{
    print();
    return 0;
}