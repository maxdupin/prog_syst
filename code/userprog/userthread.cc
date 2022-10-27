#include "userthread.h"
#include "addrspace.h"

static void StartUserThread(void *schmurtz)
{
    struct s *structK=(struct s *)schmurtz;

    int i;
    for (i = 0; i < NumTotalRegs; i++)
        machine->WriteRegister (i, 0);

    machine->WriteRegister (PCReg, structK->f);
    DEBUG ('x', "[DEBUG] Function: %d\n", structK->f);
    machine->WriteRegister (4, structK->arg);
    DEBUG ('x', "[DEBUG] Function: %d\n", structK->arg);

    machine->WriteRegister (NextPCReg, machine->ReadRegister(PCReg) + 4);
    free(schmurtz);
    // Set the stack register to the end of the address space, where we
    // allocated the stack; but subtract off a bit, to make sure we don't
    // accidentally reference off the end!
    unsigned size = currentThread->space->AllocateUsersStack();
    machine->WriteRegister (StackReg, size);
    //DEBUG ('a', "Initializing stack register to 0x%x\n",
           //numPages * PageSize - 16);
    machine->DumpMem("threads.svg");
    machine->Run();
}



int do_ThreadCreate(int f, int arg)
{
    struct s *structK = (struct s *)malloc(sizeof(s));
    structK->f = f;
    structK->arg = arg;
    Thread *t = new Thread("forked thread");
    t->space=currentThread->space;
    t->Start(StartUserThread, structK);
    return 0;
}
int do_ThreadExit(){
    currentThread->Finish();
    return 0;
}