#include <stdio.h>

int main() {
    int n, f, rs[25], m[10], count[10], pf = 0, time = 0;

    printf("Enter the length of reference string: ");
    scanf("%d", &n);

    printf("Enter the reference string: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &rs[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &f);

    for (int i = 0; i < f; i++) {
        m[i] = -1;
        count[i] = 0;
    }

    printf("\nThe Page Replacement process is:\n");
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < f; j++) {
            if (m[j] == rs[i]) {
                found = 1;
                count[j] = ++time;
                break;
            }
        }

        if (!found) {
            int min = 0;
            for (int j = 1; j < f; j++) {
                if (count[j] < count[min]) {
                    min = j;
                }
            }
            m[min] = rs[i];
            count[min] = ++time;
            pf++;
        }

        for (int j = 0; j < f; j++) {
            if (m[j] != -1) {
                printf("%d\t", m[j]);
            } else {
                printf("-\t");
            }
        }
        if (!found) {
            printf("PF No. -- %d", pf);
        }
        printf("\n");
    }

    printf("\nThe number of page faults using LRU is %d\n", pf);

    return 0;
}
