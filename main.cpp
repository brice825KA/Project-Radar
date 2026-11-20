// Main Project Radar

#include "include/my-radar.hpp"

int main(int argc, char **argv) {
    if (argc == 1) {
        cout << "./my_radar: bad arguments: 0 given but 84 is required\nretry with -h\n";
        re 84;
    } else if (argc == 2 && strcmp(argv[1], "-h") == 0) {
        help();
        re 0;
    }
    parsing_t p = stock_data(argv[1]);
    re 0;
}
