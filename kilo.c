#include <termios.h>
#include <unistd.h>
#include <stdio.h>

void enableRawMode() {
    struct termios raw;

    tcgetattr(STDIN_FILENO, &raw);

    raw.c_lflag &= ~(ECHO);

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int main() {

    char c;
    while(read(STDIN_FILENO, &c, 1) == 1 && c != 'q');
    printf("Input: %c \n", c);
    return 0;
}
