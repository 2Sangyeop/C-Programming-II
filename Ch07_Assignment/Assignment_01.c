/*****************************************************************************************************
   * 파일명: assign_01.c

   * 내용: 등차수열은 앞의 항에 항상 일정한 수(공차)를 더하여 만들어가는 수열이다.
            크기가 10인 정수형 배열에 대하여 등차수열로 값을 채우려고 한다.
            첫 번째 항의 값과 공차(common difference)를 입력받아서 배열을 채우고 출력하는 프로그램을 작성하시오.

   * 작성자: 이상엽

   * 날짜: 2025. 09. 16.

   * 버전: v1.0

 *******************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void fill_array(int arr[], int size, int first, int diff);
int assign_01(void);

int main()
{
    assign_01();
    return 0;
}

// 등차수열을 배열에 채우고 출력하는 함수
int assign_01(void)
{
    int arr[10];
    int first, diff;

    printf("첫 번째 항? ");
    scanf("%d", &first);

    printf("공차? ");
    scanf("%d", &diff);

    // 등차수열을 배열에 채움
    fill_array(arr, 10, first, diff);

    // 결과 출력
    printf("등차수열: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

// 등차수열 함수
void fill_array(int arr[], int size, int first, int diff)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = first + i * diff;
    }
}