#ifndef _CONFIG_
#define _CONFIG_

typedef struct {
    int win_x;
    int win_y;
    int win_w;
    int win_h;
    
    int bg_r;
    int bg_g;
    int bg_b;
    int bg_a;

    int text_r;
    int text_g;
    int text_b;
    int text_a;

    int bar_r;
    int bar_g;
    int bar_b;
    int bar_a;

    bool i3;
}Config;

#endif