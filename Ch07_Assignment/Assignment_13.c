/*****************************************************************************************************
   * 파일명: assign_13.c

   * 내용: 비트 OR 연산자를 이용하면 두 이미지를 합칠 수 있다. 크기가 같은 2개의 unsigned char 배열을
           비트 OR 연산한 결과를 출력하는 프로그램을 작성하시오. unsigned char 배열 2개는 크기가 16인
           배열로 선언하고 임의의 데이터(0~255)를 채우고, 비트 OR 연산 결과를 저장할 배열을 따로 선언해서
           사용하시오.

   * 작성자: 이상엽

   * 날짜: 2025. 09. 16.

   * 버전: v1.0

 *******************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>\
#include <time.h>   

void bit_or_images(unsigned char img1[], unsigned char img2[], unsigned char img3[], int size);
void print_image(unsigned char img[], int size, const char* name);
int assign_13(void);

int main()
{
    assign_13();
    return 0;
}

// 두 이미지 배열을 OR 연산하여 출력하는 함수
int assign_13(void)
{
    unsigned char image1[16];
    unsigned char image2[16];
    unsigned char image3[16];

    srand((unsigned int)time(NULL));

    // image1, image2를 난수(0~255)로 채움
    for (int i = 0; i < 16; i++)
    {
        image1[i] = rand() % 256;
        image2[i] = rand() % 256;
    }

    // OR 연산 수행
    bit_or_images(image1, image2, image3, 16);

    // 출력
    print_image(image1, 16, "image1");
    print_image(image2, 16, "image2");
    print_image(image3, 16, "image3");

    return 0;
}

// 비트 OR 연산 수행
void bit_or_images(unsigned char img1[], unsigned char img2[], unsigned char img3[], int size)
{
    for (int i = 0; i < size; i++)
    {
        img3[i] = img1[i] | img2[i];
    }
}

// 배열 출력 함수
void print_image(unsigned char img[], int size, const char* name)
{
    printf("%s: ", name);
    for (int i = 0; i < size; i++)
    {
        printf("%02X ", img[i]);
    }
    printf("\n");
}
