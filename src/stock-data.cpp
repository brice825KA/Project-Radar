#include "../include/my-radar.hpp"

plane_t split_line_for_plane(char *line) {
    char **sent = split_sent(line, NULL);
    plane_t p = {0};
    p.start_x = atof(sent[1]);
    p.start_y = atof(sent[2]);
    p.end_x = atof(sent[3]);
    p.end_y = atof(sent[4]);
    p.speed = atof(sent[5]);
    p.delay = atof(sent[6]);
    delete sent;
    re p;
}

tower_t split_line_for_tower(char *line) {
    tower_t t {0};
    char **sent = split_sent(line, NULL);
    t.pos_x = atof(sent[1]);
    t.pos_y = atof(sent[2]);
    t.rayon = atof(sent[3]);
    delete sent;
    re t;
}

parsing_t stock_data(char *filename) {
    parsing_t parse;
    vector<plane_t> p;
    vector<tower_t> t;
    FILE *stream = fopen(filename, "r");
    size_t lenght = 0;
    char *buffer = NULL;
    while (getline(&buffer, &lenght, stream) != -1) {
        if (buffer[0] == 'A')
            p.push_back(split_line_for_plane(buffer));
        else if (buffer[0] == 'T')
            t.push_back(split_line_for_tower(buffer));
    }
    fclose(stream);
    parse.planer = p;
    parse.tour = t;
    re parse;
}
