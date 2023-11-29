#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void createfile(const char *filename) {
    int file = creat(filename, 0666);
    if (file == -1) {
        perror("파일 생성 실패");
        exit(EXIT_FAILURE);
    }
    close(file);
    printf("파일 생성 완료\n");
}

void writefile(const char *filename, const char *content) {
    int file = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (file == -1) {
        perror("파일 열기 실패");
        exit(EXIT_FAILURE);
    }
    
    if (write(file, content, strlen(content)) == -1) {
        perror("파일 쓰기 실패");
        exit(EXIT_FAILURE);
    }
    
    close(file);
    printf("파일 쓰기 완료\n");
}

int main() {
    int choice;
    char filename[100];
    char content[100];

    printf("생성할 파일명을 입력하세요: ");
    scanf("%s", filename);

    createfile(filename);
            
    printf("파일에 쓸 내용을 입력하세요: ");
    scanf(" %[^\n]s", content);
    writefile(filename, content);

    return EXIT_SUCCESS;
}
