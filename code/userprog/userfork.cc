#include "userfork.h"



static void StartUserProc(void *arg){
    currentThread->space->InitRegisters();
    currentThread->space->RestoreState ();	// load page table register
    machine->Run();
}


int do_ForkExec(char *filename){
    
    OpenFile *executable = fileSystem->Open (filename);
    AddrSpace *space;
    if (executable == NULL)
    {
        printf ("Unable to open file %s\n", filename);
        return -1;
    }
    Thread *t= new Thread("forked thread");
    space = new AddrSpace (executable);
    t->space = space;
    delete executable;
    t->Start(StartUserProc,NULL);

    return 0;
}