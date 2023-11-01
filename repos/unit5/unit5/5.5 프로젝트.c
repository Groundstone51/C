#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int GetRandom(int level);
void ShowQ(int level, int num1, int num2);
void success();
void fail();

int main(void) {
    srand(time(NULL)); // �õ� �ʱ�ȭ

    int count = 0;
    for (int i = 1; i <= 5; i++) {
        int num1 = GetRandom(i);
        int num2 = GetRandom(i);
        ShowQ(i, num1, num2);
        int answer = -1;
        scanf_s("%d", &answer); // "\n" ����
        if (answer == -1) {
            printf("���α׷��� �����մϴ�.");
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
    printf("%d ���� ��й�ȣ�� ������ϴ�.", count);
    return 0;
}

int GetRandom(int level) {
    return rand() % (level * 9) + 1;
}

void ShowQ(int level, int num1, int num2) {
    printf("\n\n\n############ %d��° ��й�ȣ #############\n", level);
    printf("%d x %d ? \n\n", num1, num2);
    printf("################################################\n");
    printf("\n��й�ȣ�� �Է��ϼ���.(���Ḧ ���ϸ� -1)>>");
}

void success() {
    printf("����!\n"); // ���� ���� �߰�
}

void fail() {
    printf("����!\n"); // ���� ���� �߰�
}
