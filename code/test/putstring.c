#include "syscall.h"
void print(char *str)
{
    PutString(str);
}
int
main()
{
    print("abcddrfdf");
    //Halt();
    return 0;
}