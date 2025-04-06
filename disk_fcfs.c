#include<stdio.h>
#include<stdlib.h>

int main(){
    
    int i,n,diff,seek=0;
    printf("Enter the number of positions : ");
    scanf("%d",&n);
    printf("Enter the queue of positions : ");
    int q[n+1];
    for(i=1;i<=n;i++)
    scanf("%d",&q[i]);
    printf("Enter the head position : ");
    scanf("%d",&q[0]);
    printf("Movement of cylinders : ");

    for(i=0;i<n;i++){
        diff=abs(q[i+1]-q[i]);
        seek+=diff;
        printf("%d -> ",q[i]);
    }
    printf("%d\n",q[n]);
    printf("Total seek time : %d\n",seek);
    printf("Average seek time : %.2f\n",(float)seek/n);

}