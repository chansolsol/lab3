#include <stdio.h>
#include <time.h>

#define MAX_TEXT_LENGTH 500

void typingPractice(const char *text) {
    printf("타자 연습을 시작합니다. 아래의 텍스트를 입력하세요.\n\n%s\n", text);

    clock_t startTime = clock();

    char userInput[MAX_TEXT_LENGTH];
    fgets(userInput, MAX_TEXT_LENGTH, stdin);

    clock_t endTime = clock();

    int errors = 0, typedCharacters = 0;
    for (int i = 0; text[i] != '\0' && userInput[i] != '\0'; i++) {
        typedCharacters++;

        if (text[i] != userInput[i]) {
            errors++;
        }
    }

    double totalTime = (double)(endTime - startTime) / CLOCKS_PER_SEC; // 초 단위로 변환
    double typingSpeed = (typedCharacters * 60.0) / totalTime;  // 분당 타자수 계산

    printf("\n오타 수: %d\n", errors/2);
    printf("평균 분당 타자수: %.2f\n", typingSpeed/1000000);
}

int main() {
    const char *practiceText = "나가자 푸른 바다로 우리의 사명은 여길세 지키자 이 바다 생명을 다 하여";

    typingPractice(practiceText);

    return 0;
}