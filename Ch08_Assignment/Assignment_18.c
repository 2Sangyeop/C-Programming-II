/*****************************************************************************************************
   * 파일명: Assignment_18.c
   * 난이도: ★★★

   * 내용: 수학에서 집합(Set)은 다중집합(multiset)과 다르게 원소의 중복을 허용하지 않는다. 정수형 배열과 배열의 
   크기, 현재 들어있는 원소의 개수를 매개변수로 전달해서 원소를 추가하는 add_to_set 함수를 작성하시오. 
   add_to_set이 호출되고 나면 현재 들어있는 원소의 개수가 증가되어야 한다. 원소는 최대 배열의 크기만큼만 추가할
   수 있다. 더 이상 원소를 추가할 수 없거나 이미 같은 값의 원소가 있으면 0을 리턴하고, 원소를 추가하는 경우에는
   1을 리턴한다. add_to_set 함수를 이용해서 입력받은 정수를 집합의 원소를 추가하고, 그 때마다 집합의 원소들을 출력하는
   프로그램을 작성하시오. 

   * 작성자: 이상엽

   * 날짜: 2025. 09. 26.

   * 버전: v1.0

 *******************************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 10

int add_to_set(int arr[], int size, int* count, int value);
int assign_18(void);

int main()
{
    assign_18();
    return 0;
}

// 집합에 원소 추가 함수
int add_to_set(int arr[], int size, int* count, int value)
{
    // 배열이 꽉 찼는지?
    if (*count >= size)
    {
        printf("집합이 가득 찼습니다.\n");
        return 0;
    }

    // 중복 확인
    for (int i = 0; i < *count; i++)
    {
        if (arr[i] == value)
        {
            printf("해당 원소가 이미 [%d]에 존재합니다.\n", i);
            return 0;
        }
    }

    // 원소 추가
    arr[*count] = value;
    (*count)++;
    return 1;
}

int assign_18(void)
{
    int arr[SIZE];
    int count = 0; // 현재 집합에 들어있는 원소 개수
    int value;

    while (1)
    {
        printf("배열에 추가할 원소? ");
        if (scanf("%d", &value) != 1) break; // 입력이 잘못되면 종료

        if (add_to_set(arr, SIZE, &count, value) == 1)
        {
            // 원소 추가 성공 시 현재 집합 출력
            for (int i = 0; i < count; i++)
                printf("%d ", arr[i]);
            printf("\n");
        }
        else
        {
            // 원소 추가 실패 시에도 현재 집합 출력
            for (int i = 0; i < count; i++)
                printf("%d ", arr[i]);
            printf("\n");
        }
    }

    return 0;
}
