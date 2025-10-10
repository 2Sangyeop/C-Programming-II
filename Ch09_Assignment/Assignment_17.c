/*****************************************************************************************************
   * 파일명: assign_17.c
   * 난이도: ★★★

   * 내용: 입력받은 노래 제목을 최대 20개 저장하고 관리하는 프로그램을 작성하시오. 노래제목의 길이는 최대 40글자
           라고 가정한다. 간단한 메뉴로 노래 제목을 추가하는 기능, 노래 제목을 수정하는 기능, 노래 목록을 출력하는 
           기능을 처리한다.

   * 작성자: 이상엽

   * 날짜: 2025.10.

   * 버전: v1.0

 *******************************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_SONGS 20  // 최대 노래 개수
#define TITLE_LEN 40  // 노래 제목 최대 길이

char song_list[MAX_SONGS][TITLE_LEN + 1]; // +1은 null 문자 계산
int song_count = 0; // 등록된 노래 개수

void add_song(const char* title);
void display_list();
void edit_song(const char* old_title, const char* new_title);
int assign_17(void);

int main()
{
    assign_17();
    return 0;
}

// 1. 노래 추가 기능
void add_song(const char* title)
{

    // 노래 제목 복사
    strncpy(song_list[song_count], title, TITLE_LEN);
    song_list[song_count][TITLE_LEN] = '\0'; // 널 문자 추가

    song_count++;
}

// 2. 노래 목록 출력 기능
void display_list()
{
    printf("<<노래 목록>>\n");
    for (int i = 0; i < song_count; i++)
    {
        printf("%s\n", song_list[i]);
    }
}

// 3. 노래 수정 기능
void edit_song(const char* old_title, const char* new_title)
{
    int i;
    int found = 0;

    for (i = 0; i < song_count; i++)
    {
        // 수정할 노래 제목 찾기
        if (strcmp(song_list[i], old_title) == 0)
        {
            // 새 제목으로 수정
            strncpy(song_list[i], new_title, TITLE_LEN);
            song_list[i][TITLE_LEN] = '\0';
            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf(">> 제목을 찾을 수 없습니다.\n");
    }
}

int assign_17(void)
{
    int choice;
    char basic_title[TITLE_LEN + 1];
    char new_title_input[TITLE_LEN + 1];

    while (1)
    {
        // 메뉴 출력 및 선택
        printf("[ 0.종료 1.추가 2.수정 3.목록] 선택? ");

        if (scanf("%d", &choice) != 1) 
        {
            while (getchar() != '\n');
            continue;
        }

        while (getchar() != '\n');

        switch (choice)
        {
        case 0: // 종료
            return 0; 

        case 1: // 추가
            printf("노래 제목? ");
            if (fgets(basic_title, sizeof(basic_title), stdin) != NULL) 
            {
                basic_title[strcspn(basic_title, "\n")] = '\0';
                add_song(basic_title);
            }
            break;

        case 2: // 수정
            printf("찾을 노래 제목? ");
            if (fgets(basic_title, sizeof(basic_title), stdin) != NULL) {
                basic_title[strcspn(basic_title, "\n")] = '\0'; // \n 제거

                printf("수정할 제목? ");
                if (fgets(new_title_input, sizeof(new_title_input), stdin) != NULL) {
                    new_title_input[strcspn(new_title_input, "\n")] = '\0'; // \n 제거
                    edit_song(basic_title, new_title_input);
                }
            }
            break;

        case 3: // 목록
            display_list();
            break;
        }
    }
}