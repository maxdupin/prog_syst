#include "syscall.h"
void print(char c, int n)
{
    int i;

    for (i = 0; i < n; i++) {
        PutChar(c + i);
    }
    PutChar('\n');
}
int
main()
{
<<<<<<< HEAD
    char tab[4]={'a','b','d','\0'};
=======
    char s [5] = {'a', 'b', 'c', 'd', '\0'};
>>>>>>> a956ed1c5fde82d63200df2ed848c8472dffd65f
    print('a',4);
    Halt();
}