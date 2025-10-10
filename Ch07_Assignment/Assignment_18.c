/*****************************************************************************************************
   * 파일명: assign_18.c

   * 내용: 수학에서 집합(set)은 다중집합(multiset)과 다르게 원소의 중복을 허용하지 않는다. 최대 10개의
           정수형 원소를 저장할 수 있는 집합(set)을 구현하시오. 정수를 입력받아 집합의 원소로 추가하고,
           그 때마다 집합의 원소들을 출력하시오.

   * 작성자: 이상엽

   * 날짜: 2025. 09. 16.

   * 버전: v1.0

 *******************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int add_to_set(int set[], int* size, int value);
void print_set(int set[], int size);
int assign_18(void);

int main()
{
    assign_18();
    return 0;
}

int assign_18(void)
{
    int set[10];   // 집합 저장 배열
    int size = 0;
    int value;

    while (size < 10)
    {
        printf("배열에 추가할 원소? ");
        if (scanf("%d", &value) != 1) break; // 잘못된 입력이면 종료

        if (add_to_set(set, &size, value))
        {
            print_set(set, size);
        }
    }

    return 0;
}

// 집합에 원소 추가 (중복이면 메시지 출력 후 false 반환)
int add_to_set(int set[], int* size, int value)
{
    for (int i = 0; i < *size; i++)
    {
        if (set[i] == value)
        {
            printf("해당 원소가 이미 [%d]에 존재합니다.\n", i);
            return 0; // 중복
        }
    }

    if (*size < 10)
    {
        set[*size] = value;
        (*size)++;
        return 1; // 추가
    }
    else
    {
        printf("집합이 가득 찼습니다.\n");
        return 0; // 실패
    }
}

// 집합 출력
void print_set(int set[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", set[i]);
    }
    printf("\n");
}
