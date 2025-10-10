/*****************************************************************************************************
   * 파일명: assign_18.c
   * 난이도: ★★★

   * 내용: 음원 사이트의 플레이리스트 기능을 구현하려고 한다. 이미 등록된 SONG 구조체 배열이 있을 때,
           전체 곡 목록을 보여주고 사용자로부터 플레이리스트에 추가할 노래를 번호로 선택하게 한다.
           플레이리스트에 노래를 추가할 때마다 플레이리스트의 곡 목록과 전체 재생 시간이 얼마인지를 출력한다.
           플레이리스트에는 최대 5곡만 등록할 수 있다.

   * 작성자: 이상엽

   * 날짜: 2025.10.01
   *
   * 버전: v1.0

 *******************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_SONGS 8
#define MAX_PLAYLIST 5
#define MAX_TITLE 50
#define MAX_ARTIST 50
#define MAX_GENRE 20

struct SONG
{
    char title[MAX_TITLE];
    char artist[MAX_ARTIST];
    char genre[MAX_GENRE];
    int time;
};

void print_songlist(struct SONG songs[], int count);
void print_playlist(struct SONG* playlist[], int count);
int assign_18(void);


int main()
{
    assign_18();
    return 0;
}

// 플레이리스트 기능 구현 함수
int assign_18()
{
    struct SONG songs[MAX_SONGS] =
    {
        {"thank u, next", "Ariana Grande", "pop", 208},
        {"Attention", "Charlie Puth", "pop", 211},
        {"별 보러 가자", "박보검", "ballad", 316},
        {"How Long", "Charlie Puth", "pop", 198},
        {"I'm Fine", "방탄소년단", "hip-hop", 209},
        {"봄날", "방탄소년단", "hip-hop", 274},
        {"Awake", "방탄소년단", "ballad", 226},
        {"아낙네", "MINO", "hip-hop", 241}
    };

    struct SONG* playlist[MAX_PLAYLIST];
    int playlist_count = 0;
    int total_time = 0;
    int choice;

    print_songlist(songs, MAX_SONGS);

    while (playlist_count < MAX_PLAYLIST)
    {

        printf("플레이리스트에 추가할 곡 번호? ");
        scanf("%d", &choice);

        if (choice < 1 || choice > MAX_SONGS)
        {
            printf("잘못된 곡 번호입니다.\n");
            continue;
        }

        playlist[playlist_count] = &songs[choice - 1];
        total_time += songs[choice - 1].time;
        playlist_count++;

        printf("≪ 플레이리스트 ≫\n");
        print_playlist(playlist, playlist_count);
        printf("총 재생시간 : %d초\n\n", total_time);
    }

    return 0;
}

// 전체 곡 목록 출력함수
void print_songlist(struct SONG songs[], int count)
{
    printf("\n제목\t\t\t아티스트\t장르\t재생시간\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d: %-20s %-15s %-10s %d초\n",
            i + 1, songs[i].title, songs[i].artist, songs[i].genre, songs[i].time);
    }
}

// 플레이리스트 출력함수
void print_playlist(struct SONG* playlist[], int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("%-20s %-15s %-10s %d초\n",
            playlist[i]->title, playlist[i]->artist, playlist[i]->genre, playlist[i]->time);
    }
}