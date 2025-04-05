#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define SHM_SIZE 1024

int main() {
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, SHM_SIZE, 0666);
    char *shared_memory = (char *)shmat(shmid, NULL, 0);

    while (1) {
        if (*shared_memory) {
            printf("Reader read: %s\n", shared_memory);
            if (strcmp(shared_memory, "exit") == 0)
                break;
            *shared_memory = '\0';  // Clear after reading
        }
        sleep(1);
    }

    shmdt(shared_memory);
    return 0;
}
