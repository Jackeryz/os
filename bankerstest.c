#include<stdio.h>
#include<stdbool.h>

int i,j,k,l,y;

void read(int p, int r, int mat[p][r]){
    for (i=0;i<p;i++)
    for(j=0;j<r;j++)
    scanf("%d",&mat[i][j]);
}

void print(int p, int r, int mat[p][r]){
    for (i=0;i<p;i++){
    for(j=0;j<r;j++)
    printf("%d ",mat[i][j]);
    printf("\n");
    }
}

int main(){

    int p,r;
    printf("Enter the number of processes : ");
    scanf("%d",&p);
    printf("Enter the number of resources : ");
    scanf("%d",&r);

    int alloc[p][r],max[p][r],need[p][r],avail[p+1][r];
    printf("Enter the max matrix \n");
    read(p,r,max);
    printf("Enter the allocation matrix \n");
    read(p,r,alloc);
    for(i=0;i<p;i++)
    for(j=0;j<r;j++)
    need[i][j]=max[i][j]-alloc[i][j];
    printf("Enter the first row of available matrix \n");
    read(1,r,avail);
    bool f[p],flag;
    int ans[p],idx=0,aidx=0;
    for(i=0;i<p;i++)
    f[i]=false;

    for(i=0;i<p;i++)
    for(j=0;j<p;j++){
        if(!f[j]){
            flag=false;
            for(k=0;k<r;k++)
            if(need[j][k]>avail[aidx][k]){
            flag=true;
            break;
            }
            if(!flag){
                for(k=0;k<r;k++)
                avail[aidx+1][k]=avail[aidx][k]+alloc[j][k];
                aidx++;
                f[j]=true;
                ans[idx++]=j;
            }
        }
    }

    flag=false;
    for(i=0;i<p;i++)
    if(!f[i]){
    flag=true;
    break;
    }

    if(flag)
        printf("System is not in safe state\n");
    else{
        printf("Safe sequence is : ");
        for(i=0;i<p-1;i++)
        printf("P%d -> ",ans[i]);
        printf("P%d\n",ans[p-1]);
        printf("Need matrix is :\n");
        print(p,r,need);
        printf("Available matrix is :\n");
        print(p+1,r,avail);
        printf("Total resources : ");
        for(i=0;i<r;i++)
        printf("%d ",avail[p][i]);
    }

}