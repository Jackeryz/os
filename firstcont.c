#include<stdio.h>

typedef struct {
    int ts,rs;
} Memory;

void Alloc (int p[], Memory m[], int np, int nm){

    int i,j;

    for(i=0;i<np;i++){
        int found = 0;
        
        for(j=0;j<nm;j++)
        if(m[j].rs>=p[i]){
            found=1;
            break;
        }

        if(!found)
            printf("Process P%d of size %d cannot be allocated \n",i+1,p[i]);

        else{
            m[j].rs -= p[i];
            printf("Process P%d of size %d is allocated in memory block %d of size %d, remaining size : %d \n",i+1,p[i],j+1,m[j].ts,m[j].rs);
        }
    }
}

void main(){

    int np,nm,i;

    printf("Enter the number of processes : ");
    scanf("%d",&np);
    printf("Enter the number of memory blocks : ");
    scanf("%d",&nm);

    int p[np];
    printf("Enter %d processes : ",np);
    for(i=0;i<np;i++)
    scanf("%d",&p[i]);

    Memory m[nm];
    printf("Enter %d memory blocks : ",nm);
    for(i=0;i<nm;i++){
    scanf("%d",&m[i].ts);
    m[i].rs=m[i].ts;
    }

    Alloc(p,m,np,nm);
}