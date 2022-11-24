#ifdef CHANGED
#include "pageprovider.h"
#include "machine.h"
#include "system.h"


#include  <string.h>


PageProvider::PageProvider ()
{
    bitmap = new BitMap(NumPhysPages);
}

PageProvider::~PageProvider()
{

    bitmap->~BitMap();
}

int PageProvider::GetEmptyPage()
{
    int num = bitmap->Find();
    memset(&(machine->mainMemory[PageSize*num]), 0, PageSize);
    return num;
}

void PageProvider::ReleasePage(int which)
{
    bitmap->Clear(which);
}

int PageProvider::NumAvailPage()
{
    return bitmap->NumClear();
}
#endif
