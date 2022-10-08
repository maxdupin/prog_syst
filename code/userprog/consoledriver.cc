#ifdef CHANGED
#include "copyright.h"
#include "system.h"
#include "consoledriver.h"
#include "synch.h"
static Semaphore *readAvail;
static Semaphore *writeDone;
static void ReadAvailHandler(void *arg) { (void) arg; readAvail->V(); }
static void WriteDoneHandler(void *arg) { (void) arg; writeDone->V(); }
ConsoleDriver::ConsoleDriver(const char *in, const char *out)
{
    readAvail = new Semaphore("read avail", 0);
    writeDone = new Semaphore("write done", 0);
    console = new Console (in, out, ReadAvailHandler, WriteDoneHandler, NULL);
}
ConsoleDriver::~ConsoleDriver()
{
    delete console;
    delete writeDone;
    delete readAvail;
}
void ConsoleDriver::PutChar(int ch)
{
    // ...
    console->TX (ch);
    writeDone->P ();
}
int ConsoleDriver::GetChar()
{
    // ...

    int ch;
    readAvail->P ();
    ch= console->RX ();
    return ch;


}
void ConsoleDriver::PutString(const char *s)
{
    // ...
    int i=0;
    while(s[i]!='\0'){
        PutChar(s[i]);
        i++;
    }
}
void ConsoleDriver::GetString(char *s, int n)
{
    // ...
    int i=0;
    char g;
    while(i!=n){
        g=GetChar();
        s[i]=g;
        if(g=='\0'){
            break;
        }
        i++;
    }
    s[i]='\0';

    
}
unsigned ConsoleDriver::copyStringFromMachine(int from, char *to, unsigned size) {
    int c;
    unsigned i = 0;
    
    for (;i < size; i++ ){
        machine->ReadMem(from+i, 1, &c);
        
        if (i == size-1) {
            to[i] = '\0';
        }else {
            to[i] = (char) c;
        }
        if (to[i] == '\0') break;
    }
    return i;
    
}
unsigned ConsoleDriver::copyStringToMachine(char *from, int to, unsigned size) {
    int c;
    unsigned i = 0;
    
    for (;i < size; i++ ){
        c= (int) from[i];
        if (i == size-1) {
            from[i] = '\0';
        }else {
            from[i] = (int) c;
            machine->WriteMem(to+i, 1, c);
        }
        if (from[i] == '\0') break;
        
    }
    machine->WriteMem(to+i, 1, '\0');
    return i;
    
}

#endif // CHANGED