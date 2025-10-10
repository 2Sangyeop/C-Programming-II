/*****************************************************************************************************
   * 파일명: Assignment_15.c
   * 난이도: ★★★

   * 내용: 7장의 선택 정렬 코드를 이용해서 정수형 배열을 정렬하는 sort_array 함수를 정의하시오. 크기가 10인 int 
           배열에 0~99사이의 임의의 정수를 채운 다음 sort_array 함수로 정렬한 결과를 출력하는 프로그램을 
           작성하시오.

   * 작성자: 이상엽

   * 날짜: 2025. 09. 26.

   * 버전: v1.0

 *******************************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void sort_array(int arr[], int size);  // 선택 정렬 함수
int assign_15(void);

int main()
{
    assign_15();
    return 0;
}

// 선택 정렬 함수
void sort_array(int arr[], int size)
{
    int i, j, min_idx, temp;

    for (i = 0; i < size - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        // swap
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

int assign_15(void)
{
    int arr[SIZE];
    srand((unsigned int)time(NULL)); // 난수 시드 

    // 0~99 사이 임의 정수 생성
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % 100;
    }

    // 정렬 전 출력
    printf("정렬 전: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 정렬 수행
    sort_array(arr, SIZE);

    // 정렬 후 출력
    printf("정렬 후: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
