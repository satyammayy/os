#include <stdio.h>

int findOptimalPage(int frm[], int nof, int ref[], int nor, int currentIndex) {
    int optimalIndex = -1;
    int farthest = currentIndex;
    for (int i = 0; i < nof; i++) {
        int j;
        for (j = currentIndex; j < nor; j++) {
            if (frm[i] == ref[j]) {
                if (j > farthest) {
                    farthest = j;
                    optimalIndex = i;
                }
                break;
            }
        }
        if (j == nor) {
            return i;
        }
    }
    return (optimalIndex == -1) ? 0 : optimalIndex;
}
int main() {
    int nof, nor, ref[50], frm[50], pf = 0;
    printf("OPTIMAL PAGE REPLACEMENT ALGORITHM\n");
    printf("Enter number of frames: ");
    scanf("%d", &nof);
    printf("Enter number of pages: ");
    scanf("%d", &nor);
    printf("Enter the page numbers: ");
    for (int i = 0; i < nor; i++) {
        scanf("%d", &ref[i]);
    }
    for (int i = 0; i < nof; i++) {
        frm[i] = -1;
    }
    printf("Page Replacement Process:\n");
    for (int i = 0; i < nor; i++) {
        int flag = 0;
        for (int j = 0; j < nof; j++) {
            if (frm[j] == ref[i]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            int victim;
            for (int j = 0; j < nof; j++) {
                if (frm[j] == -1) {
                    victim = j;
                    break;
                }
            }
            if (frm[victim] != -1) {
                victim = findOptimalPage(frm, nof, ref, nor, i + 1);
            }
            frm[victim] = ref[i];
            pf++;
            for (int j = 0; j < nof; j++) {
                if (frm[j] != -1) {
                    printf("%d ", frm[j]);
                } else {
                    printf("- ");
                }
            }
            printf("\n");
        }
    }
    printf("Total page faults: %d\n", pf);
    return 0;
}
