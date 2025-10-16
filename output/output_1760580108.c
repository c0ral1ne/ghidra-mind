#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void func(int magic_value);

int main(void)
{
    func(0xdeadbeef);
    return 0;
}

void func(int magic_value)
{
    // Removed stack canary checks inserted by the compiler.
    char input_buffer[32];
    gid_t gid1;
    gid_t gid2;

    printf("overflow me : ");
    gets(input_buffer);

    if (magic_value == -0x35014542) {
        gid1 = getegid();
        gid2 = getegid();
        setregid(gid2, gid1);
        system("/bin/sh");
    } else {
        puts("Nah..");
    }
}