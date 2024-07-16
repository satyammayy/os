#include <stdio.h>

int main() {
    int nor, nof, ref[25], frm[10], count[10], pf = 0, time = 0;

    // Get the length of the reference string
    printf("Enter the length of reference string: ");
    scanf("%d", &nor);

    // Get the reference string
    printf("Enter the reference string: ");
    for (int i = 0; i < nor; i++) {
        scanf("%d", &ref[i]);
    }

    // Get the number of frames
    printf("Enter the number of frames: ");
    scanf("%d", &nof);

    // Initialize frames and counters
    for (int i = 0; i < nof; i++) {
        frm[i] = -1;
        count[i] = 0;
    }

    printf("\nThe Page Replacement process is:\n");

    for (int i = 0; i < nor; i++) {
        int found = 0;
        // Check if the page is already in a frame
        for (int j = 0; j < nof; j++) {
            if (frm[j] == ref[i]) {
                found = 1;
                count[j] = ++time; // Update the usage time for LRU
                break;
            }
        }

        if (!found) {
            // Find the least recently used page
            int min = 0;
            for (int j = 1; j < nof; j++) {
                if (count[j] < count[min]) {
                    min = j;
                }
            }
            // Replace the LRU page with the current page
            frm[min] = ref[i];
            count[min] = ++time; // Update the usage time for LRU
            pf++;
        }

        // Print the current frame status
        for (int j = 0; j < nof; j++) {
            if (frm[j] != -1) {
                printf("%d\t", frm[j]);
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
