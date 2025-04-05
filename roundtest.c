#include <stdio.h>

typedef struct {
    int id, arrival_time, burst_time, waiting_time, turnaround_time, remaining_time;
} Process;

void swap(Process *a, Process *b) {
    Process temp = *a;
    *a = *b;
    *b = temp;
}

// Sort processes based on arrival time
void sortByArrival(Process proc[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (proc[j].arrival_time > proc[j + 1].arrival_time)
                swap(&proc[j], &proc[j + 1]);
        }
    }
}

void roundRobin(Process proc[], int n, int quantum) {
    int time = 0, completed = 0;
    float total_wt = 0, total_tat = 0;
    
    // Copy burst time to remaining time
    for (int i = 0; i < n; i++)
        proc[i].remaining_time = proc[i].burst_time;

    // Process queue simulation
    while (completed < n) {
        int executed = 0;
        for (int i = 0; i < n; i++) {
            if (proc[i].remaining_time > 0 && proc[i].arrival_time <= time) {
                executed = 1;
                int exec_time = (proc[i].remaining_time > quantum) ? quantum : proc[i].remaining_time;
                proc[i].remaining_time -= exec_time;
                time += exec_time;

                if (proc[i].remaining_time == 0) { // Process finished
                    completed++;
                    proc[i].waiting_time = time - proc[i].arrival_time - proc[i].burst_time;
                    if (proc[i].waiting_time < 0) proc[i].waiting_time = 0;
                    proc[i].turnaround_time = proc[i].waiting_time + proc[i].burst_time;
                    total_wt += proc[i].waiting_time;
                    total_tat += proc[i].turnaround_time;
                }
            }
        }
        if (!executed) time++; // Idle time if no process is ready
    }

    // Print results
    printf("Process\tAT\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\t%d\n", proc[i].id, proc[i].arrival_time, proc[i].burst_time, proc[i].waiting_time, proc[i].turnaround_time);

    printf("Average Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);
}

int main() {
    int n, quantum;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process proc[n];

    // Input process details
    for (int i = 0; i < n; i++) {
        proc[i].id = i + 1;
        printf("Enter arrival time and burst time for process %d: ", proc[i].id);
        scanf("%d %d", &proc[i].arrival_time, &proc[i].burst_time);
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    // Sort by arrival time before scheduling
    sortByArrival(proc, n);

    roundRobin(proc, n, quantum);
    return 0;
}
