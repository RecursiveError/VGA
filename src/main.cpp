#include <vga.hpp>
#include <closeGL.hpp>
#include <string.h>

char buffer_1[SCREEN_H][SCREEN_W] = {
{ WHITE,0,1,2,3,4,5,6,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,},
{ WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,},
{ WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,CYAN,CYAN,CYAN,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,},
{ WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,},
{ WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,},
{ WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,},
{ WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,WHITE,WHITE,WHITE,WHITE,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,},
{ WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,WHITE,WHITE,WHITE,WHITE,},
{ WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,WHITE,WHITE,WHITE,},
{ WHITE,WHITE,WHITE,WHITE,WHITE,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,WHITE,WHITE,},
{ WHITE,WHITE,WHITE,WHITE,WHITE,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,CYAN,CYAN,CYAN,CYAN,CYAN,WHITE,WHITE,},
{ WHITE,WHITE,WHITE,WHITE,WHITE,CYAN,CYAN,CYAN,CYAN,CYAN,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,CYAN,CYAN,CYAN,CYAN,CYAN,WHITE,WHITE,WHITE,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,WHITE,WHITE,},
{ WHITE,WHITE,WHITE,WHITE,WHITE,CYAN,CYAN,CYAN,CYAN,CYAN,WHITE,WHITE,WHITE,WHITE,WHITE,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,WHITE,WHITE,},
{ WHITE,WHITE,WHITE,WHITE,WHITE,CYAN,CYAN,CYAN,CYAN,WHITE,WHITE,WHITE,WHITE,WHITE,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,WHITE,WHITE,CYAN,CYAN,CYAN,WHITE,WHITE,CYAN,CYAN,WHITE,WHITE,},//-<<
{ WHITE,WHITE,WHITE,WHITE,WHITE,CYAN,CYAN,CYAN,CYAN,WHITE,WHITE,WHITE,WHITE,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,WHITE,WHITE,WHITE,WHITE,CYAN,WHITE,WHITE,WHITE,WHITE,CYAN,WHITE,WHITE,},
{ WHITE,WHITE,WHITE,WHITE,WHITE,CYAN,CYAN,CYAN,CYAN,WHITE,WHITE,WHITE,WHITE,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,WHITE,WHITE,WHITE,WHITE,CYAN,WHITE,WHITE,WHITE,WHITE,CYAN,WHITE,WHITE,},
{ WHITE,WHITE,WHITE,WHITE,WHITE,CYAN,CYAN,CYAN,CYAN,WHITE,WHITE,WHITE,WHITE,WHITE,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,WHITE,WHITE,CYAN,CYAN,CYAN,WHITE,WHITE,CYAN,CYAN,WHITE,WHITE,},//<<<
{ WHITE,WHITE,WHITE,WHITE,WHITE,CYAN,CYAN,CYAN,CYAN,CYAN,WHITE,WHITE,WHITE,WHITE,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,WHITE,WHITE,},
{ WHITE,WHITE,WHITE,WHITE,WHITE,CYAN,CYAN,CYAN,CYAN,CYAN,WHITE,WHITE,WHITE,WHITE,WHITE,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,WHITE,WHITE,WHITE,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,WHITE,WHITE,},
{ WHITE,WHITE,WHITE,WHITE,WHITE,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,CYAN,CYAN,CYAN,CYAN,CYAN,WHITE,WHITE,},
{ WHITE,WHITE,WHITE,WHITE,WHITE,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,WHITE,WHITE,},
{ WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,WHITE,WHITE,WHITE,},
{ WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,WHITE,WHITE,WHITE,WHITE,},
{ WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,},
{ WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,},
{ WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,},
{ WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,CYAN,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,},
{ WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,CYAN,CYAN,CYAN,CYAN,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,},
{ WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,},
{ WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,},};

int main(void){
    set_VGAbuffer(buffer_1);
    VGA_setup();
    for(;;){

    }
    return 0;
}