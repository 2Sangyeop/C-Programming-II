/*
프로그램명: 수업 중 실습 10장. 2
학번: 202111022
이름: 이상엽
날짜:25. 09. 30
*/
#include <stdio.h>

#include "contact.h" // contact.h 헤더파일 사용

Contact kim = { 0 };

int main() {
	Contact lee = { "LEE", "010-1234-5678", 1 };
	Contact lee2 = { 0 };
	lee2 = lee;
	//lee2 = { "LEE2", "010-9876-5432", 2 }; 오류!
	lee2.ringtone = 2;

	return 0;
}
