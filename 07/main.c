#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handleSignal(int signal) {
    if (signal == SIGINT) {
        printf("인터럽트 발생, 프로그램을 종료합니다...\n");
        exit(EXIT_FAILURE);
    } else if(signal == SIGTSTP){
        printf("인터럽트 발생, 프로그램을 종료합니다...\n");
        exit(EXIT_FAILURE);
    }
}

int main() {
    // 시그널 핸들러 설정
    signal(SIGINT, handleSignal);
    signal(SIGTSTP, handleSignal);

    printf("인터럽트 신호 입력 대기중\n");

    while (1) {
        
    }

    printf("프로그램 종료\n");
}
