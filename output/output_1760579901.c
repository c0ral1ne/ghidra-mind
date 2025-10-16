#include <stdio.h>
#include <string.h>

extern char tape[];
extern char *p;

void execute_brainfuck(unsigned char op)
{
    char *current_cell = p;
    int input_char;

    switch (op) {
        case '+':
            *p = *p + 1;
            break;
        case ',':
            input_char = getchar();
            *current_cell = (char)input_char;
            break;
        case '-':
            *p = *p - 1;
            break;
        case '.':
            putchar((int)*p);
            break;
        case '<':
            p = p - 1;
            break;
        case '>':
            p = p + 1;
            break;
        case '[':
            puts("[ and ] not supported.");
            break;
        default:
            break;
    }
}

int main(void)
{
    size_t input_length;
    int stack_guard_base;
    unsigned int index;
    char input_buffer[1024];
    int saved_stack_guard;

    saved_stack_guard = *(int *)(stack_guard_base + 0x14);
    setvbuf(stdout, NULL, 2, 0);
    setvbuf(stdin, NULL, 1, 0);
    p = tape;
    puts("welcome to brainfuck testing system!!");
    puts("type some brainfuck instructions except [ ]");
    memset(input_buffer, 0, 0x400);
    fgets(input_buffer, 0x400, stdin);
    index = 0;
    while (1) {
        input_length = strlen(input_buffer);
        if (input_length <= index) break;
        execute_brainfuck((unsigned char)input_buffer[index]);
        index = index + 1;
    }
    if (saved_stack_guard != *(int *)(stack_guard_base + 0x14)) {
        __stack_chk_fail();
    }
    return 0;
}