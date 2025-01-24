#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int id;
    int profit;
    int deadline;
} Job;

//bubble sort
void sortJobs(Job jobs[], int n) {
    for (int i =0; i<n-1; i++){
        for (int j =0; j<n-i-1; j++) {
            if (jobs[j].profit < jobs[j + 1].profit) {
                Job temp = jobs[j];
                jobs[j] = jobs[j+1];
                jobs[j+1] = temp;
            }
        }
    }
}

//job scheduling
int JobScheduling (Job jobs[], int n) {
    //sort jobs based on profit
    sortJobs(jobs, n);

    int maxDeadline = 0;
    //find max deadline
    for (int i =0; i<n; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }

    //array to store the result of job scheduling
    bool result[maxDeadline+1];
    for (int i =0; i<=maxDeadline; i++) {
        result[i] = false;
    }

    int totalProfit = 0;
    int totalJobs = 0;

    //logic for job scheduling
    for (int i =0; i<n; i++) {
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (result[j] == false) {
                result[j] = true;
                totalProfit += jobs[i].profit;
                totalJobs++;
                break;
            }
        }
    }

    printf("Total jobs scheduled: %d\n", totalJobs);
    return totalProfit;
}

int main ()
{
    Job jobs[] = {
        {1, 100, 2},
        {2, 19, 1},
        {3, 27, 2},
        {4, 25, 1},
        {5, 15, 3}
    };
    int n = sizeof(jobs) / sizeof(jobs[0]);

    int totalProfit = JobScheduling(jobs, n);
    printf("Total profit: %d\n", totalProfit);
}
