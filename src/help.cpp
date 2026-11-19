#include "../include/my-radar.hpp"

void help(void) {
    cout << "Air traffic simulation panel\nUSAGE";
    cout << "   ./my_radar [OPTIONS] path_to_script\n";
    cout << "   path_to_script  The path to the script file\n";
    cout << "OPTIONS\n";
    cout << "-h     print the usage and quit\n";
    cout << "'L' Key     enable/disable hitboxes and areas.\n";
    cout << "'S' Key     enable/disable sprites.\n";
}
