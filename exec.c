#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
main() {
pid_t pid;

switch(pid = fork()) {
case -1:
 perror("\nERR");
 exit(-1);

case 0:
 printf("\nChild Process\n");
 execl("/bin/date", "date", 0);
 exit(0);

case 1:
 wait("NULL");
 printf("\nChild terminated\n");
 exit(0);
}
}
