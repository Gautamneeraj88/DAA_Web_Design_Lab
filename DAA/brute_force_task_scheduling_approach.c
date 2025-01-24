// implement the brute force task scheduling approach
// Input: An array of tasks with start and end times
// Output: Maximum number of tasks that can be scheduled without overlapping
// Time Complexity: O(n^2)
// Space Complexity: O(1)

#include <stdio.h>

typedef struct {
    int start;
    int end;
} Task;

int max_tasks(Task tasks[], int n) {
    int max_count = 0;

    for (int i = 0; i < n; i++) {
        int count = 1;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                if (tasks[j].end <= tasks[i].start || tasks[j].start >= tasks[i].end) {
                    count++;
                }
            }
        }
        if (count > max_count) {
            max_count = count;
        }
    }

    return max_count;
}

int main() {
    int n;
    printf("Enter the number of tasks: ");
    scanf("%d", &n);
    Task tasks[n];
    printf("Enter the start and end times of the tasks: \n");
    for (int i = 0; i < n; i++) {
        printf("Task %d: ", i + 1);
        scanf("%d %d", &tasks[i].start, &tasks[i].end);
    }
    printf("Maximum number of tasks that can be scheduled: %d\n", max_tasks(tasks, n));
    return 0;
}
