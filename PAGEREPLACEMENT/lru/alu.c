#include <stdio.h>
int main() {
    int nof, nor, ref[50], frm[50], count[50], pf = 0, time = 0;
    printf("LRU PAGE REPLACEMENT ALGORITHM\n");
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
        count[i] = 0;
    }
    printf("Page Replacement Process:\n");
    for (int i = 0; i < nor; i++) {
        int found = 0;
        for (int j = 0; j < nof; j++) {
            if (frm[j] == ref[i]) {
                found = 1;
                count[j] = ++time; 
                break;
            }
        }
        if (!found) {
            int min = 0;
            for (int j = 1; j < nof; j++) {
                if (count[j] < count[min]) {
                    min = j;
                }
            }
            frm[min] = ref[i];
            count[min] = ++time;
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
