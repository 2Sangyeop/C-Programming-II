/*****************************************************************************************************
   * 파일명: assign_16.c

   * 내용: 정수형 배열과 키 값을 매개변수로 전달받아 배열에서 키 값을 찾아 인덱스를 리턴하는 find_array
           함수를 작성하시오. 키 값을 찾을 수 없으면 -1를 리턴한다.

   * 작성자: 이상엽

  * 날짜: 2025. 09. 16.

   * 버전: v1.0

 *******************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int find_array(int arr[], int size, int key);
int assign_16(void);

int main()
{
    assign_16();
    return 0;
}

// 배열에서 키 값을 찾아 인덱스를 출력하는 함수
int assign_16(void)
{
    int arr[10] = { 23, 45, 62, 12, 99, 83, 23, 50, 72, 37 };
    int key;
    int index;

    // 배열 출력
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 키 값 입력
    printf("찾을 값? ");
    scanf("%d", &key);


    index = find_array(arr, 10, key);

    if (index != -1)
    {
        printf("%d는 %d번째 원소입니다.\n", key, index);
    }
    else
    {
        printf("%d는 배열에 없습니다.\n", key);
    }

    return 0;
}

// 배열에서 키 값을 찾아 인덱스값을 반환 (없으면 -1)
int find_array(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return i; //찾으면 인덱스 반환
        }
    }
    return -1; // 못 찾으면 -1
}
