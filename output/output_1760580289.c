void xor_buffer(char *buffer, int length) {
    for (int i = 0; i < length; i++) {
        buffer[i] ^= 1;
    }
}

int main(void) {
    int fd = open("/home/mistake/password", 0, 0x100);
    if (fd >= 0) {
        puts("do not bruteforce...");
        time_t now = time(NULL);
        int delay = ((int)now) % 20;
        sleep(delay);

        char expected[16];
        ssize_t bytes_read = read(0, expected, 10);
        if ((int)bytes_read < 1) {
            puts("read error");
            close(0);
        } else {
            char input[24];
            printf("input password : ");
            scanf("%s", input);
            xor_buffer(input, 10);

            int cmp = strncmp(expected, input, 10);
            if (cmp == 0) {
                puts("Password OK");
                system("/bin/cat flag\n");
            } else {
                puts("Wrong Password");
            }
            close(0);
        }
    } else {
        printf("can't open password %d\n", -(fd >> 31));
    }

    // Removed stack canary checks for readability

    return 0;
}