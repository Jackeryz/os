#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

main(void) {
        pid\_t pid = 0;

        pid = fork();
        if (pid == 0) {
                printf("I am the child.\\n");
        }
        if (pid > 0) {
                printf("I am the parent, the child is %d.\\n", pid);
        }
        if (pid < 0) {
                perror("In fork():");
        }

        exit(0);
}
