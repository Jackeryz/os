#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t child_pid;

    // Create a child process
    child_pid = fork();

    if (child_pid == 0) {
        printf("Child process: PID=%d\n", getpid());
    } else if (child_pid > 0) {
        printf("Parent process: PID=%d, Child PID=%d\n", getpid(), child_pid);
    } else {
        perror("Fork failed");
    }

    return 0;
}
