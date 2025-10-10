/*****************************************************************************************************
   * 파일명: assign_03.c
   * 난이도: ★

   * 내용: 입력받은 문자열의 소문자는 대문자로, 대문자는 소문자로 변환하는 프로그램을 작성하시오.

   * 작성자: 이상엽

   * 날짜: 2025.10.

   * 버전: v1.0

 *******************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void swap_case(char* str);
int assign_03(void);

int main()
{
    assign_03();

    return 0;
}

// 대소문자 변환 함수
void swap_case(char* str)
{
    // 문자열의 끝(\0)까지 반복
    for (int i = 0; str[i] != '\0'; i++)
    {
        // 현재 문자
        char c = str[i];

        // 대문자　－＞　소문자
        if (isupper((unsigned char)c))
        {
            str[i] = tolower((unsigned char)c);
        }
        // 소문자　－＞　대문자
        else if (islower((unsigned char)c))
        {
            str[i] = toupper((unsigned char)c);
        }
    
    }
}

int assign_03(void)
{
    char line[256];

    // 문자열 입력
    printf("문자열? ");
    if (fgets(line, sizeof(line), stdin) == NULL) {
        return 1; 
    }

    // 대소문자 변환 함수 
    swap_case(line);

    // 결과 출력
    printf("변환 후: %s", line);

    return 0;
}