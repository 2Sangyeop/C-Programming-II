/*****************************************************************************************************
   * 파일명: assign_01.c
   * 난이도: ★

   * 내용: 한 줄의 문자열을 입력받아서 공백 문자 (' ', \n, \t, \f, \r, \v)의 개수를 세는 프로그램을 작성하시오.

   * 작성자: 이상엽

   * 날짜: 2025.10.

   * 버전: v1.0

 *******************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h＞

int count_space(const char* str);
int assign_01(void);

int main()
{
    assign_01();
    return 0;
}

// 공백 문자 개수 세는 함수
int count_space(const char* str)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isspace((unsigned char)str[i])) count++;
    }
    return count;
}

// 과제 실행 함수
int assign_01(void)
{
    char line[256];
    int space_count;

    // 문자열 입력
    printf("문자열? ");

    if (fgets(line, sizeof(line), stdin) == NULL) {
        return 1;
    }

    // 공백 개수 계산
    space_count = count_space(line);

    // 결과 출력
    printf("공백 문자의 개수: %d\n", space_count);

    return 0;
}