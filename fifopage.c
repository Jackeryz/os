#include<stdio.h>

void Func(int p[], int n, int f){

    int i, j, hits = 0, faults = 0, front = 0, frames[f];

    for(i=0; i<f; i++) frames[i]=-1;

    for(i=0;i<n;i++){

        int found = 0;
        
        for(j=0;j<f;j++)
            if(frames[j]==p[i]){
                found = 1;
                hits++;
                break;
            }

            if(!found){
                faults++;
                frames[front] = p[i];
                front = (front+1)%f;
            }

    }

    printf("The no. of hits : %d\nThe no. of faults : %d\n",hits,faults);
    printf("Hit ratio : %d:%d\nFault ratio : %d:%d",hits,hits+faults,faults,hits+faults);
        
}

void main(){

    int n,f;

    printf("Enter the no. of pages : ");
    scanf("%d",&n);
    
    printf("Enter the no. of frames : ");
    scanf("%d",&f);

    int p[n];
    printf("Enter %d pages : ",n);
    for(int i=0;i<n;i++)
    scanf("%d",&p[i]);

    Func(p,n,f);

}