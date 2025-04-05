#include <stdio.h>
#include <stdbool.h>

void printUnallocated(int allocation[], int n) {
    printf("Unallocated Processes: ");
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (allocation[i] == -1) {
            printf("P%d ", i + 1);
            found = true;
        }
    }
    if (!found) printf("None");
    printf("\n");
}

void firstFit(int blocks[], bool allocated[], int m, int processes[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++) allocation[i] = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!allocated[j] && blocks[j] >= processes[i]) {
                allocation[i] = j;
                allocated[j] = true;
                break;
            }
        }
    }
    printf("\nFirst Fit Allocation:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d -> ", i + 1);
        if (allocation[i] != -1) printf("Block %d\n", allocation[i] + 1);
        else printf("Not Allocated\n");
    }
    printUnallocated(allocation, n);
}

void bestFit(int blocks[], bool allocated[], int m, int processes[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++) allocation[i] = -1;

    for (int i = 0; i < n; i++) {
        int bestIdx = -1;
        for (int j = 0; j < m; j++) {
            if (!allocated[j] && blocks[j] >= processes[i]) {
                if (bestIdx == -1 || blocks[j] < blocks[bestIdx]) {
                    bestIdx = j;
                }
            }
        }
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            allocated[bestIdx] = true;
        }
    }
    printf("\nBest Fit Allocation:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d -> ", i + 1);
        if (allocation[i] != -1) printf("Block %d\n", allocation[i] + 1);
        else printf("Not Allocated\n");
    }
    printUnallocated(allocation, n);
}

void worstFit(int blocks[], bool allocated[], int m, int processes[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++) allocation[i] = -1;

    for (int i = 0; i < n; i++) {
        int worstIdx = -1;
        for (int j = 0; j < m; j++) {
            if (!allocated[j] && blocks[j] >= processes[i]) {
                if (worstIdx == -1 || blocks[j] > blocks[worstIdx]) {
                    worstIdx = j;
                }
            }
        }
        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            allocated[worstIdx] = true;
        }
    }
    printf("\nWorst Fit Allocation:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d -> ", i + 1);
        if (allocation[i] != -1) printf("Block %d\n", allocation[i] + 1);
        else printf("Not Allocated\n");
    }
    printUnallocated(allocation, n);
}

int main() {
    int m, n;
    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);
    int memoryBlocks[m];
    bool allocated[m];
    printf("Enter the sizes of %d memory blocks: ", m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &memoryBlocks[i]);
        allocated[i] = false;
    }

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int processSizes[n];
    printf("Enter the sizes of %d processes: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &processSizes[i]);
    }

    int blocks1[m], blocks2[m], blocks3[m];
    bool allocated1[m], allocated2[m], allocated3[m];
    for (int i = 0; i < m; i++) {
        blocks1[i] = blocks2[i] = blocks3[i] = memoryBlocks[i];
        allocated1[i] = allocated2[i] = allocated3[i] = false;
    }

    firstFit(blocks1, allocated1, m, processSizes, n);
    bestFit(blocks2, allocated2, m, processSizes, n);
    worstFit(blocks3, allocated3, m, processSizes, n);

    return 0;
}
