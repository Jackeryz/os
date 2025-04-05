#include <stdio.h>
#include <stdbool.h>

struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int priority;
    int waiting_time;
    int turnaround_time;
    bool completed;
};

int main() {
    int n, i, j;
    float avg_waiting_time = 0, avg_turnaround_time = 0;

    // Input the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    // Input arrival time, burst time, and priority for each process
    for (i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter arrival time for process %d: ", processes[i].id);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time for process %d: ", processes[i].id);
        scanf("%d", &processes[i].burst_time);
        printf("Enter priority for process %d (lower number = higher priority): ", processes[i].id);
        scanf("%d", &processes[i].priority);
        processes[i].completed = false; // Initialize all processes as not completed
    }

    int current_time = 0;
    int completed_processes = 0;

    // Priority Scheduling Logic
    while (completed_processes < n) {
        int highest_priority = __INT_MAX__;
        int shortest_burst = __INT_MAX__;
        int shortest_index = -1;

        // Find the process with the highest priority (lowest number) that has arrived and is not completed
        for (i = 0; i < n; i++) {
            if (!processes[i].completed && processes[i].arrival_time <= current_time) {
                if (processes[i].priority < highest_priority || 
                    (processes[i].priority == highest_priority && processes[i].burst_time < shortest_burst)) {
                    highest_priority = processes[i].priority;
                    shortest_burst = processes[i].burst_time;
                    shortest_index = i;
                }
            }
        }

        if (shortest_index == -1) {
            // No process is available to execute, increment time
            current_time++;
        } else {
            // Execute the process with the highest priority (and shortest burst time in case of tie)
            processes[shortest_index].waiting_time = current_time - processes[shortest_index].arrival_time;
            processes[shortest_index].turnaround_time = processes[shortest_index].waiting_time + processes[shortest_index].burst_time;
            current_time += processes[shortest_index].burst_time;
            processes[shortest_index].completed = true;
            completed_processes++;
        }
    }

    // Display the table
    printf("\nProcess ID\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               processes[i].id,
               processes[i].arrival_time,
               processes[i].burst_time,
               processes[i].priority,
               processes[i].waiting_time,
               processes[i].turnaround_time);
    }

    // Calculate average waiting time and average turnaround time
    for (i = 0; i < n; i++) {
        avg_waiting_time += processes[i].waiting_time;
        avg_turnaround_time += processes[i].turnaround_time;
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;

    // Output the averages
    printf("\nAverage Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);

    return 0;
}

