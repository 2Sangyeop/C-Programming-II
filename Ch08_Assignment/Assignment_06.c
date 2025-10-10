/*****************************************************************************************************
   * 파일명: Assignment_06.c
   * 난이도: ★★

   * 내용: 정수형 배열에 대하여 배열의 원소 중 최댓값과 최솟값을 찾는 get_min_max 함수를 정의하시오.
           크기가 10인 int 배열에 대해서 원하는 값으로 초기값을 채운 다음 get_min_max 함수로 최댓값과
           최솟값을 찾아서 출력하시오.
           
   * 작성자: 이상엽

   * 날짜: 2025. 09. 26.

   * 버전: v1.0

 *******************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void get_min_max(int arr[], int size, int* min, int* max);
int assign_06(void);

int main()
{
    assign_06();
    return 0;
}

// 최댓값과 최솟값을 찾는 함수
void get_min_max(int arr[], int size, int* min, int* max)
{
    *min = arr[0];
    *max = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] < *min) *min = arr[i];
        if (arr[i] > *max) *max = arr[i];
    }
}

int assign_06(void)
{
    int arr[10] = { 12, 31, 43, 45, 67, 23, 87, 95, 23, 58 }; 
    int min, max;

    printf("배열: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 최솟값, 최댓값 찾기
    get_min_max(arr, 10, &min, &max);

    printf("최솟값: %d\n", min);
    printf("최댓값: %d\n", max);

    return 0;
}
