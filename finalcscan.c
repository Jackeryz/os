#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, n, head, dir, seek = 0, max;
    printf("Enter the number of requests: ");
    scanf("%d", &n);

    int q[n + 1];
    printf("Enter the requests: ");
    for (i = 0; i < n; i++)
        scanf("%d", &q[i]);

    printf("Enter the head: ");
    scanf("%d", &head);
    q[n] = head;
    n++; // total requests including head

    printf("Enter the maximum size of the disk: ");
    scanf("%d", &max);

    printf("Enter the direction (0 for left, 1 for right): ");
    scanf("%d", &dir);

    // Sort the array
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (q[j] > q[j + 1]) {
                int temp = q[j];
                q[j] = q[j + 1];
                q[j + 1] = temp;
            }

    // Find index of the head in sorted array
    int hidx;
    for (i = 0; i < n; i++)
        if (q[i] == head) {
            hidx = i;
            break;
        }

    printf("Movement of cylinders: %d", head);

    if (dir) { // Moving right
        // Move toward higher track numbers
        for (i = hidx + 1; i < n; i++) {
            printf(" -> %d", q[i]);
            seek += abs(head - q[i]);
            head = q[i];
        }

        // Jump to beginning
        if (head != max - 1) {
            seek += abs(head - (max - 1));
            head = 0;
            printf(" -> %d", max - 1);
            printf(" -> 0");
        } else {
            head = 0;
            printf(" -> 0");
        }

        seek += (max - 1); // from end to start (circular jump)

        // Now continue from the beginning
        for (i = 0; i < hidx; i++) {
            printf(" -> %d", q[i]);
            seek += abs(head - q[i]);
            head = q[i];
        }

    } else { // Moving left
        for (i = hidx - 1; i >= 0; i--) {
            printf(" -> %d", q[i]);
            seek += abs(head - q[i]);
            head = q[i];
        }

        // Jump to end
        if (head != 0) {
            seek += abs(head - 0);
            head = max - 1;
            printf(" -> 0");
            printf(" -> %d", max - 1);
        } else {
            head = max - 1;
            printf(" -> %d", max - 1);
        }

        seek += (max - 1); // from start to end (circular jump)

        // Now continue from the end
        for (i = n - 1; i > hidx; i--) {
            printf(" -> %d", q[i]);
            seek += abs(head - q[i]);
            head = q[i];
        }
    }

    printf("\nTotal seek time: %d\n", seek);
    printf("Average seek time: %.2f\n", (float)seek / (n - 1)); // exclude head

    return 0;
}
