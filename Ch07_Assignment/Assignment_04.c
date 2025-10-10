/*****************************************************************************************************
   * 파일명: assign_04.c

   * 내용: 특정 값으로 초기화된 정수형 배열에 대하여 배열의 원소 중 최댓값을 가진 원소와 최솟값을 가진 원소를
           찾아서 인덱스와 값을 함께 출력하는 프로그램을 작성하시오.
           배열의 초기값은 마음대로 정하시오.

   * 작성자: 이상엽

   * 날짜: 2025. 09. 16.

   * 버전: v1.0

 *******************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void find_min_max(int arr[], int size);
int assign_04(void);

int main()
{
    assign_04();
    return 0;
}

// 배열에서 최댓값, 최솟값을 찾아 출력하는 함수
int assign_04(void)
{
    int arr[10] = { 23, 45, 62, 12, 99, 83, 23, 50, 72, 37 };

    printf("배열: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    find_min_max(arr, 10);

    return 0;
}

// 배열의 원소 중 최댓값을 가진 원소와 최솟값을 가진 원소를 찾는 함수
void find_min_max(int arr[], int size)
{
    int max = arr[0], min = arr[0];
    int max_index = 0, min_index = 0;

    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            max_index = i;
        }
        if (arr[i] < min)
        {
            min = arr[i];
            min_index = i;
        }
    }

    printf("최댓값: 인덱스=%d, 값=%d\n", max_index, max);
    printf("최솟값: 인덱스=%d, 값=%d\n", min_index, min);
}