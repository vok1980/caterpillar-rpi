#include <stdio.h>      //printf()
#include <stdlib.h>     //exit()
#include <signal.h>
#include "DEV_Config.h"
#include "MotorDriver.h"

void  Handler(int signo)
{
    //System Exit
    printf("\r\nHandler:Motor Stop\r\n");
    Motor_Stop(MOTORA);
    Motor_Stop(MOTORB);
    DEV_ModuleExit();

    exit(0);
}

int main(void)
{
    //1.System Initialization
    if(DEV_ModuleInit())
        exit(0);
    
    //2.Motor Initialization
    Motor_Init();


    // Exception handling:ctrl + c
    signal(SIGINT, Handler);
    while(1) {
        int speedA, speedB;
        scanf("%d %d", &speedB, &speedA);
        printf("Motor_Run\r\n");
        Motor_Run(MOTORA, speedA > 0 ? FORWARD : BACKWARD, abs(speedA));
        Motor_Run(MOTORB, speedB > 0 ? FORWARD : BACKWARD, abs(speedB));
    }

    //3.System Exit
    DEV_ModuleExit();
    return 0;
}

