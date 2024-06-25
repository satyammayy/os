#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MSG_LEN 64

int main() {
    int result;
    int fd[2];
    char message[MSG_LEN];
    char recvd_msg[MSG_LEN];

    result = pipe(fd);
    if (result < 0) {
        perror("pipe");
        exit(1);
    }

    const char *messages[] = {
        "Linux World!! ",
        "Understanding ",
        "Concepts of ",
        "Piping "
    };

    for (int i = 0; i < sizeof(messages) / sizeof(messages[0]); ++i) {
        strncpy(message, messages[i], MSG_LEN);
        result = write(fd[1], message, strlen(message));
        if (result < 0) {
            perror("write");
            exit(2);
        }
    }

    result = read(fd[0], recvd_msg, MSG_LEN);
    if (result < 0) {
        perror("read");
        exit(3);
    }

    printf("%s\n", recvd_msg);

    return 0;
}
