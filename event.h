#ifndef EVENT_H_INCLUDED
#define EVENT_H_INCLUDED

#include<stdbool.h>
bool initGL();
void arrowFunc(int key, int x, int y);
void update(int value);
void reshapeWindow(int width, int height);
void display();
//void camera();
#endif