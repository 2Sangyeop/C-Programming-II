/*****************************************************************************************************
   * 파일명: assign_06.c

   * 내용: 크기가 10인 실수형 배열에 대해서 원소들을 역순으로 만드는 프로그램을 작성하시오.
           실수형 배열의 초기값은 마음대로 정하시오.

   * 작성자: 이상엽

   * 날짜: 2025. 09. 16.

   * 버전: v1.0

 *******************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void reverse_array(double arr[], int size);
int assign_06(void);

int main()
{
    assign_06();
    return 0;
}

// 배열을 역순으로 출력하는 함수
int assign_06(void)
{
    double arr[10] = { 1.2, 3.1, 4.3, 4.5, 6.7, 2.3, 8.7, 9.5, 2.3, 5.8 };

    // 원래 배열 출력
    printf("배열: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%.1f ", arr[i]);
    }
    printf("\n");

    // 역순으로 출력
    reverse_array(arr, 10);

    return 0;
}

// 배열을 역순으로 만둘어 출력 
void reverse_array(double arr[], int size)
{
    printf("역순: ");
    for (int i = size - 1; i >= 0; i--)
    {
        printf("%.1f ", arr[i]);
    }
    printf("\n");
}