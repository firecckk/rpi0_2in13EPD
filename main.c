#include <stdlib.h>     //exit()
#include <signal.h>     //signal()
//#include "EPD_Test.h"   //Examples
#include "Modules.h"

void  Handler(int signo)
{
    //System Exit
    printf("\r\nHandler:exit\r\n");
    DEV_Module_Exit();

    exit(0);
}

int main(void)
{
    // Exception handling:ctrl + c
    signal(SIGINT, Handler);
    //EPD_2in13_V2_test();
    EPD_run();
    return 0;
}
