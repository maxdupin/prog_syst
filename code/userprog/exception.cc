// exception.cc
//      Entry point into the Nachos kernel from user programs.
//      There are two kinds of things that can cause control to
//      transfer back to here from user code:
//
//      syscall -- The user code explicitly requests to call a procedure
//      in the Nachos kernel.  Right now, the only function we support is
//      "Halt".
//
//      exceptions -- The user code does something that the CPU can't handle.
//      For instance, accessing memory that doesn't exist, arithmetic errors,
//      etc.
//
//      Interrupts (which can also cause control to transfer from user
//      code into the Nachos kernel) are handled elsewhere.
//
// For now, this only handles the Halt() system call.
// Everything else core dumps.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "system.h"
#include "syscall.h"

//----------------------------------------------------------------------
// UpdatePC : Increments the Program Counter register in order to resume
// the user program immediately after the "syscall" instruction.
//----------------------------------------------------------------------
static void
UpdatePC ()
{
    int pc = machine->ReadRegister (PCReg);
    machine->WriteRegister (PrevPCReg, pc);
    pc = machine->ReadRegister (NextPCReg);
    machine->WriteRegister (PCReg, pc);
    pc += 4;
    machine->WriteRegister (NextPCReg, pc);
}


//----------------------------------------------------------------------
// ExceptionHandler
//      Entry point into the Nachos kernel.  Called when a user program
//      is executing, and either does a syscall, or generates an addressing
//      or arithmetic exception.
//
//      For system calls, the following is the calling convention:
//
//      system call code -- r2DEBUG('s', "GetChar\n");
//              arg1 -- r4
//              arg2 -- r5
//              arg3 -- r6
//              arg4 -- r7
//
//      The result of the system call, if any, must be put back into r2.
//
// And don't forget to increment the pc before returning. (Or else you'll
// loop making the same system call forever!
//
//      "which" is the kind of exception.  The list of possible exceptions
//      are in machine.h.
//----------------------------------------------------------------------

void
ExceptionHandler (ExceptionType which)
{
    int type = machine->ReadRegister (2);
    int address = machine->registers[BadVAddrReg];

    switch (which)
      {
        case SyscallException:
          {
            switch (type)
              {
                case SC_Halt:
                  {
                    DEBUG ('s', "Shutdown, initiated by user program.\n");
                    interrupt->Powerdown ();
                    break;
                  }
                  #ifdef CHANGED
                  case SC_PutChar:
                  {
                    //Test : ./nachos -x ../test/putchar
                    DEBUG('s', "PutChar\n");
                    int c = machine->ReadRegister (4);
                    consoledriver->PutChar(c);
                    break;
                  }
                  case SC_GetChar:
                  {
                    DEBUG('s', "GetChar\n");
                    machine->WriteRegister(2, consoledriver->GetChar());
                    break;
                  }
                  case SC_PutString:
                  {
                    DEBUG('s', "PutString\n");
                    int r = machine->ReadRegister(4);
                    // Malloc un tableau to
                    char* tab =(char*) malloc(MAX_STRING_SIZE*sizeof(char));
                    // utiliser MAXSTRINGSIZE
                    int size = r/MAX_STRING_SIZE;
                    int test=0;
                    //Boucle pour éviter de tronquer le string
                    for(int i = 0; i < size; i++){
                      test=consoledriver->copyStringFromMachine(r,tab, MAX_STRING_SIZE);
                      consoledriver->PutString(tab);
                      r+=test;
                      if(test!=MAX_STRING_SIZE) break;
                    }
                    free(tab);
                    break;
                  }
                  case SC_GetString :
                  {
                    DEBUG('s',"GetString");
                    int r = machine->ReadRegister(4);
                    int size_uti =machine->ReadRegister(5);
                    int min=0;
                    if(size_uti<MAX_STRING_SIZE) min=size_uti;
                    else min=MAX_STRING_SIZE;              
                    int size = size_uti/min;
                    char* tab =(char*) malloc(MAX_STRING_SIZE*sizeof(char));
                    int test=0;
                    for(int i = 0; i < size; i++){
                        consoledriver->GetString(tab,MAX_STRING_SIZE);
                        test=consoledriver->copyStringToMachine(tab,r,MAX_STRING_SIZE);                      
                        if(test!=min) break;
                        r+=test;
                    }

                    free(tab);
                    break;
                  }
                  case SC_GetInt:
                  {
                    DEBUG('s', "GetInt\n");
                    int r = machine->ReadRegister(4);
                    int i;
                    consoledriver->GetInt(&i);
                    machine->WriteMem(r,sizeof(int),i);
                    break;
                  }
                  case SC_PutInt:
                  {
                    DEBUG('s', "PutInt\n");
                    int r=machine->ReadRegister(4);
                    consoledriver->PutInt(r);
                    break;
                  }
                  case SC_Exit:
                  {
                    DEBUG('s',"Exit\n");

                    int r=machine->ReadRegister(4);
                    printf("%d\n", r);
                    interrupt->Powerdown ();
                    break;
                  }
                  
                  case SC_ThreadCreate: //./nachos -rs 1234
                  {
                    DEBUG('s',"ThreadCreate\n");
                    printf("truc\n");
                    //do_ThreadCreate(f,arg)
                    break;
                  }
                  case SC_ThreadExit:
                  {
                    DEBUG('s',"ThreadExit");
                    //do_ThreadExit()
                    break;
                  }



                  #endif
                default:
                  {
                    ASSERT_MSG(FALSE, "Unimplemented system call %d\n", type);
                  }
              }

            // Do not forget to increment the pc before returning!
            UpdatePC ();
            break;
          }

        case PageFaultException:
          if (!address) {
            ASSERT_MSG (FALSE, "NULL dereference at PC %x!\n", machine->registers[PCReg]);
          } else {
            // For now
            ASSERT_MSG (FALSE, "Page Fault at address %x at PC %x\n", address, machine->registers[PCReg]);
          }
          break;

        case ReadOnlyException:
          // For now
          ASSERT_MSG (FALSE, "Read-Only at address %x at PC %x\n", address, machine->registers[PCReg]);
          break;

        case BusErrorException:
          // For now
          ASSERT_MSG (FALSE, "Invalid physical address at address %x at PC %x\n", address, machine->registers[PCReg]);
          break;

        case AddressErrorException:
          // For now
          ASSERT_MSG (FALSE, "Invalid address %x at PC %x\n", address, machine->registers[PCReg]);
          break;

        case OverflowException:
          // For now
          ASSERT_MSG (FALSE, "Overflow at PC %x\n", machine->registers[PCReg]);
          break;

        case IllegalInstrException:
          // For now
          ASSERT_MSG (FALSE, "Illegal instruction at PC %x\n", machine->registers[PCReg]);
          break;

        default:
          ASSERT_MSG (FALSE, "Unexpected user mode exception %d %d %x at PC %x\n", which, type, address, machine->registers[PCReg]);
          break;
      }
}
