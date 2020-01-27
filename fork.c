#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

main() {
 pid_t pid;
 int x = 5;
 pid = fork();
 x++;

 if (pid<0) {
  perror("Process creation error.");
  exit(-1);
 } else if (pid == 0) {
    printf("\nChild Process");
    printf("\nProcess ID: %d", getpid());
    printf("\nX = %d", x);
    printf("\n Parent PID: %d", getppid());
 } else {
    printf("\nParent Process");
    printf("\nPID : %d", getpid());
    printf("\nx = %d", x);
    printf("\nPPID : %d", getppid());
 }
}
