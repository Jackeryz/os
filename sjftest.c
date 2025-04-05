#include<stdio.h>

struct Process {
int id;
int at;
int bt;
int wt;
int tat;
};

int main(){
int n;
float atat = 0, awt = 0;

printf("Enter the number of processes \n");
scanf("%d",&n);
struct Process p[n];

printf("Enter the arrival time and burst time of all processes\n");
for(int i=0;i<n;i++){
p[i].id=i+1;
printf("Enter the arrival time of process %d : ",p[i].id);
scanf("%d",&p[i].at);
printf("Enter the burst time of process %d : ",p[i].id);
scanf("%d",&p[i].bt);
}

for(int i=1; i<n; i++)
for(int j=0; j<n-i; j++)
if(p[j].at>p[j+1].at||(p[j].at==p[j+1].at&&p[j].bt>p[j+1].bt)){
    struct Process temp = p[j];
    p[j] = p[j+1];
    p[j+1] = temp;
}

int completed = 0;
int ct = 0;
int v[n];
for(int i=0; i<n; i++)
v[i]=0;

while(completed<n){
    int shi = -1;
    int sht = 1e9;

    for (int i=0; i<n; i++)
    if(!v[i] && p[i].at<=ct && p[i].bt<sht){
        sht = p[i].bt;
        shi = i;
    }

    if(shi==-1)
        ct++;
    else{
    v[shi]=1;
    p[shi].wt=ct-p[shi].at;
    p[shi].tat=p[shi].bt+p[shi].wt;
    ct+=p[shi].bt;
    completed++;
    }
}

printf("Process \t Arrival time \t Burst time \t Waiting time \t Turn around time\n");
for(int i=0;i<n;i++){
printf ("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].id,p[i].at,p[i].bt,p[i].wt,p[i].tat);
atat+=p[i].tat;
awt+=p[i].wt;}

atat/=n;
awt/=n;
printf("Average waiting time : %.2f \n",awt);
printf("Average turn around time : %.2f \n",atat);

return 0;
}