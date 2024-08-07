#include <stdio.h>

int h, m, inc;
int main() {
    scanf("%d%d%d", &h, &m, &inc);
    m += inc;
    h += m / 60;
    m %= 60;

    h %= 24;

    printf("%02d %02d", h, m);
}