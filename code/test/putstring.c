#include "syscall.h"
void print(char *str)
{
    PutString(str);
}
int
main()
{
    char str[5] = {'a', 'b', 'c', 'd', '\0'};
    print(str);
    Halt();
}