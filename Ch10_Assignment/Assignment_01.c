/*****************************************************************************************************
   * 파일명: assign_01.c
   * 난이도: ★

   * 내용: 인터넷 사이트에 로그인 할 때 사용되는 아이디와 패스워드를 관리하기 위한 LOGIN 구조체를 정의하시오.
           아이디와 패스워드는 각각 최대 20글자까지 입력할 수 있다. LOGIN 구조체 변수를 선언한 다음
           아이디와 패스워드를 입력받아 저장하고 출력하는 프로그램을 작성하시오. 패스워드를 출력할 때는
           패스워드의 내용은 보이지 않도록 패스워드 글자 수만큼 *을 대신 출력하시오.

   * 작성자: 이상엽

   * 날짜: 2025.10.01

   * 버전: v1.0

 *******************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 20

struct LOGIN
{
    char id[MAX_SIZE];
    char password[MAX_SIZE];
};

void input_login(struct LOGIN* user);
void print_login(const struct LOGIN* user);
int assign_01(void);

int main()
{
    assign_01();

    return 0;
}
int assign_01()
{
    struct LOGIN user;

    input_login(&user);
    print_login(&user);

    return 0;
}

// id, pw 입력 함수
void input_login(struct LOGIN* user)
{
    printf("ID? ");
    scanf("%20s", user->id);

    printf("Password? ");
    scanf("%20s", user->password);
}

// id, pw 출력 함수
void print_login(const struct LOGIN* user)
{
    printf("ID: %s\n", user->id);

    printf("PW: ");
    for (int i = 0; i < strlen(user->password); i++)
    {
        putchar('*');
    }
    printf("\n");
}