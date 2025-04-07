#include<stdio.h>

typedef struct {
    int ts,rs;
} Memory;

void Alloc(int p[], Memory m[], int np, int nm){

    for(int i=0;i<np;i++){

        int found = -1,sm = __INT_MAX__,pr = p[i];
        for(int j=0;j<nm;j++){
            if(m[j].rs>=pr && m[j].rs<sm){
                found = j;
                sm = m[j].rs;
            }

        }

    if(found==-1)
            printf("Process P%d of size %d cannot be allocated \n",i+1,pr);

        else{
            m[found].rs -= pr;
            printf("Process P%d of size %d is allocated in memory block %d of size %d, remaining size : %d \n",i+1,pr,found+1,m[found].ts,m[found].rs);
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