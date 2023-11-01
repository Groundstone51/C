#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int GetRandom(int level);
void ShowQ(int level, int num1, int num2);
void success();
void fail();

int main(void) {
    srand(time(NULL)); // 시드 초기화

    int count = 0;
    for (int i = 1; i <= 5; i++) {
        int num1 = GetRandom(i);
        int num2 = GetRandom(i);
        ShowQ(i, num1, num2);
        int answer = -1;
        scanf_s("%d", &answer); // "\n" 제거
        if (answer == -1) {
            printf("프로그램을 종료합니다.");
            exit(0);
        }
        else if (answer == num1 * num2) {
            success();
            count++;
        }
        else {
            fail();
        }
    }
    printf("%d 개의 비밀번호를 맞췄습니다.", count);
    return 0;
}

int GetRandom(int level) {
    return rand() % (level * 9) + 1;
}

void ShowQ(int level, int num1, int num2) {
    printf("\n\n\n############ %d번째 비밀번호 #############\n", level);
    printf("%d x %d ? \n\n", num1, num2);
    printf("################################################\n");
    printf("\n비밀번호를 입력하세요.(종료를 원하면 -1)>>");
}

void success() {
    printf("성공!\n"); // 개행 문자 추가
}

void fail() {
    printf("실패!\n"); // 개행 문자 추가
}
