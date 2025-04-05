#include <stdio.h>
#include <stdbool.h>

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
    printf("First Fit Allocation:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d -> Block %d\n", i + 1, allocation[i] + 1);
    }
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
    printf("Best Fit Allocation:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d -> Block %d\n", i + 1, allocation[i] + 1);
    }
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
    printf("Worst Fit Allocation:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d -> Block %d\n", i + 1, allocation[i] + 1);
    }
}

int main() {
    int memoryBlocks[] = {100, 500, 200, 300, 600};
    int processSizes[] = {212, 417, 112, 426};
    int m = sizeof(memoryBlocks) / sizeof(memoryBlocks[0]);
    int n = sizeof(processSizes) / sizeof(processSizes[0]);
    
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

