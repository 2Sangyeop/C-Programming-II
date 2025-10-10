/*****************************************************************************************************
   * 파일명: Assignment_10.c
   * 난이도: ★★

   * 내용: 3x3 행렬의 합을 구하는 add_matrix 함수를 작성하시오. add_matrix 함수를 이용해서 행렬의 합을 구하는
           프로그램을 작성하시오. 행렬로 사용될 2차원 배열은 마음대로 초기화해도 된다.

   * 작성자: 이상엽

   * 날짜: 2025. 09. 26.

   * 버전: v1.0

 *******************************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 3

void add_matrix(int a[SIZE][SIZE], int b[SIZE][SIZE], int result[SIZE][SIZE]);
int assign_10(void);

int main()
{
    assign_10();
    return 0;
}

// 두 3x3 행렬의 합을 구하는 함수
void add_matrix(int a[SIZE][SIZE], int b[SIZE][SIZE], int result[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

int assign_10(void)
{
    int x[SIZE][SIZE] = {
        {10, 20, 30},
        {40, 50, 60},
        {70, 80, 90}
    };

    int y[SIZE][SIZE] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int result[SIZE][SIZE];

    printf("x 행렬:\n");
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            printf("%3d ", x[i][j]);
        printf("\n");
    }

    printf("y 행렬:\n");
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            printf("%3d ", y[i][j]);
        printf("\n");
    }

    // 행렬 덧셈
    add_matrix(x, y, result);

    printf("x + y 행렬:\n");
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            printf("%3d ", result[i][j]);
        printf("\n");
    }

    return 0;
}
