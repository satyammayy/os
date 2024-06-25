#include <stdio.h>

int main() {
    int nof, nor, ref[50], frm[50], pf = 0, victim = 0;

    printf("FIFO PAGE REPLACEMENT ALGORITHM\n");
    printf("Enter number of frames: ");
    scanf("%d", &nof);
    printf("Enter number of pages: ");
    scanf("%d", &nor);
    
    printf("Enter the page numbers: ");
    for (int i = 0; i < nor; i++) {
        scanf("%d", &ref[i]);
    }

    // Initialize frame array to -1
    for (int i = 0; i < nof; i++) {
        frm[i] = -1;
    }

    printf("Page Replacement Process:\n");
    for (int i = 0; i < nor; i++) {
        int flag = 0;
        // Check if page is already in frame
        for (int j = 0; j < nof; j++) {
            if (frm[j] == ref[i]) {
                flag = 1;
                break;
            }
        }

        // If page is not in frame, replace using FIFO
        if (flag == 0) {
            frm[victim] = ref[i];
            victim = (victim + 1) % nof;
            pf++;

            // Print current frame status
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
