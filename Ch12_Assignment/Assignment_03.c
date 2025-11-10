/*****************************************************************************************************
   * 파일명: assign_03.c
   
   * 난이도: ★★

   * 내용: 텍스트 파일의 이름을 입력 받아서 파일 내의 문자들에 대하여 영문자의 개수를 문자별로 세서 출력하는 
           프로그램을 작성하시오. 문자의 개수를 셀 때는 대소문자를 구분하지 않는다.

   * 작성자: 이상엽

   * 날짜: 2025.11.10

   * 버전: v1.0

 *******************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

#define MAX_SIZE 100

void input_filename(char* filename);
void print_file(const char* filename);
void count_letters(const char* filename, int counts[]);
void print_letter_count(const int counts[]);
int assign_03(void);

int main()
{
    assign_03();
    return 0;
}

int assign_03()
{
    char filename[MAX_SIZE];
    int counts[26] = { 0 };

    input_filename(filename);
    print_file(filename);
    count_letters(filename, counts);
    print_letter_count(counts);

    return 0;
}

// 파일 이름 입력
void input_filename(char* filename)
{
    printf("파일명? ");
    scanf("%s", filename);
}

// 파일 내용 출력
void print_file(const char* filename)
{
    FILE* fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("파일을 열 수 없습니다.\n");
        return;
    }

    char ch;
    while ((ch = fgetc(fp)) != EOF)
    {
        putchar(ch);
    }

    fclose(fp);
}

// 파일 내 영문자 개수 세기 (대소문자 구분 X)
void count_letters(const char* filename, int counts[])
{
    FILE* fp = fopen(filename, "r");
    if (fp == NULL)
        return;

    int ch;
    while ((ch = fgetc(fp)) != EOF)
    {
        if (isalpha(ch))
        {
            ch = tolower(ch);
            counts[ch - 'a']++;
        }
    }

    fclose(fp);
}

// 알파벳별 개수 출력
void print_letter_count(const int counts[])
{
    printf("\n\n");
    for (int i = 0; i < 26; i++)
    {
        if (counts[i] > 0)
        {
            printf("%c:%d  ", 'a' + i, counts[i]);
        }
    }
    printf("\n");
}
