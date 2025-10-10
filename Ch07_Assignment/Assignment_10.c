/*****************************************************************************************************
   * 파일명: assign_10.c

   * 내용: 3x3 행렬의 합을 구하는 프로그램을 작성하시오. 행렬로 사용될 2차원 배열은 마음대로 초기화해도 된다.

   * 작성자: 이상엽

   * 날짜: 2025. 09. 16.

   * 버전: v1.0

 *******************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void add_result(int x[][3], int y[][3], int result[][3], int row, int column);
void print_result(char* title, int result[][3], int row, int column);
int assign_10(void);

int main()
{
    assign_10();
    return 0;
}


int assign_10(void)
{
    int x[3][3] = {
        {10, 20, 30},
        {40, 50, 60},
        {70, 80, 90}
    };

    int y[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int result[3][3];

    // 행렬 출력
    print_result("x 행렬:", x, 3, 3);
    print_result("y 행렬:", y, 3, 3);

    // 행렬 덧셈
    add_result(x, y, result, 3, 3);

    // 최종 행렬 결과 출력
    print_result("x + y 행렬:", result, 3, 3);

    return 0;
}

// 행렬 덧셈 함수
void add_result(int x[][3], int y[][3], int result[][3], int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            result[i][j] = x[i][j] + y[i][j];
        }
    }
}

// 행렬 출력 함수
void print_result(char* title, int result[][3], int row, int column)
{
    printf("%s\n", title);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}