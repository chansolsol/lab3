#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

#define BUFFER_SIZE 25

int main() {
    int fd[2];
    pid_t pid;
    char messageOut[BUFFER_SIZE] = "Hello, world!";
    char messageIn[BUFFER_SIZE];

    if (pipe(fd) == -1) {
        fprintf(stderr, "파이프 생성 실패\n");
        return EXIT_FAILURE;
    }

    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "프로세스 생성 실패\n");
        return EXIT_FAILURE;
    }

    if (pid > 0) {
        // 부모 프로세스
        close(fd[0]);  

        printf("부모 프로세스 전송 : %s\n", messageOut);
        write(fd[1], messageOut, strlen(messageOut) + 1);
        close(fd[1]);  
    } else {
        // 자식 프로세스
        close(fd[1]);  

        read(fd[0], messageIn, BUFFER_SIZE);
        printf("자식 프로세스 수신 : %s\n", messageIn);
        close(fd[0]);  
    }

    return EXIT_SUCCESS;
}
