#ifndef __CLOSEGL__HPP
#define __CLOSEGL__HPP
#include <vga.hpp>

void draw_cube(char (&buf)[SCREEN_H][SCREEN_W], int px_x, int px_y, char color);
void clear(char (&buf)[SCREEN_H][SCREEN_W]);
#endif