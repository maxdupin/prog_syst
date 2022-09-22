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
    console = ...
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
    #ifdef CHANGED
    console->TX (ch);
    writeDone->P ();
    #endif // CHANGED
}
int ConsoleDriver::GetChar()
{
    // ...
}
void ConsoleDriver::PutString(const char *s)
{
    // ...
}
void ConsoleDriver::GetString(char *s, int n)
{
    // ...
}
#endif // CHANGED