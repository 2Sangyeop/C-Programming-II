/*****************************************************************************************************
   * 파일명: assign_16.c
   * 난이도: ★★★

   * 내용: 인터넷 사이트에 로그인하려는 사용자로부터 아이디와 패스워드를 입력받아 로그인 과정을 처리하려고 한다. 
          사용자 5명의 아이디와 패스워드가 이미 등록되어 있을 때, 입력받은 아이디에 해당하는 패스워드와 사용자가 
          입력한 패스워드가 일치하면 로그인을 허용하는 프로그램을 작성하시오. 사용자가 입력한 아이디가 존재하지 
          않거나, 아이디에 해당하는 패스워드가 일치하지 않으면 에러 메시지 출력 후 아이디와 패스워드를 다시 입력받게
          한다. 3번의 재시도 후에도 올바른 아이디와 패스워드를 입력하지 못하면 로그인 실패 에러 메시지를 출력한다.
          아이디 문자열 배열과 패스워드 문자열 배열은 마음대로 정해서 사용한다.

   * 작성자: 이상엽

   * 날짜: 2025.10.

   * 버전: v1.0

 *******************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define USER 5
#define ID_LEN 20
#define PW_LEN 20

int check_login(const char* id, const char* pw);
int assign_16(void);

// 등록된 사용자
// ID
const char* user_ids[USER] = { "v", "jimin", "jeongguk", "jhope", "suga" };
// PW
const char* user_pws[USER] = { "dna!23", "@BestOfMe@", "fire!", "dope@", "idol!!" };


int main()
{
    assign_16();
    return 0;
}

// ID/PW 일치 여부 확인 함수
// 리턴값: 0(ID 없음), 1(PW 불일치), 2(로그인 성공)
int check_login(const char* id, const char* pw)
{
    int i;

    // 등록된 ID 확인
    for (i = 0; i < USER; i++)
    {
        // ID 일치 확인
        if (strcmp(id, user_ids[i]) == 0)
        {
            // ID가 일치하면 PW도 확인
            if (strcmp(pw, user_pws[i]) == 0)
            {
                return 2; // 로그인 성공
            }
            else
            {
                return 1; // ID는 있지만 PW 불일치
            }
        }
    }

    return 0; //  ID부터 없음
}

int assign_16(void)
{
    char input_id[ID_LEN];
    char input_pw[PW_LEN];
    int attempt;
    int login_status; // 로그인 사ㅇ태

    for (attempt = 1; attempt <= 3; attempt++)
    {
        // ID 입력
        printf("ID: ");
        if (fgets(input_id, sizeof(input_id), stdin) == NULL) return 1;
        input_id[strcspn(input_id, "\n")] = '\0'; // \n제거

        // PW 입력
        printf("PW: ");
        if (fgets(input_pw, sizeof(input_pw), stdin) == NULL) return 1;
        input_pw[strcspn(input_pw, "\n")] = '\0'; 

        // 로그인 상태 확인
        login_status = check_login(input_id, input_pw);

        if (login_status == 2)
        {
            printf("\n로그인 성공!\n");
            return 0; // 성공 시 프로그램 종료
        }
        else
        {
            // 로그인 상황에 따른 메시지 출력
            if (login_status == 0)
            {
                printf("해당 id가 없습니다.\n\n");
            }
            else if (login_status == 1)
            {
                printf("패스워드가 틀렸습니다.\n\n");
            }
        }
    }

    // 3회 재시도 후에도 실패 시
    printf("로그인 실패 에러.\n");
    return 0;
}