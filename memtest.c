#include<stdio.h>
#include<stdbool.h>

void printUnallocated (int allocation[],int n){
    bool found = false;
    printf("Unallocated Process : ");
    for(int i=0;i<n;i++){
        if(allocation[i]==-1){
            printf("P%d ",i+1);
            found = true;
        }}
    if(!found)printf("None");
    printf("\n");
}

int best(int blocks[], bool allocated[], int m, int processes[], int n){
int allocation[n];
for (int i=0;i<n;i++)allocation[i]=-1;

for(int i=0;i<n;i++){
    int bestidx=-1;
    for(int j=0;j<m;j++){
        if((!allocated[m])&&blocks[j]>=processes[i])
            if(bestidx==-1||blocks[j]<blocks[bestidx])
            bestidx=j;
    }
    if(bestidx!=-1){
        allocation[i]=bestidx;
        allocated[bestidx]=true;
    }
}

printf("Best fit :\n");
for(int i=0;i<n;i++){
    printf("Process %d ->",i+1);
    if(allocation[i]!=-1) printf(" Block %d\n",allocation[i]+1);
    else printf("Not allocated\n");
}
printUnallocated(allocation,n);
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

    int blocks1[m];
    bool allocated1[m];
    for (int i = 0; i < m; i++) {
        blocks1[i] = memoryBlocks[i];
        allocated1[i] = false;
    }

    best(blocks1, allocated1, m, processSizes, n);


    return 0;
}