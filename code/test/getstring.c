#include "syscall.h"
void print(char* s,int n)
{
    GetString(s,n);
    PutString(s);
}
int
main()
{
    char tab[] ={'a','b','b','b','b','b','b'};
    print(tab,15);
    return 0;
}