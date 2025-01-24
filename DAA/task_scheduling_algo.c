// Implement task scheduling algorithm using the following approach:
// 1. Initialize max_count to 0.
// 2. For each task, initialize count to 1.
// 3. For each other task, if it does not overlap with the current task, increment count.
// 4. If count is greater than max_count, update max_count.
// 5. Return max_count.
// Input: An array of tasks with start and end times
// Output: Maximum number of tasks that can be scheduled without overlapping
// time complexity: O(n^2)
// space complexity: O(1)

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
