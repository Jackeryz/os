#include <stdio.h>

#define MAX_PROCESSES 100

// Structure to store process information
typedef struct {
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int waitingTime;
    int turnAroundTime;
    int completionTime;
} Process;

void calculateAverageTimes(Process processes[], int n, int quantum);

int main() {
    int n, quantum;

    // Input number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process processes[n];

    // Input arrival time and burst time for each process
    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrivalTime);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burstTime);
        processes[i].remainingTime = processes[i].burstTime;
    }

    // Input time quantum
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    // Calculate the average waiting time and turnaround time
    calculateAverageTimes(processes, n, quantum);

    return 0;
}

void calculateAverageTimes(Process processes[], int n, int quantum) {
    int time = 0;
    int remainingProcesses = n;
    float totalWaitingTime = 0, totalTurnAroundTime = 0;

    // Round Robin Scheduling
    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");

    while (remainingProcesses > 0) {
        for (int i = 0; i < n; i++) {
            if (processes[i].remainingTime > 0) {
                int currentTime = time;

                // Update time and process remaining burst time
                if (processes[i].remainingTime > quantum) {
                    time += quantum;
                    processes[i].remainingTime -= quantum;
                } else {
                    time += processes[i].remainingTime;
                    processes[i].remainingTime = 0;
                    processes[i].completionTime = time;
                    processes[i].turnAroundTime = processes[i].completionTime - processes[i].arrivalTime;
                    processes[i].waitingTime = processes[i].turnAroundTime - processes[i].burstTime;
                    
                    totalWaitingTime += processes[i].waitingTime;
                    totalTurnAroundTime += processes[i].turnAroundTime;

                    remainingProcesses--;
                }

                // Print process details after each quantum
                if (processes[i].remainingTime == 0) {
                    printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, processes[i].arrivalTime, 
                           processes[i].burstTime, processes[i].completionTime, 
                           processes[i].waitingTime, processes[i].turnAroundTime);
                }
            }
        }
    }

    // Calculate and display averages
    printf("\nAverage Waiting Time: %.2f\n", totalWaitingTime / n);
    printf("Average Turnaround Time: %.2f\n", totalTurnAroundTime / n);
}


