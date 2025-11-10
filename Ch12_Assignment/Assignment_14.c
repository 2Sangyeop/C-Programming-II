/*****************************************************************************************************
   * 파일명: assign_14.c
   
   * 난이도: ★★★

   * 내용: 13번 프로그램을 실행해서 크기가 다른 2진 파일을 2개 생성한 다음 두 파일을 읽어서 하나의 int 배열을 
           생성한 다음 정렬 후에 다시 2진 파일로 저장하는 프로그램을 작성하시오.

   * 작성자: 이상엽

   * 날짜: 2025.11.10

   * 버전: v1.0

 *******************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int* load_binary_file(const char* filename, int* n);
void save_binary_file(const char* filename, int* arr, int n);
int* merge_and_sort(int* arr1, int n1, int* arr2, int n2, int* total);
int assign_14(void);

int main()
{
    assign_14();
    return 0;
}

int assign_14()
{
    char file1[50], file2[50], file_out[50];
    int n1, n2, total;
    int* arr1 = NULL, * arr2 = NULL, * merged = NULL;

    printf("첫 번째 파일명? ");
    scanf("%s", file1);
    arr1 = load_binary_file(file1, &n1);
    printf("정수 %d개를 읽었습니다.\n", n1);

    printf("두 번째 파일명? ");
    scanf("%s", file2);
    arr2 = load_binary_file(file2, &n2);
    printf("정수 %d개를 읽었습니다.\n", n2);

    merged = merge_and_sort(arr1, n1, arr2, n2, &total);

    printf("저장할 파일명? ");
    scanf("%s", file_out);
    save_binary_file(file_out, merged, total);
    printf("정수 %d개를 저장했습니다.\n", total);

    free(arr1);
    free(arr2);
    free(merged);

    return 0;
}

// 2진 파일 읽기 (첫 번째 int는 N)
int* load_binary_file(const char* filename, int* n)
{
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        printf("파일 열기 실패: %s\n", filename);
        exit(1);
    }

    fread(n, sizeof(int), 1, fp);
    int* arr = (int*)malloc(sizeof(int) * (*n));
    if (arr == NULL)
    {
        printf("메모리 할당 실패\n");
        exit(1);
    }

    fread(arr, sizeof(int), *n, fp);
    fclose(fp);
    return arr;
}

// 2진 파일 저장 (첫 번째 int는 N)
void save_binary_file(const char* filename, int* arr, int n)
{
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL)
    {
        printf("파일 생성 실패: %s\n", filename);
        return;
    }

    fwrite(&n, sizeof(int), 1, fp);
    fwrite(arr, sizeof(int), n, fp);

    fclose(fp);
}

// 두 배열 합치고 오름차순 정렬
int* merge_and_sort(int* arr1, int n1, int* arr2, int n2, int* total)
{
    *total = n1 + n2;
    int* merged = (int*)malloc(sizeof(int) * (*total));
    if (merged == NULL)
    {
        printf("메모리 할당 실패\n");
        exit(1);
    }

    for (int i = 0; i < n1; i++)
        merged[i] = arr1[i];
    for (int i = 0; i < n2; i++)
        merged[n1 + i] = arr2[i];

    // 단순 삽입 정렬
    for (int i = 1; i < *total; i++)
    {
        int key = merged[i];
        int j = i - 1;
        while (j >= 0 && merged[j] > key)
        {
            merged[j + 1] = merged[j];
            j--;
        }
        merged[j + 1] = key;
    }

    return merged;
}
