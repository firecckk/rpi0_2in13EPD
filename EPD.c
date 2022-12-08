#include "Modules.h"
#include "EPD_2in13_V2.h"
#include <time.h>

void clear_screen(void) {
    printf("Clear...\r\n");
    EPD_2IN13_V2_Init(EPD_2IN13_V2_FULL);
    EPD_2IN13_V2_Clear();
}

void EPD_sleep(void) {
    printf("Goto Sleep...\r\n");
    EPD_2IN13_V2_Sleep();
    DEV_Delay_ms(2000);
    printf("close 5V, Module enters 0 power consumption ...\r\n");
    DEV_Module_Exit();
}

int EPD_run(void) {
    printf("EPD_running!");

    if(DEV_Module_Init()!=0){
        return -1;
    }

    EPD_2IN13_V2_Init(EPD_2IN13_V2_FULL);
    
    UBYTE *BlackImage;
    UWORD Imagesize = ((EPD_2IN13_V2_WIDTH % 8 == 0)? (EPD_2IN13_V2_WIDTH / 8 ): (EPD_2IN13_V2_WIDTH / 8 + 1)) * EPD_2IN13_V2_HEIGHT;
    if((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL) {
        printf("Failed to apply for black memory...\r\n");
        return -1;
    }

    printf("Paint_NewImage\r\n");
    Paint_NewImage(BlackImage, EPD_2IN13_V2_WIDTH, EPD_2IN13_V2_HEIGHT, 270, WHITE);
    Paint_SelectImage(BlackImage);
    Paint_SetMirroring(MIRROR_VERTICAL);
    Paint_Clear(WHITE);

    // build clock
    

    // finalize
    free(BlackImage);
    BlackImage = NULL;
    return 0;
}

int EPD_test(void) {
    printf("EPD_running!");

    if(DEV_Module_Init()!=0){
        return -1;
    }

    EPD_2IN13_V2_Init(EPD_2IN13_V2_FULL);
    
    UBYTE *BlackImage;
    UWORD Imagesize = ((EPD_2IN13_V2_WIDTH % 8 == 0)? (EPD_2IN13_V2_WIDTH / 8 ): (EPD_2IN13_V2_WIDTH / 8 + 1)) * EPD_2IN13_V2_HEIGHT;
    if((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL) {
        printf("Failed to apply for black memory...\r\n");
        return -1;
    }

    printf("Paint_NewImage\r\n");
    Paint_NewImage(BlackImage, EPD_2IN13_V2_WIDTH, EPD_2IN13_V2_HEIGHT, 90, WHITE);
    Paint_SelectImage(BlackImage);
    Paint_SetMirroring(MIRROR_VERTICAL);
    Paint_Clear(WHITE);

    //EPD_2IN13_V2_Init(EPD_2IN13_V2_FULL);
    //EPD_2IN13_V2_DisplayPartBaseImage(BlackImage);

    //EPD_2IN13_V2_Init(EPD_2IN13_V2_PART);
    //Paint_SelectImage(BlackImage);

    Paint_DrawString_EN(178, 1, "1", &Font12, WHITE, BLACK);
    Paint_DrawString_EN(238, 1, "2", &Font12, WHITE, BLACK);
    Paint_DrawString_EN(238, 55, "3", &Font12, WHITE, BLACK);
    Paint_DrawString_EN(238, 110, "4", &Font12, WHITE, BLACK);
    Paint_DrawString_EN(178, 110, "5", &Font12, WHITE, BLACK);
    Paint_DrawString_EN(119, 110, "6", &Font12, WHITE, BLACK);
    Paint_DrawString_EN(60, 110, "7", &Font12, WHITE, BLACK);
    Paint_DrawString_EN(1, 110, "8", &Font12, WHITE, BLACK);
    Paint_DrawString_EN(1, 55, "9", &Font12, WHITE, BLACK);
    Paint_DrawString_EN(1, 1, "10", &Font12, WHITE, BLACK);
    Paint_DrawString_EN(60, 1, "11", &Font12, WHITE, BLACK);
    Paint_DrawString_EN(119, 1, "12", &Font12, WHITE, BLACK);
    EPD_2IN13_V2_Display(BlackImage);

    // partial refresh test
    EPD_2IN13_V2_Init(EPD_2IN13_V2_PART);
    Paint_SelectImage(BlackImage);
    struct timespec start={0,0}, finish={0,0}; 
    clock_gettime(CLOCK_REALTIME,&start);
    for(uint8_t i = 0; i<10; i++) {
        Paint_ClearWindows(0, 9, 10+i*10, 111,WHITE);
        Paint_DrawRectangle(i*10, 10, 10+i*10, 12, BLACK, DOT_PIXEL_1X1, DRAW_FILL_FULL);
        EPD_2IN13_V2_DisplayPart(BlackImage);
        DEV_Delay_ms(200);
    }
	clock_gettime(CLOCK_REALTIME,&finish);
    printf("total partial refresh time: %ld S\r\n",finish.tv_nsec-start.tv_nsec);

    free(BlackImage);
    BlackImage = NULL;
    
    return 0;
}
