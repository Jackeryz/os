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
    int already_present = 0;
    for (i = 0; i < n; i++)
        if (q[i] == head) {
            already_present = 1;
            break;
        }
    if (!already_present) {
        q[n] = head;
        n++;
    }
              

    printf("Enter the maximum size of the disk: ");
    scanf("%d", &max);

    printf("Enter the direction (0 for left, 1 for right): ");
    scanf("%d", &dir);

    for (i = 1; i < n; i++)
        for (j = 0; j < n - i; j++)
            if (q[j] > q[j + 1]) {
                q[j] ^= q[j+1];
                q[j+1] ^= q[j];
                q[j] ^= q[j+1];
            }

    int hidx;
    for (i = 0; i < n; i++)
        if (q[i] == head) {
            hidx = i;
            break;
        }

    printf("Movement of cylinders: %d", head);

    if (dir) { // Moving right
        for (i = hidx + 1; i < n; i++) {
            printf(" -> %d", q[i]);
            seek += abs(head - q[i]);
            head = q[i];
        }
        if (head != max - 1) {
            printf(" -> %d", max - 1);
            seek += abs(head - (max - 1));
            head = max - 1;
        }
        for (i = hidx - 1; i >= 0; i--) {
            printf(" -> %d", q[i]);
            seek += abs(head - q[i]);
            head = q[i];
        }
    }
    
    
    
    else { // Moving left
        for (i = hidx - 1; i >= 0; i--) {
            printf(" -> %d", q[i]);
            seek += abs(head - q[i]);
            head = q[i];
        }
        if (head != 0) {
            printf(" -> 0");
            seek += abs(head - 0);
            head = 0;
        }
        for (i = hidx + 1; i < n; i++) {
            printf(" -> %d", q[i]);
            seek += abs(head - q[i]);
            head = q[i];
        }
    }

    printf("\nTotal seek time: %d\n", seek);
    printf("Average seek time: %.2f\n", (float)seek / (n - 1)); // exclude head

    return 0;
}
