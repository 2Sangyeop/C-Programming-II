/*****************************************************************************************************
   * 파일명: assign_05.c
   * 난이도: ★★

   * 내용: 대소문자를 구분하지 않고 문자열을 비교하는 strcmp_ic 함수를 작성하시오. strcmp_ic(lhs, rhs) 함수의
           리턴값은 strcmp와 마찬가지로 lhs가 rhs보다 크면 0보다 큰 값, 두 문자열이 같으면 0, lhs가 rhs보다 
           작으면 0보다 작은 값을 리턴한다. strcmp_ic 함수를 이용해서 입력받은 두 문자열을 비교하는 프로그램을 
           작성하시오.

   * 작성자: 이상엽

   * 날짜: 2025.10.

   * 버전: v1.0

 *******************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 256

int strcmp_ic(const char* lhs, const char* rhs);
int assign_05(void);

int main()
{
    assign_05();
    return 0;
}

// 대소문자 구분하지 않고 문자열 비교 함수
int strcmp_ic(const char* lhs, const char* rhs)
{
   // 두 문자열 중 하나라도 NULL이 아닐 때 까지
    while (*lhs != '\0' && *rhs != '\0')
    {
        // 두 문자를 소문자로 변환해서 비교한다 ** tip 참고.
        char char_lhs = tolower((unsigned char)*lhs);
        char char_rhs = tolower((unsigned char)*rhs);

        if (char_lhs > char_rhs)
        {
            return 1; // lhs가 더 큰 경우에는 0보다 큰 값 반환
        }
        else if (char_lhs < char_rhs)
        {
            return -1; // lhs가 더 작으면 0보다 작은 값 반환
        }

        // 다음 문자로 이동
        lhs++;
        rhs++;
    }

    // 두 문자열의 길이가 같다면 0 반환
    if (*lhs == '\0' && *rhs == '\0')
    {
        return 0;
    }
    // lhs가 더 짧다면 (lhs가 먼저 끝났다면) -1 반환
    else if (*lhs == '\0')
    {
        return -1;
    }
    // rhs가 더 짧다면 (rhs가 먼저 끝났다면) 1 반환
    else
    {
        return 1;
    }
}

// 과제 실행 함수
int assign_05(void)
{
    char str1[SIZE], str2[SIZE];
    int result;

    // 첫 번째 문자열 입력
    printf("첫 번째 문자열 ? ");
    if (fgets(str1, sizeof(str1), stdin) == NULL) return 1;

    // 두 번째 문자열 입력
    printf("두 번째 문자열 ? ");
    if (fgets(str2, sizeof(str2), stdin) == NULL) return 1;

    // \n 제거 ** fgets는 \n도 함께 저장하므로.
    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';

    // 문자열 비교 함수
    result = strcmp_ic(str1, str2);

    // 결과 출력
    if (result == 0)
    {
        printf("%s와 %s가 같습니다.\n", str1, str2);
    }
    else if (result > 0)
    {
        printf("%s가 %s보다 큽니다.\n", str1, str2);
    }
    else 
    {
        printf("%s가 %s보다 작습니다.\n", str1, str2);
    }

    return 0;
}