#ifndef _TEXTBOX_
#define _TEXTBOX_

#include "raylib.h"

#define MAX_INPUT_CHARS     40

struct textBox{
    char message[MAX_INPUT_CHARS + 1];
    Rectangle rect;
    int max;
    bool mouseOnText;
    int letterCount;
    int framesCounter;
    textBox(int x, int y, int w, int h, int max);
    void update();
    void draw();
    void setMessage(const char newMessage[MAX_INPUT_CHARS + 1]);
};

#endif