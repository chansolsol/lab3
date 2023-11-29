#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>

void listFilesRecursively(const char *basePath) {
    char path[1000];
    struct dirent *dp;
    DIR *dir = opendir(basePath);

    if (!dir) {
        perror("디렉토리 열기 실패");
        return;
    }

    while ((dp = readdir(dir)) != NULL) {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0) {
            printf("%s/%s\n", basePath, dp->d_name);

            // 디렉토리인 경우 재귀적으로 파일 목록 나열
            if (dp->d_type == DT_DIR) {
                sprintf(path, "%s/%s", basePath, dp->d_name);
                listFilesRecursively(path);
            }
        }
    }

    closedir(dir);
}

int main() {
    char basePath[100];

    printf("디렉토리 경로를 입력하세요: ");
    scanf("%s", basePath);

    printf("디렉토리 내 파일과 디렉토리 목록:\n");
    listFilesRecursively(basePath);

    return EXIT_SUCCESS;
}