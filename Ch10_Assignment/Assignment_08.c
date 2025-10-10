/*****************************************************************************************************
   * 파일명: assign_08.c
   * 난이도: ★

   * 내용: 커피숍에서 판매되는 제품 정보를 나타내는 PRODUCT 구조체를 정의하시오. 각 제품별로 제품명, 가격, 재고를
           저장할 수 있어야 한다. PRODUCT 구조체를 매개변수로 전달받아 제품 정보를 출력하는 print_product 함수를
           정의하시오. PRODUCT 구조체 변수를 선언한 다음 제품명, 가격, 재고를 입력받아 저장하고 출력하는 프로그램을
           작성하시오. 참고로 제품명은 빈칸 없는 한 단어로 입력한다.

   * 작성자: 이상엽

   * 날짜: 2025.10.01

   * 버전: v1.0

 *******************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_NAME 20

struct PRODUCT
{
    char name[MAX_NAME]; // 제품명
    int price;           // 가격
    int many;           // 재고
};

void print_product(struct PRODUCT p);
int assign_08(void);

int main()
{
    assign_08();
    return 0;
}

int assign_08()
{
    struct PRODUCT item;

    printf("제품명? ");
    scanf("%s", item.name);

    printf("가격? ");
    scanf("%d", &item.price);

    printf("재고? ");
    scanf("%d", &item.many);

    print_product(item);

    return 0;
}

// 저장된 가격, 재고 출력하는 함수
void print_product(struct PRODUCT p)
{
    printf("[%s %d원 재고:%d]", p.name, p.price, p.many);
}