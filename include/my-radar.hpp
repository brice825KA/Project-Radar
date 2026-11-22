#ifndef _MY_RADAR_HPP_
#define _MY_RADAR_HPP_

    #include <iostream>
    #include <cstring>
    #include <cstdio>
    #include <raylib.h>
    #include <vector>
    #define re return
    #define WIDTH 800
    #define HEIGHT 700
    using namespace std;

typedef struct tower_s {
    float pos_x;
    float pos_y;
    double rayon;
} tower_t;

typedef struct plane_s {
    float start_x;
    float start_y;
    float end_x;
    float end_y;
    float speed;
    float delay;
} plane_t;

typedef struct parsing_s {
    vector<plane_t> planer;
    vector<tower_t> tour;
} parsing_t;

void help(void);
int count_word(char *lim, char *sent);
char **split_sent(char *sent, char *lim);
parsing_t stock_data(char *filename);
plane_t split_line_for_plane(char *line);
tower_t split_line_for_tower(char *line);
void loop_simulation(parsing_t parse);


#endif
