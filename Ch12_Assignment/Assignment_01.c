/*****************************************************************************************************
   * 파일명: assign_01.c
   
   * 난이도: ★

   * 내용: 텍스트 파일의 이름을 입력받아서 파일의 내용을 라인 번호와 함께 출력하는 프로그램을 작성하시오.
   
   * 작성자: 이상엽

   * 날짜: 2025.11.10

   * 버전: v1.0

 *******************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_SIZE 100

void input_filename(char* filename);
void print_file_with_line(const char* filename);
int assign_01(void);

int main()
{
    assign_01();
    return 0;
}

int assign_01()
{
    char filename[MAX_SIZE];

    input_filename(filename);
    print_file_with_line(filename);

    return 0;
}

// 파일 이름 입력 함수
void input_filename(char* filename)
{
    printf("파일명? ");
    scanf("%s", filename);
}

// 파일 내용을 줄 번호와 함께 출력하는 함수
void print_file_with_line(const char* filename)
{
    FILE* fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("파일을 열 수 없습니다.\n");
        return;
    }

    char line[256];
    int line_num = 1;

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        printf("%d: %s", line_num, line);
        line_num++;
    }

    fclose(fp);
}
