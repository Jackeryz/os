#include <stdio.h>

void algo(int p[], int n, int f) {
    int frames[f], freq[f]; // frequencies of pages in frames
    int faults = 0, hits = 0;

    for (int i = 0; i < f; i++) {
        frames[i] = -1;
        freq[i] = 0;
    }

    for (int j = 0; j < n; j++) {
        int page = p[j];
        int found = -1;

        for (int i = 0; i < f; i++) {
            if (frames[i] == page) {
                found = i;
                break;
            }
        }

        if (found != -1) {
            hits++;
            freq[found]++;
        } else {
            faults++;

            int minFreq = 1e9, replaceIndex = -1;

            for (int i = 0; i < f; i++) {
                if (frames[i] == -1) {
                    replaceIndex = i;
                    break;
                }
                if (freq[i] < minFreq) {
                    minFreq = freq[i];
                    replaceIndex = i;
                }
            }

            frames[replaceIndex] = page;
            freq[replaceIndex] = 1;
        }
    }

    printf("Total number of hits: %d and faults: %d\n", hits, faults);
}

int main() {
    int n, f;
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    printf("Enter the number of frames: ");
    scanf("%d", &f);
    int p[n];
    printf("Enter the pages: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    algo(p, n, f);
    return 0;
}
