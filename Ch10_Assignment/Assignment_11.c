/*****************************************************************************************************
   * 파일명: assign_11.c
   * 난이도: ★★★

   * 내용: PRODUCT 구조체 배열을 이용해서 제품명을 입력받아 검색 후 주문처리하는 프로그램을 작성하시오. 주문 
           수량을 입력받아 결제 금액을 알려주고, 제품 재고를 주문 수량만큼 감소시켜야 한다. 제품명으로 검색할
           수 없거나 찾은 제품의 재고가 주문 수량보다 적으면 에러 메시지를 출력한다. PRODUCT 구조체 배열은 
           크기가 5인 배열로 선언하고 적당한 값으로 초기화해서 사용한다.
  
  * 작성자: 이상엽

   * 날짜: 2025.10.01

   * 버전: v1.0

 *******************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_NAME 30
#define SIZE 3

struct PRODUCT
{
    char name[MAX_NAME];
    int price;
    int many;

};

void print_product(struct PRODUCT p);
void print_all(struct PRODUCT list[], int n);
int assign_11(void);

int main()
{
    assign_11();    
    return 0;
}
int assign_11()
{
    struct PRODUCT list[SIZE] =
    {
        { "아메리카노", 4000, 10 }, { "카페라떼", 4500, 10 },{ "플랫화이트", 5000, 10 }
    };

    char inputname[MAX_NAME];
    int order;

    while (1)
    {
        printf("주문할 제품명? ");
        scanf("%s", inputname);

        // 주문 종료 
        if (strcmp(inputname, ".") == 0) break;

        int i;
        for (i = 0; i < SIZE; i++)
        {
            if (strcmp(list[i].name, inputname) == 0) {
                // 제품 찾아서 주문
                printf("주문할 수량? ");
                scanf("%d", &order);

                if (order > list[i].many) {
                    printf("재고가 부족합니다.\n");
                }
                else {
                    list[i].many -= order;
                    int total = list[i].price * order;
                    printf("결제 금액: %d  %s 재고: %d\n", total, list[i].name, list[i].many);
                }
                break; // \종료
            }
        }

        if (i == SIZE)
        {
            printf("제품을 찾을 수 없습니다.\n");
        }
    }

    print_all(list, SIZE);
    return 0;
}

void print_product(struct PRODUCT p)
{
    printf("[%s %d원 재고:%d]", p.name, p.price, p.many);
}

void print_all(struct PRODUCT list[], int n)
{
    for (int i = 0; i < n; i++) {
        print_product(list[i]);
        printf("\n"); 
    }
}