#include<stdio.h>
#include<stdlib.h>

int main(){

        int i,j,n,max,seek=0,dir,flag=0,hidx,head;

        printf("Enter the no. of requests : ");
        scanf("%d",&n);

        int q[n+1];

        printf("Enter the requests : ");
        for(i=0;i<n;i++)
        scanf("%d",&q[i]);

        printf("Enter the position of the head : ");
        scanf("%d",&head);

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

        printf("Enter the max size of the disk : ");
        scanf("%d",&max);
        max--;

        printf("Enter the direction of the movement of the head ( 0 for left and 1 for right ) : ");
        scanf("%d",&dir);

        printf("Movement of the head is : %d", head);
        
        if(dir){

            for(i=hidx+1; i<n; i++){
                seek += abs(head-q[i]);
                printf(" -> %d",q[i]);
                head=q[i];
            }

            if(head!=max){
                seek += abs(head-max);
                printf(" -> %d", max);
                head = max;
            }

            for(i=hidx-1;i>=0;i--){
                seek += abs(head-q[i]);
                printf(" -> %d",q[i]);
                head=q[i];
            }
        }
        else{

            for(i=hidx-1;i>=0;i--){
                seek += abs(head-q[i]);
                printf(" -> %d",q[i]);
                head=q[i];
            }

            if(head!=0){
                seek += abs(head-0);
                printf(" -> 0");
                head = 0;
            }

            for(i=hidx+1; i<n; i++){
                seek += abs(head-q[i]);
                printf(" -> %d",q[i]);
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