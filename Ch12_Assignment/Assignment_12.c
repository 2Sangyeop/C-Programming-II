/*****************************************************************************************************
   * 파일명: assign_12.c
   
   * 난이도: ★★★

   * 내용: 11번 프로그램에 연락처 검색이 실패하는 경우 새로운 연락처를 추가하는 기능을 구현하시오. 또한, 프로그램이
           종료될 때 CONTACT 구조체의 내용을 텍스트 파일로 저장하도록 처리하시오.

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
struct CONTACT* add_contact(struct CONTACT* list, int* count, const char* name);
void save_contacts(const char* filename, const struct CONTACT* list, int count);
int assign_12(void);

int main()
{
    assign_12();
    return 0;
}

int assign_12()
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
        {
            char answer;
            printf("연락처를 찾을 수 없습니다. 연락처를 등록하시겠습니까?(y/n)? ");
            scanf(" %c", &answer);

            if (answer == 'y' || answer == 'Y')
            {
                list = add_contact(list, &count, name);
            }
        }
        else
        {
            printf("%s의 전화번호 %s로 전화를 겁니다....\n", list[index].name, list[index].phone);
        }
    }

    save_contacts(filename, list, count);
    printf("%s로 %d개의 연락처를 저장했습니다.\n", filename, count);

    free(list);
    return 0;
}

// 파일에서 연락처 읽기
struct CONTACT* load_contacts(const char* filename, int* count)
{
    FILE* fp = fopen(filename, "r");
    if (fp == NULL)
        return NULL;

    int c = 0;
    char temp_name[MAX_SIZE], temp_phone[MAX_SIZE];

    while (fscanf(fp, "%s %s", temp_name, temp_phone) == 2)
        c++;

    rewind(fp);

    struct CONTACT* list = (struct CONTACT*)malloc(sizeof(struct CONTACT) * c);
    if (list == NULL)
    {
        fclose(fp);
        return NULL;
    }

    for (int i = 0; i < c; i++)
        fscanf(fp, "%s %s", list[i].name, list[i].phone);

    fclose(fp);
    *count = c;
    return list;
}

// 이름으로 연락처 검색
int find_contact(const struct CONTACT* list, int count, const char* name)
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(list[i].name, name) == 0)
            return i;
    }
    return -1;
}

// 새 연락처 추가
struct CONTACT* add_contact(struct CONTACT* list, int* count, const char* name)
{
    char phone[MAX_SIZE];

    printf("전화번호? ");
    scanf("%s", phone);

    struct CONTACT* new_list = (struct CONTACT*)realloc(list, sizeof(struct CONTACT) * (*count + 1));
    if (new_list == NULL)
    {
        printf("메모리 할당 실패\n");
        return list;
    }

    strcpy(new_list[*count].name, name);
    strcpy(new_list[*count].phone, phone);
    (*count)++;

    return new_list;
}

// 연락처 파일로 저장
void save_contacts(const char* filename, const struct CONTACT* list, int count)
{
    FILE* fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("파일 저장 실패.\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(fp, "%s %s\n", list[i].name, list[i].phone);
    }

    fclose(fp);
}
