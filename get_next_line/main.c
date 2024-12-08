#include "get_next_line.h"


int main() {
    int fd = open("empty", O_RDONLY);
    int i = 1;
    char *s;

    while (s = get_next_line(fd))
    {
        printf("%d: %s", i++, s);
        free(s);
    }
}