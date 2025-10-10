
/*****************************************************************************************************
   * 파일명: assign_13.c
   * 난이도: ★★

   * 내용: 직사각형 정보를 나타내는 RECT 구조체를 정의하시오. 직사각형은 좌하단점과 우상단점으로 구성되며
           점의 좌표는 POINT 구조체를 이용해서 나타낸다. 직사각형 정보를 출력하는 print_rect함수를 정의하고,
           RECT 구조체 변수를 선언해서 직사각형 정보를 입력받고 출력하는 프로그램을 작성하시오.

   * 작성자: 이상엽

   * 날짜: 2025.10.01

   * 버전: v1.0

 *******************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct POINT
{
    int x;
    int y;
};

struct RECT
{
    struct POINT left_bottom; // 좌하단점
    struct POINT right_top;   // 우상단점
};

void print_rect(struct RECT r);
int assign_13(void);

int main()
{
    assign_13();
    return 0;
}

// 직사각형 정보 입력함수
int assign_13()
{
    struct RECT rect;

    printf("직사각형의 좌하단점(x,y)? ");
    scanf("%d %d", &rect.left_bottom.x, &rect.left_bottom.y);

    printf("직사각형의 우상단점(x,y)? ");
    scanf("%d %d", &rect.right_top.x, &rect.right_top.y);

    // 출력
    print_rect(rect);

    return 0;
}

// 입력받은 정보를 출력하는 함수
void print_rect(struct RECT r)
{
    printf("[RECT 좌하단점:(%d, %d) 우상단점:(%d, %d)]\n",
        r.left_bottom.x, r.left_bottom.y, r.right_top.x, r.right_top.y);
}
