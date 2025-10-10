/*****************************************************************************************************
   * 파일명: assign_08.c

   * 내용: 상품 가격이 저장된 정수형 배열에 대하여 할인율(%)을 입력받아 할인된 가격을
           계산해서 출력하는 프로그램을 작성하시오. 상품 가격이 저장된 배열의 크기는 5이고,
           상품 가격은 입력받아서 사용한다. 할인된 가격은 별도의 배열에 저장해야 한다.

   * 작성자: 이상엽

   * 날짜: 2025. 09. 16.

   * 버전: v1.0

 *******************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void calc_discount(int price[], int discount_price[], int size, int rate);
int assign_08(void);

int main()
{
    assign_08();
    return 0;
}

// 상품 가격 배열을 입력받고 할인율을 적용해 출력하는 함수
int assign_08(void)
{
    int price[5];          // 원래 가격 배열
    int discount_price[5]; // 할인된 가격 배열
    int rate;

    printf("상품가 5개를 입력하세요:\n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &price[i]);
    }

    printf("할인율(%%)? ");
    scanf("%d", &rate);

    // 계산
    calc_discount(price, discount_price, 5, rate);

    // 결과 출력
    for (int i = 0; i < 5; i++)
    {
        printf("가격: %d --> 할인가: %d\n", price[i], discount_price[i]);
    }

    return 0;
}

// 할인된 가격을 계산하여 배열에 저장하는 함수
void calc_discount(int price[], int discount_price[], int size, int rate)
{
    for (int i = 0; i < size; i++)
    {
        discount_price[i] = price[i] * (100 - rate) / 100;
    }
}