#include "syscall.h"

int main()
{
    //PutChar('a');
    //ForkExec("../test/putchar");
    //ForkExec("../test/putchar");
    ForkExec("../test/userpages0");
    ForkExec("../test/userpages1");

    ForkExec("../test/userpages0");
    ForkExec("../test/userpages1");

    ForkExec("../test/userpages0");
    ForkExec("../test/userpages1");

    ForkExec("../test/userpages0");
    ForkExec("../test/userpages1");

    ForkExec("../test/userpages0");
    ForkExec("../test/userpages1");

    ForkExec("../test/userpages0");
    ForkExec("../test/userpages1");
    ThreadExit();
    return 0;
}