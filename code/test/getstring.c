#include "syscall.h"
void print()
{
    int size=20;
    char s[size];
    GetString(s,size);
    PutString(s);
    PutChar('\n');
}
int
main()
{
    
    print();
    return 0;
}