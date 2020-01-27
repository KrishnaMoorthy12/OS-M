#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

main() {
int i, status;
pid_t pid = fork();

if(pid < 0 ) {
perror("\n Process creation failure \n");
exit(-1);
} else if (pid > 0) {
wait(NULL);
printf("\nParent Starts\nEven Nos.:");
for (i = 2; i<=10; i+=2)
 printf("%3d", i);
printf("\nParent ends\n");
} else if(pid == 0) {
printf("\nChild starts\n Odd nos.:");
for (i = 1; i<10; i+=2)
 printf("%3d", i);
printf("\nChild ends\n");
}
}
