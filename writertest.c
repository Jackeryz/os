#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define SHM_SIZE 1024

int main() {
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
    char *shared_memory = (char *)shmat(shmid, NULL, 0);

    while (1) {
        printf("Enter text: ");
        fgets(shared_memory, SHM_SIZE, stdin);
        shared_memory[strcspn(shared_memory, "\n")] = '\0';

        if (strcmp(shared_memory, "exit") == 0)
            break;

        sleep(1);
    }

    shmdt(shared_memory);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}
