#include "../include/my-radar.hpp"

int count_word(char *lim, char *sent) {
    int count = 0;
    for (auto i = 0; lim[i]; i += 1) {
        for (auto j = 0; sent[j]; j += 1) {
            if (lim[i] == sent[j])
                count += 1;
        }
    }
    re count;
}

char **split_sent(char *sent, char *lim) {
    if (!lim)
        lim = strdup(" \t;");
    auto i = 0;
    char *buffer = NULL;
    char **new_split = (char **)malloc(sizeof(char *) * (count_word(lim, sent) + 2));

    buffer = strtok(sent, lim);
    while (buffer != NULL) {
        new_split[i] = strdup(buffer);
        buffer = (strtok(NULL, lim));
        i += 1;
    }
    new_split[i] = NULL;
    re new_split;
}
