#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

int main()
{
    int fd = 0;
    if ((fd = open("testfile.txt", O_RDONLY)) < -1)
        return 1;

    char buffer[19];
    if (read(fd, buffer, 19) != 19)
        return 1;
    printf("%s\n", buffer);

    if (lseek(fd, 10, SEEK_SET) < 0)
        return 1;

    if (read(fd, buffer, 19) != 19)
        return 1;
    printf("%s\n", buffer);

    return 0;
}
