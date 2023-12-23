#include <closeGL.hpp>
#include <string.h>


//draw one pixel cube for test
void draw_cube(char (&buf)[SCREEN_H][SCREEN_W], int px_x, int px_y, char color){
    buf[px_y][px_x] = color;
}

void clear(char (&buf)[SCREEN_H][SCREEN_W]){
    memset(buf, 0, SCREEN_H + SCREEN_W);
}