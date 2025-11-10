/*****************************************************************************************************
   * 파일명: assign_13.c
   * 
   * 난이도: ★★

   * 내용: 정수의 개수 N을 입력받아 int가 N개 들어갈 수 있는 동적 메모리를 할당받는다. 이 배열에 임의의 정수를 
           N개 생성해서 채운 다음 텍스트 파일과 2진 파일로 각각 저장하는 프로그램을 작성하시오. 
           2진 파일로 저장할 때는 N을 먼저 저장하고, 배열의 내용을 저장하시오. 저장된 파일을 문서 편집기에서
           열어서 내용을 확인해보고 파일의 크기도 비교해본다.

   * 작성자: 이상엽

   * 날짜: 2025.11.10

   * 버전: v1.0

 *******************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* generate_array(int n);
void save_text_file(const char* filename, int* arr, int n);
void save_binary_file(const char* filename, int* arr, int n);
int assign_13(void);

int main()
{
    assign_13();
    return 0;
}

int assign_13()
{
    int N;
    int* arr = NULL;
    char filename[50];

    printf("정수의 개수? ");
    scanf("%d", &N);

    arr = generate_array(N);

    printf("파일명? ");
    scanf("%s", filename);

    save_text_file(filename, arr, N);
    save_binary_file(filename, arr, N);

    printf("%s.txt와 %s.dat를 생성했습니다.\n", filename, filename);

    free(arr);
    return 0;
}

// 배열 생성 + 난수 채움
int* generate_array(int n)
{
    int* arr = (int*)malloc(sizeof(int) * n);
    if (arr == NULL)
    {
        printf("메모리 할당 실패\n");
        exit(1);
    }

    srand((unsigned int)time(NULL));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000; // 0~999 사이 난수
    }

    return arr;
}

// 텍스트 파일 저장
void save_text_file(const char* filename, int* arr, int n)
{
    char txt_filename[60];
    sprintf(txt_filename, "%s.txt", filename);

    FILE* fp = fopen(txt_filename, "w");
    if (fp == NULL)
    {
        printf("텍스트 파일 생성 실패\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "%d\n", arr[i]);
    }

    fclose(fp);
}

// 2진 파일 저장
void save_binary_file(const char* filename, int* arr, int n)
{
    char bin_filename[60];
    sprintf(bin_filename, "%s.dat", filename);

    FILE* fp = fopen(bin_filename, "wb");
    if (fp == NULL)
    {
        printf("바이너리 파일 생성 실패\n");
        return;
    }

    fwrite(&n, sizeof(int), 1, fp);        // 먼저 N 저장
    fwrite(arr, sizeof(int), n, fp);       // 배열 내용 저장

    fclose(fp);
}
