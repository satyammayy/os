#include <stdio.h>

int main() {
    int burstTime[20], process[20], waitingTime[20], turnaroundTime[20];
    int i, j, numProcesses, total = 0;
    float avgWaitingTime, avgTurnaroundTime;

    // Input the number of processes
    printf("Enter number of processes: ");
    scanf("%d", &numProcesses);

    // Input burst time for each process
    printf("\nEnter Burst Time for each process:\n");
    for (i = 0; i < numProcesses; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &burstTime[i]);
        process[i] = i + 1;  // Process number
    }

    // Initialize waiting time for the first process
    waitingTime[0] = 0;

    // Calculate waiting time for each process
    for (i = 1; i < numProcesses; i++) {
        waitingTime[i] = 0;
        for (j = 0; j < i; j++) {
            waitingTime[i] += burstTime[j];
        }
        total += waitingTime[i];
    }

    // Calculate average waiting time
    avgWaitingTime = (float)total / numProcesses;
    total = 0;

    // Display process details
    printf("\nProcess\t Burst Time \tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < numProcesses; i++) {
        turnaroundTime[i] = burstTime[i] + waitingTime[i];  // Calculate turnaround time
        total += turnaroundTime[i];
        printf("Process %d\t %d\t\t %d\t\t %d\n", process[i], burstTime[i], waitingTime[i], turnaroundTime[i]);
    }

    // Calculate average turnaround time
    avgTurnaroundTime = (float)total / numProcesses;

    // Display average waiting time and average turnaround time
    printf("\nAverage Waiting Time = %.2f\n", avgWaitingTime);
    printf("Average Turnaround Time = %.2f\n", avgTurnaroundTime);

    return 0;
}
