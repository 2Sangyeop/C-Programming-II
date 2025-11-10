/*****************************************************************************************************
   * 파일명: assign_04.c
   
   * 난이도: ★★

   * 내용: 아이디와 패스워드가 저장된 텍스트 파일을 크기가 10인 LOGIN 구조체 배열로 읽어온 다음, 입력 받은 아이디와
           패스워드가 일치하면 "로그인 성공" 아니면 "로그인 실패"라고 출력하는 프로그램을 작성하시오. 텍스트 파일의 
           형식은 다음과 같다.
           [password.txt]
           guest idontknow
           sugasuga bts_awesome
           rapmonster spring@day
           jimin lovearmy

   * 작성자: 이상엽

   * 날짜: 2025.11.10

   * 버전: v1.0

 *******************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 20
#define MAX_USERS 10

struct LOGIN {
    char id[MAX_SIZE];
    char password[MAX_SIZE];
};

int load_login_file(const char* filename, struct LOGIN users[]);
int find_user_index(const struct LOGIN users[], int count, const char* id);
int check_password(const struct LOGIN* user, const char* password);
int assign_04(void);

int main()
{
    assign_04();
    return 0;
}

int assign_04()
{
    struct LOGIN users[MAX_USERS];
    int user_count = 0;
    char id[MAX_SIZE];
    char password[MAX_SIZE];
    int idx;

    user_count = load_login_file("password.txt", users);

    while (1)
    {
        printf("ID? ");
        scanf("%s", id);

        // 종료 조건
        if (strcmp(id, ".") == 0)
            break;

        idx = find_user_index(users, user_count, id);

        if (idx == -1)
        {
            printf("아이디를 찾을 수 없습니다.\n");
            continue;
        }

        printf("Password? ");
        scanf("%s", password);

        if (check_password(&users[idx], password))
            printf("로그인 성공\n");
        else
            printf("로그인 실패\n");
    }

    return 0;
}

// 파일에서 ID와 PW 읽어오기
int load_login_file(const char* filename, struct LOGIN users[])
{
    FILE* fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("파일을 열 수 없습니다.\n");
        return 0;
    }

    int count = 0;
    while (fscanf(fp, "%s %s", users[count].id, users[count].password) == 2)
    {
        count++;
        if (count >= MAX_USERS)
            break;
    }

    fclose(fp);
    return count;
}

// ID 검색 함수
int find_user_index(const struct LOGIN users[], int count, const char* id)
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(users[i].id, id) == 0)
            return i;
    }
    return -1;
}

// 비밀번호 확인 함수
int check_password(const struct LOGIN* user, const char* password)
{
    return strcmp(user->password, password) == 0;
}
