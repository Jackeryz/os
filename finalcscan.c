#include<stdio.h>
#include<stdlib.h>

int main(){

    int i,j,n,dir,hidx,head,max,seek=0;

    printf("Enter the no. of requests : ");
    scanf("%d",&n);

    int q[n+1];

    printf("Enter the requests : ");
    for(i=0;i<n;i++)
    scanf("%d",&q[i]);

    printf("Enter the position of the head : ");
    scanf("%d",&head);
    int flag=0;
    for(i=0;i<n;i++)
    if(q[i]==head){
        flag=1;
        break;
    }
    if(!flag){
        q[n]=head;
        n++;
    }

    for(i=1;i<n;i++)
    for(j=0;j<n-i;j++)
        if(q[j]>q[j+1]){
            q[j] ^= q[j+1];
            q[j+1] ^= q[j];
            q[j] ^= q[j+1];
        }

    for(i=0;i<n;i++)
    if(q[i]==head){
    hidx=i;
    break;
    }

    printf("Enter the maximum size of the disk : ");
    scanf("%d",&max);
    max--;

    printf("Enter the direction of movement of the head ( 0 for left, 1 for right ) : ");
    scanf("%d",&dir);

    printf("Movement of disk : %d ",head);

    if(dir){
        for(i=hidx+1;i<n;i++){
            seek += abs(head - q[i]);
            printf("-> %d ",q[i]);
            head=q[i];
        }

        if(head!=max){
            printf("-> %d -> 0 ",max);
            seek += abs(head-max);
            head = 0;
        }
        else{
            printf("-> 0 ");
            head = 0;
        }
        seek += max;

        for(i=0;i<hidx;i++){
            seek += abs(head - q[i]);
            printf("-> %d ",q[i]);
            head=q[i];
        }

    }

    else{
        for(i=hidx-1;i>=0;i--){
            seek += abs(head - q[i]);
            printf("-> %d ",q[i]);
            head=q[i];
        }

        if(head!=0){
            printf("-> 0 -> %d ",max);
            seek += abs(head-0);
            head = max;
        }
        else{
            printf("-> %d ",max);
            head = max;
        }
        seek += max;

        for(i=n-1;i>hidx;i--){
            seek += abs(head - q[i]);
            printf("-> %d ",q[i]);
            head=q[i];
        }

    }

    if(!flag)
    n--;

    printf("\n");
    printf("Total seek time : %d\n",seek);
    printf("Average seek time : %.2f\n",(float)seek/n);

    return 0;
}