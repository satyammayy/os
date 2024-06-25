#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MSG_LEN 64

int main() {
    int result;
    int fd[2];
    char message[MSG_LEN];
    char recvd_msg[MSG_LEN];  // Fix the typo here (was MSG_LE)

    // Creating a pipe: fd[0] is for reading and fd[1] is for writing
    result = pipe(fd);
    if (result < 0) {
        perror("pipe");
        exit(1);
    }

    strncpy(message, "Linux World!! ", MSG_LEN);
    result = write(fd[1], message, strlen(message) + 1);
    if (result < 0) {
        perror("write");
        exit(2);
    }

    strncpy(message, "Understanding ", MSG_LEN);
    result = write(fd[1], message, strlen(message) + 1);
    if (result < 0) {
        perror("write");
        exit(2);
    }

    strncpy(message, "Concepts of ", MSG_LEN);
    result = write(fd[1], message, strlen(message) + 1);
    if (result < 0) {
        perror("write");
        exit(2);
    }

    strncpy(message, "Piping ", MSG_LEN);
    result = write(fd[1], message, strlen(message) + 1);
    if (result < 0) {
        perror("write");
        exit(2);
    }

    // Read messages from the pipe
    while ((result = read(fd[0], recvd_msg, MSG_LEN)) > 0) {
        printf("Received: %s\n", recvd_msg);
    }

    if (result < 0) {
        perror("read");
        exit(3);
    }

    return 0;
}
