#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int mySystem(const char *command) {
    pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, "프로세스 생성 실패\n");
        return -1;
    } else if (pid == 0) {
        execlp("/bin/sh", "sh", "-c", command, NULL);
        exit(EXIT_SUCCESS);
    } else {
        int status;
        waitpid(pid, &status, 0);
        return status;
    }
}

int main() {
    char command[100];

    printf("실행할 명령어를 입력하세요: ");
    fgets(command, sizeof(command), stdin);

    command[strcspn(command, "\n")] = '\0';
    int status = mySystem(command);

    return EXIT_SUCCESS;
}
