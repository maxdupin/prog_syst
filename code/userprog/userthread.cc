#include "userthread.h"
#include "addrspace.h"
#include "userfork.h"

class Semaphore;


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
    //machine->DumpMem("threads.svg");
    machine->Run();
}



int do_ThreadCreate(int f, int arg)
{
    
    struct s *structK = (struct s *)malloc(sizeof(s));
    structK->f = f;
    structK->arg = arg;
    Thread *t = new Thread("forked thread");
    currentThread->space->compteurT++;
    t->space=currentThread->space;
    int posInBitMap = currentThread->space->AddInBitMap();
    if(posInBitMap != -1){
        t->SetPosInBitMap(posInBitMap);
        t->Start(StartUserThread, structK);
    }
    return 0;
}
int do_ThreadExit(){
    
        currentThread->space->compteurT--;
        int pos = currentThread->GetPosInBitMap();
        //printf("thread =%d\n", currentThread->space->compteurT);
        currentThread->space->ClearBitMap(pos);


    if(currentThread->space->compteurT==0){
        do_ForkExit();
    }
    
    currentThread->Finish();
    return 0;
}