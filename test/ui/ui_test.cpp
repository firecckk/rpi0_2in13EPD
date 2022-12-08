#include <stdlib.h>
//#include "UI.h"
#include "SdlScreen.cpp"

#define IMAGE_SIZE 80 * HEIGHT

int main() {
    SdlScreen screen = SdlScreen();

    UBYTE *BlackImage;
    //UWORD Imagesize = ((WIDTH % 8 == 0)? (WIDTH / 8 ): (WIDTH / 8 + 1)) * HEIGHT;
    UWORD Imagesize = IMAGE_SIZE;
    if((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL) {
        printf("Failed to apply for black memory...\r\n");
        return -1;
    }
    while(!screen.quit) {
        screen.handleEvent();
        screen.display(BlackImage);
    }
    screen.~SdlScreen();
    //App_Init();
    //App_Uninit();
}

