#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>

int main()
{
    char d[100];
    int op;
    struct dirent *sd;

    printf("** Menu **\n1. Create directory\n2. Remove directory\n3. Read directory\nEnter your choice: ");
    scanf("%d", &op);

    switch (op)
    {
    case 1:
        printf("Enter directory name: ");
        scanf("%s", d);
        if (mkdir(d) == -1)
            printf("Directory not created.\n");
        else
            printf("Directory created.\n");
        break;

    case 2:
        printf("Enter directory name: ");
        scanf("%s", d);
        if (rmdir(d) == -1)
            printf("Directory not removed.\n");
        else
            printf("Directory removed.\n");
        break;

    case 3:
        printf("Enter directory name to open: ");
        scanf("%s", d);
        DIR *e = opendir(d);
        if (e == NULL)
            printf("Directory does not exist.\n");
        else
        {
            printf("Directory exists. Contents:\n");
            while ((sd = readdir(e)) != NULL)
                printf("%s\t", sd->d_name);
            printf("\n");
            closedir(e);
        }
        break;

    default:
        printf("Invalid choice.\n");
        break;
    }

    return 0;
}
