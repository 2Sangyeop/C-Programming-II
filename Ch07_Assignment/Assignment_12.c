/*****************************************************************************************************
   * 파일명: assign_12.c

   * 내용: 기차표 예매 프로그램을 작성하려고 한다. 간단한 구현을 위해 좌석은 모두 10개라고 하자.
           예매할 좌석수를 입력받아 빈 자리를 할당한다. 예매할 때마다 각 좌석의 상태를 출력한다.
           O이면 예매 가능, X는 예매 불가를 의미한다. 더 이상 예매할 수 없으면 프로그램을 종료한다.

   * 작성자: 이상엽

   * 날짜: 2025. 09. 16.

   * 버전: v1.0

 *******************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_seats(char seats[], int size);
void buy_seats(char seats[], int size);
int assign_12(void);

int main()
{
    assign_12();
    return 0;
}

int assign_12(void)
{
    char seats[10];
    int total = 10;

    // 좌석 
    for (int i = 0; i < total; i++)
    {
        seats[i] = 'O';
    }

    while (1)
    {
        print_seats(seats, total);

        // 예매 가능한 좌석이 남아 있는지 확인
        int available = 0;
        for (int i = 0; i < total; i++)
        {
            if (seats[i] == 'O')
                available++;
        }

        if (available == 0)
        {
            printf("더 이상 예매할 수 없습니다.\n");
            break;
        }

        buy_seats(seats, total);
    }

    return 0;
}

// 좌석 상태 출력 함수
void print_seats(char seats[], int size)
{
    printf("현재좌석: [ ");
    for (int i = 0; i < size; i++)
    {
        printf("%c ", seats[i]);
    }
    printf("]\n");
}

// 좌석 구매 함수
void buy_seats(char seats[], int size)
{
    int count;
    printf("예매할 좌석수? ");
    scanf("%d", &count);

    if (count <= 0)
    {
        printf("잘못된 좌석 수입니다.\n");
        return;
    }

    int sold = 0;
    printf("예매된 좌석 번호: ");
    for (int i = 0; i < size && sold < count; i++)
    {
        if (seats[i] == 'O')
        {
            seats[i] = 'X';
            printf("%d ", i + 1);
            sold++;
        }
    }
    printf("번 좌석을 예매했습니다.\n");
}