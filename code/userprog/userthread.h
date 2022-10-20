#include "thread.h"
#include "system.h"

 struct s
{
    int f;
    int arg;
};


extern int do_ThreadCreate(int f, int arg);
extern int do_ThreadExit();