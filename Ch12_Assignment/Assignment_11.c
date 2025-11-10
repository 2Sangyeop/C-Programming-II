/*****************************************************************************************************
   * 파일명: assign_11.c
   
   * 난이도: ★★

   * 내용: CONTACT 구조체를 이용한 연락처 관리 프로그램에 텍스트 파일에서 연락처를 로딩하는 기능을 추가한다. 
           텍스트 파일에 정해진 형식으로 연락처를 저장하고 이 파일을 읽어서 CONTACT 구조체 배열을 생성하도록 
           프로그램을 작성하시오. CONTACT 구조체 배열은 동적메모리에 생성한다.

   * 작성자: 이상엽

   * 날짜: 2025.11.10

   * 버전: v1.0

 *******************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 20

struct CONTACT {
    char name[MAX_SIZE];
    char phone[MAX_SIZE];
};

struct CONTACT* load_contacts(const char* filename, int* count);
int find_contact(const struct CONTACT* list, int count, const char* name);
int assign_11(void);

int main()
{
    assign_11();
    return 0;
}

int assign_11()
{
    char filename[50];
    struct CONTACT* list = NULL;
    int count = 0;
    char name[MAX_SIZE];
    int index;

    printf("연락처 파일명? ");
    scanf("%s", filename);

    list = load_contacts(filename, &count);
    if (list == NULL)
    {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    printf("%d개의 연락처를 로딩했습니다.\n", count);

    while (1)
    {
        printf("이름(. 입력 시 종료)? ");
        scanf("%s", name);

        if (strcmp(name, ".") == 0)
            break;

        index = find_contact(list, count, name);
        if (index == -1)
            printf("연락처를 찾을 수 없습니다.\n");
        else
            printf("%s의 전화번호 %s로 전화를 겁니다....\n", list[index].name, list[index].phone);
    }

    free(list);
    return 0;
}

// 파일에서 연락처 로딩
struct CONTACT* load_contacts(const char* filename, int* count)
{
    FILE* fp = fopen(filename, "r");
    if (fp == NULL)
        return NULL;

    // 연락처 개수 계산
    int c = 0;
    char temp_name[MAX_SIZE], temp_phone[MAX_SIZE];
    while (fscanf(fp, "%s %s", temp_name, temp_phone) == 2)
        c++;

    rewind(fp); // 파일 포인터 처음으로 이동

    // 동적 메모리 할당
    struct CONTACT* list = (struct CONTACT*)malloc(sizeof(struct CONTACT) * c);
    if (list == NULL)
    {
        fclose(fp);
        return NULL;
    }

    // 실제 데이터 읽기
    for (int i = 0; i < c; i++)
        fscanf(fp, "%s %s", list[i].name, list[i].phone);

    fclose(fp);
    *count = c;
    return list;
}

// 이름으로 연락처 찾기
int find_contact(const struct CONTACT* list, int count, const char* name)
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(list[i].name, name) == 0)
            return i;
    }
    return -1;
}
