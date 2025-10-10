/*
프로그램명: 수업 중 실습 9장
학번: 202111022
이름: 이상엽
문제: 키보드로부터 다음 레코드를 한 줄 입력받아 필들를
   구분하여 구조체 배열에 지정한 후 출력하는 프로그램을 작성하시오.
   레코드 형식: 이름, 학번, 학과, 학년(정수)
   입력 종료 조건: "exit" 입력
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS 100
#define BUFFER_SIZE 128

struct Student {
    char name[24];
    char id[16];
    char major[32];
    int year;
};
typedef struct Student Student;

int inputStudents(Student students[], int max);
void printStudents(Student students[], int count);

int main() {
    Student students[MAX_STUDENTS];
    int studentCount = inputStudents(students, MAX_STUDENTS);
    printStudents(students, studentCount);
    return 0;
}

// 학생 정보 입력 함수 (입력받은 학생 수 반환)
int inputStudents(Student students[], int max) {
    int count = 0;
    char input[BUFFER_SIZE];

    printf("학생 정보를 입력하세요 (형식: 이름,학번,학과,학년). 종료하려면 'exit' 입력:\n");

    while (count < max) {
        printf("입력 %d > ", count + 1);
        if (fgets(input, sizeof(input), stdin) == NULL) break;

        // 개행 문자 제거
        input[strcspn(input, "\n")] = 0;

        // 종료 조건
        if (strcmp(input, "exit") == 0) {
            break;
        }

        char* token = strtok(input, ",");
        if (token == NULL) continue;
        strncpy(students[count].name, token, sizeof(students[count].name) - 1);
        students[count].name[sizeof(students[count].name) - 1] = '\0';

        token = strtok(NULL, ",");
        if (token == NULL) continue;
        strncpy(students[count].id, token, sizeof(students[count].id) - 1);
        students[count].id[sizeof(students[count].id) - 1] = '\0';

        token = strtok(NULL, ",");
        if (token == NULL) continue;
        strncpy(students[count].major, token, sizeof(students[count].major) - 1);
        students[count].major[sizeof(students[count].major) - 1] = '\0';

        token = strtok(NULL, ",");
        if (token == NULL) continue;
        students[count].year = atoi(token);

        count++;
    }
    return count;
}

// 학생 정보 출력 함수
void printStudents(Student students[], int count) {
    printf("\n입력된 학생 정보:\n");
    for (int i = 0; i < count; i++) {
        printf("학생 %d: 이름: %s, 학번: %s, 학과: %s, 학년: %d\n",
            i + 1, students[i].name, students[i].id,
            students[i].major, students[i].year);
    }
}