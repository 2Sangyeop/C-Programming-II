/*****************************************************************************************************
   * 파일명: assign_03.c
   * 난이도: ★★

   * 내용: LOGIN 구조체 배열을 이용해서 로그인 과정을 프로그램으로 작성하시오. 아이디를 입력받아
           LOGIN 구조체 배열에서 아이디를 찾은 다음 입력받은 패스워드와 등록된 패스워드를 비교해서
           같으면 "로그인 성공"이라고 출력한다. LOGIN 구조체 배열은 크기가 5인 배열로 선언하고
           적당한 값으로 초기화해서 사용한다.

   * 작성자: 이상엽

   * 날짜: 2025.10.01

   * 버전: v1.0

 *******************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 20

struct LOGIN {
    char id[MAX_SIZE];
    char password[MAX_SIZE];
};

int try_login(struct LOGIN users[], int count, char input_id[], char input_pw[]);
int assign_03(void);

int main()
{
    assign_03();
    return 0;
}
int assign_03()
{
    struct LOGIN users[5] =
    {
        {"guest", "Idontknow"},
        {"parkjisung", "manu123"},
        {"sonheungmin", "sonny"},
        {"leekangin", "paris123"},
        {"kimminjae", "german123"}
    };

    char input_id[MAX_SIZE];
    char input_pw[MAX_SIZE];

    while (1)
    {
        printf("ID? ");
        scanf("%20s", input_id);

        printf("PW: ");
        scanf("%20s", input_pw);

        if (try_login(users, 5, input_id, input_pw)) {
            printf("로그인 성공\n");

            break;
        }
        else {
            printf("로그인 실패\n");
        }
    }

    return 0;
}

//로그인 함수
int try_login(struct LOGIN users[], int count, char input_id[], char input_pw[])
{
    for (int i = 0; i < count; i++)
    {
        //아이디 확인
        if (strcmp(users[i].id, input_id) == 0) // 아이디 일치
        {
            //비밀번호 확인
            if (strcmp(users[i].password, input_pw) == 0)
            {
                return 1; //로그인 성공
            }
            else
            {
                return 0; // 로그인 실패
            }
        }
    }