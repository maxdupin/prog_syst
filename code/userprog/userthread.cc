#include "userthread.h"

static void StartUserThread(void *schmurtz)
{
    DEBUG('x',"mon debug%d\n");
    
    }


int do_threadCreate(int f, int arg)
{
    struct s structK;
    structK.f = f;
    structK.arg = arg;
    Thread *t = new Thread("forked thread");
    t->space=currentThread->space;
    t->Start(StartUserThread, &structK);
    return 0;
}
int do_ThreadExit(){
    currentThread->Finish();
}