/*****************************************************************************************************
   * 파일명: assign_08.c
   * 난이도: ★★

   * 내용: 시저 암호는 간단한 치환 암호로 암호화하고자 하는 문자열의 각 알파벳을 특정 개수만큼 더하거나 빼서
           다른 알파벳으로 치환하는 방식이다. 예를 들어 B를 3만큼 더해서 치환하면 E가 되는 식이다. 문자열과
           키 값(치환할 문자의 이동거리)를 입력 받아서 암호화된 문자열을 출력하는 프로그램을 작성하시오.

   * 작성자: 이상엽

   * 날짜: 2025.10.

   * 버전: v1.0

 *******************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 256
#define A_SIZE 26 //알파벳개수

void c_Password(char* str, int key);
int assign_08(void);

int main()
{
    assign_08();
    return 0;
}

// 시저 암호 함수
void c_Password(char* str, int key)
{
    char ch;

    // 알파벳 개수는 26개, 이보다 큰 수자가 입력됐을 경우 오류 방지.
    key %= A_SIZE;

    for (int i = 0; str[i] != '\0'; i++)
    {
        ch = str[i];

        // 대문자 처리
        if (isupper((unsigned char)ch))
        {
            ch = ch + key;

            // 'Z'를 넘어갔을 때 계산식
            if (ch > 'Z') {
                ch = ch - A_SIZE;
            }
            // 'A'보다 작을 때 계산식
            else if (ch < 'A') {
                ch = ch + A_SIZE;
            }

            str[i] = ch;
        }
        // 소문자 처리
        else if (islower((unsigned char)ch))
        {
            ch = ch + key;

            // 'z'를 넘어갔을 때 계산식
            if (ch > 'z') {
                ch = ch - A_SIZE;
            }
            // 'a'보다 작아졌을 때 계산식
            else if (ch < 'a') {
                ch = ch + A_SIZE;
            }

            str[i] = ch;
        }
    }
}

// 과제 실행 함수
int assign_08(void)
{
    char str[SIZE];
    int key;
    char key_input[10];

    // 반복 루프 시작
    do {
        // 문자열 입력
        printf("문자열? ");
        if (fgets(str, sizeof(str), stdin) == NULL) return 1;

        // . 입력 시 종료
        if (strcmp(str, ".") == 0) {
            break;
        }

        // \n제거
        str[strcspn(str, "\n")] = '\0';

        // 암호 키 입력
        printf("암호 키(정수)? ");
        if (fgets(key_input, sizeof(key_input), stdin) == NULL) return 1;
        sscanf(key_input, "%d", &key);

        // 시저 암호 함수
        c_Password(str, key);

        // 결과 출력
        printf("암호화된 문자열: %s\n", str);

    } while (1);

    return 0;
}