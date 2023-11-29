#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    printf("부모 프로세스 생성 (PID: %d)\n", getpid());

    pid = fork(); // 자식 프로세스 생성

    if (pid == 0) {
        // 자식 프로세스
        printf("자식 프로세스 생성 (PID: %d, 부모 PID: %d)\n", getpid(), getppid());
        sleep(30); // 30초 대기
        printf("자식 프로세스 종료\n");
    } else {
        // 부모 프로세스
        printf("부모 프로세스에서 자식 프로세스 (PID: %d) 종료 대기 \n", pid);
        wait(NULL); // 자식 프로세스 종료를 대기
        printf("부모 프로세스 종료\n");
    }

    return 0;
}
