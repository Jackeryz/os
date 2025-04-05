#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0, out = 0;

int empty = BUFFER_SIZE;
int full = 0;
int mutex = 1;

void wait(int *s) {
    while (*s <= 0);
    (*s)--;
}

void signal(int *s) {
    (*s)++;
}

void produce() {
    wait(&mutex);
    if (empty > 0) {
        wait(&empty);
        
        int item;
        printf("Enter item to produce: ");
        scanf("%d", &item);
        
        buffer[in] = item;
        printf("Produced: %d\n", item);
        in = (in + 1) % BUFFER_SIZE;
        
        signal(&full);
    } else {
        printf("Buffer is full! Cannot produce.\n");
    }
    signal(&mutex);
}

void consume() {
    wait(&mutex);
    if (full > 0) {
        wait(&full);
        
        int item = buffer[out];
        printf("Consumed: %d\n", item);
        out = (out + 1) % BUFFER_SIZE;
        
        signal(&empty);
    } else {
        printf("Buffer is empty! Cannot consume.\n");
    }
    signal(&mutex);
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Produce\n2. Consume\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                produce();
                break;
            case 2:
                consume();
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
