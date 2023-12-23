#ifndef _VGA_HPP_
#define _VGA_HPP_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
enum COLORS{
    BLACK = 0,
    RED = 1,
    GREEN = 2,
    YELLOW = 3,
    BLUE = 4,
    PURPLE = 5,
    CYAN = 6,
    WHITE = 7
};
#define nop __asm__("nop \n");

#define SCREEN_W 54
#define SCREEN_H 30

void VGA_setup();
void set_VGAbuffer(char (*framebuf)[SCREEN_W]);
#endif