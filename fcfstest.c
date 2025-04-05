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
float atat,awt;

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

for (int i=1;i<n;i++)
	for(int j=0;j<n-i;j++)
	if(p[j].at>p[j+1].at){
struct Process temp = p[j];
	p[j] = p[j+1];
	p[j+1]= temp;

	}

int ct = 0;

for(int i=0;i<n;i++){
if(ct<p[i].at)
ct = p[i].at;
p[i].wt=ct-p[i].at;
p[i].tat=p[i].bt+p[i].wt;
ct+=p[i].bt;
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



