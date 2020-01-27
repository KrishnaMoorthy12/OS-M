#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>

main(int argc, char* argv[]) {
int fd, n, len;
char buf[100];
if(argc != 2) {
perror("\nUsage: ./a.out <filename.extension>\n");
exit(-1);
}
fd = open(argv[1], O_WRONLY|O_CREAT|O_TRUNC, 0644);
if (fd <0) {
 perror("ERR");
 exit(-1);
}
printf("\nPress Ctrl + D to exit.\n");
while ((n =  read(0, buf, sizeof(buf))) > 0) {
 len = strlen(buf);
 write(fd, buf, len);
}
 close(fd);
}